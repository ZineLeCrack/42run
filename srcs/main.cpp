#include "Includes.hpp"

static Game			*game;
static glm::mat4	View = glm::lookAt(glm::vec3(0.0, 0.2, -0.5), glm::vec3(0.0, 0.5, 5.0), glm::vec3(0.0, -1.0, 0.0));
static glm::mat4	Projection = glm::perspective(glm::radians(45.0f), 2560.0f / 1600.0f, 0.1f, 100.0f);
static double		v = 0.0625;
static bool			is_dying = false;
static bool			is_turning = false;
static double		to_turn = 0.0;
static bool			keys[256];
static bool			specials_keys[256];

GLuint loadPNGTexture(const char* filename) {
	FILE *fp = fopen(filename, "rb");
	if (!fp) {
		std::cerr << RED "Error: cannot read file." << filename << RESET << std::endl;
		return 0;
	}

	// Vérification signature PNG
	png_byte header[8];
	fread(header, 1, 8, fp);
	if (png_sig_cmp(header, 0, 8)) {
		std::cerr << RED "Error: " << filename << " is not a PNG image." RESET << std::endl;
		fclose(fp);
		return 0;
	}

	// Structures libpng
	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) { fclose(fp); return 0; }

	png_infop info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr) { png_destroy_read_struct(&png_ptr, NULL, NULL); fclose(fp); return 0; }

	if (setjmp(png_jmpbuf(png_ptr))) {
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(fp);
		return 0;
	}

	png_init_io(png_ptr, fp);
	png_set_sig_bytes(png_ptr, 8);

	// Lecture info PNG
	png_read_info(png_ptr, info_ptr);

	int width = png_get_image_width(png_ptr, info_ptr);
	int height = png_get_image_height(png_ptr, info_ptr);
	png_byte color = png_get_color_type(png_ptr, info_ptr);
	png_byte depth = png_get_bit_depth(png_ptr, info_ptr);

	// Conversion en RGBA8 si nécessaire
	if (depth == 16) png_set_strip_16(png_ptr);
	if (color == PNG_COLOR_TYPE_PALETTE) png_set_palette_to_rgb(png_ptr);
	if (color == PNG_COLOR_TYPE_GRAY && depth < 8) png_set_expand_gray_1_2_4_to_8(png_ptr);
	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)) png_set_tRNS_to_alpha(png_ptr);

	if (color == PNG_COLOR_TYPE_RGB || color == PNG_COLOR_TYPE_GRAY || color == PNG_COLOR_TYPE_PALETTE)
		png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);

	if (color == PNG_COLOR_TYPE_GRAY || color == PNG_COLOR_TYPE_GRAY_ALPHA)
		png_set_gray_to_rgb(png_ptr);

	png_read_update_info(png_ptr, info_ptr);

	// Allocation buffer
	std::vector<png_byte> imageData(width * height * 4);
	std::vector<png_bytep> row_pointers(height);

	for (int y = 0; y < height; y++) {
		row_pointers[y] = imageData.data() + y * width * 4;
	}

	// Lecture pixels
	png_read_image(png_ptr, row_pointers.data());
	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	fclose(fp);

	// Création texture OpenGL
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
				 GL_RGBA, GL_UNSIGNED_BYTE, imageData.data());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return textureID;
}

static void	loadTextures()
{
	vector<GLuint>	&textureIDs = game->get_textureIDs();

	textureIDs.push_back(loadPNGTexture("imgs/floor.png"));
	textureIDs.push_back(loadPNGTexture("imgs/celling.png"));
	textureIDs.push_back(loadPNGTexture("imgs/paint1.png"));
	textureIDs.push_back(loadPNGTexture("imgs/paint2.png"));
	textureIDs.push_back(loadPNGTexture("imgs/paint3.png"));
	textureIDs.push_back(loadPNGTexture("imgs/paint4.png"));
	textureIDs.push_back(loadPNGTexture("imgs/paint5.png"));
	textureIDs.push_back(loadPNGTexture("imgs/42_1.png"));
	textureIDs.push_back(loadPNGTexture("imgs/42_2.png"));
	textureIDs.push_back(loadPNGTexture("imgs/right_wall_corridor1.png"));
	textureIDs.push_back(loadPNGTexture("imgs/right_wall_corridor2.png"));
	textureIDs.push_back(loadPNGTexture("imgs/right_wall_corridor3.png"));
	textureIDs.push_back(loadPNGTexture("imgs/right_wall_corridor4.png"));
	textureIDs.push_back(loadPNGTexture("imgs/right_wall_corridor5.png"));
	textureIDs.push_back(loadPNGTexture("imgs/right_wall_corridor6.png"));
	textureIDs.push_back(loadPNGTexture("imgs/npc1.png"));
	textureIDs.push_back(loadPNGTexture("imgs/npc2.png"));
	textureIDs.push_back(loadPNGTexture("imgs/val.png"));
	textureIDs.push_back(loadPNGTexture("imgs/boom.png"));
	textureIDs.push_back(loadPNGTexture("imgs/0.png"));
	textureIDs.push_back(loadPNGTexture("imgs/1.png"));
	textureIDs.push_back(loadPNGTexture("imgs/2.png"));
	textureIDs.push_back(loadPNGTexture("imgs/3.png"));
	textureIDs.push_back(loadPNGTexture("imgs/4.png"));
	textureIDs.push_back(loadPNGTexture("imgs/5.png"));
	textureIDs.push_back(loadPNGTexture("imgs/6.png"));
	textureIDs.push_back(loadPNGTexture("imgs/7.png"));
	textureIDs.push_back(loadPNGTexture("imgs/8.png"));
	textureIDs.push_back(loadPNGTexture("imgs/9.png"));
	textureIDs.push_back(loadPNGTexture("imgs/lava.png"));
	textureIDs.push_back(loadPNGTexture("imgs/metal.png"));
	textureIDs.push_back(loadPNGTexture("imgs/galaxy.png"));
}

static void	loadObjects() {
	game->get_objects().push_back(new Object("objects/table.obj"));
}

static void	put_score(unsigned long long n, unsigned int i) {
	if (n < 10) {
		double	val = (double)i;
		glBindTexture(GL_TEXTURE_2D, game->get_textureIDs()[NB_0 + n]);

		glBegin(GL_QUADS);

		glTexCoord2d(0.0, 0.0); applyMVP(game->get_MVP(), glm::vec3(-0.95 + (val * 0.05), 0.1, 0.95));
		glTexCoord2d(0.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(-0.95 + (val * 0.05), 0.15, 0.95));
		glTexCoord2d(1.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(-0.9 + (val * 0.05), 0.15, 0.95));
		glTexCoord2d(1.0, 0.0); applyMVP(game->get_MVP(), glm::vec3(-0.9 + (val * 0.05), 0.1, 0.95));

		glEnd();
	} else {
		put_score(n % 10, i);
		put_score(n / 10, i - 1);
	}
}

static void	end() {
	sleep(1);
	cout << BLUE << "Game Over !\nYou Earned " << (int)(game->get_score() * 0.1) << " points !" << endl;
	glutLeaveMainLoop();
}

static void	display() {
	long long	fps = get_timestamp() + 16666;
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (game->get_map()[2]->is_turn() > 1 && !is_turning && to_turn > 2.0) {
		to_turn = 0.0;
		is_turning = true;
	}

	if (is_turning) {
		to_turn += 0.01;
		if (to_turn > 1.5) {
			is_turning = false;
			vector<Map*>::iterator tmp = ++++(game->get_map().begin());
			delete (*tmp);
			game->get_map().erase(tmp);
			game->gen_next();
		}
	}

	corridor(game, is_turning, game->get_map()[2]->is_turn() == 2 ? -to_turn : to_turn);
	unsigned long long	score = game->get_score() * 0.1;
	put_score(score, to_string(score).size());

	if (is_turning) {
		glutSwapBuffers();
		glutPostRedisplay();
		return ;
	}

	double &d = game->get_distance();

	if (game->get_is_jumping()) {
		if (game->get_height() < -0.4)
			game->get_is_jumping() = false;
		else
			game->get_height() -= (game->get_height() + 0.7) * 0.05;
	}
	else if (game->get_height() < 0.0) {
		game->get_height() += (game->get_height() + 0.55) * 0.05;
	}

	if (keys[KEY_ESC]) {
		end();
	}

	if (specials_keys[GLUT_KEY_LEFT] && game->get_pos() > -0.8) {
		game->get_pos() -= 0.01;
	}

	if (specials_keys[GLUT_KEY_RIGHT] && game->get_pos() < 0.8) {
		game->get_pos() += 0.01;
	}

	double	pos = game->get_pos();

	if ((game->get_map()[2]->is_turn() && (d - (int)d) > 0.3) || (game->get_map()[1]->is_turn() && (d - (int)d) < 0.7)) {
		if (pos < -0.5 || pos > 0.5) {
			double h = game->get_height();

			glBindTexture(GL_TEXTURE_2D, game->get_textureIDs()[BOOM]);

			glBegin(GL_QUADS);

			glTexCoord2d(0.0, 0.0); applyMVP(game->get_MVP(), glm::vec3(-0.4 + pos, 0.3 + h, 1.3));
			glTexCoord2d(0.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(-0.4 + pos, 0.9 + h, 1.3));
			glTexCoord2d(1.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(0.4 + pos, 0.9 + h, 1.3));
			glTexCoord2d(1.0, 0.0); applyMVP(game->get_MVP(), glm::vec3(0.4 + pos, 0.3 + h, 1.3));

			glEnd();

			glutSwapBuffers();
			glutPostRedisplay();
			end();
		}
	}

	int *obs = game->get_map()[1]->get_obs();
	if (obs && (d - (int)d) < 0.3) {
		for (int i = 0; i < 3; i++) {
			if (!obs[i]) continue;
			double	col = (i - 1) * 1.0;
			if (game->get_height() > -0.1 && (pos < col + 0.35 && pos > col - 0.35)) {
				double h = game->get_height();

				glBindTexture(GL_TEXTURE_2D, game->get_textureIDs()[BOOM]);

				glBegin(GL_QUADS);

				glTexCoord2d(0.0, 0.0); applyMVP(game->get_MVP(), glm::vec3(-0.4 + pos, 0.3 + h, 1.3));
				glTexCoord2d(0.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(-0.4 + pos, 0.9 + h, 1.3));
				glTexCoord2d(1.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(0.4 + pos, 0.9 + h, 1.3));
				glTexCoord2d(1.0, 0.0); applyMVP(game->get_MVP(), glm::vec3(0.4 + pos, 0.3 + h, 1.3));

				glEnd();

				glutSwapBuffers();
				glutPostRedisplay();
				end();
			}
		}
	}

	if (((game->get_map()[2]->is_hole() && d - (int)d > 0.5) || (game->get_map()[1]->is_hole() && d - (int)d < 0.5)) && game->get_height() >= 0.0) is_dying = true;

	if (is_dying) {
		game->get_height() += 0.01;
		if (game->get_height() > 1.0) {
			end();
		}
		glutSwapBuffers();
		glutPostRedisplay();
		return ;
	}

	if (keys[32] && game->get_height() >= 0.0) {
		game->get_is_jumping() = true;
	}

	d += v;
	if (v < 0.15) v += 0.000012;
	if (to_turn <= 2.0) to_turn += v;

	if (d >= 1.0) {
		d = 0;
		delete *(game->get_map().begin());
		game->get_map().erase(game->get_map().begin());
		if (game->get_map().size() <= 30) game->gen_next();
	}

	game->get_score()++;

	wait(fps);
	glutSwapBuffers();
	glutPostRedisplay();
}

static void special_keypress(int key, int x, int y) {
	(void)x;
	(void)y;

	specials_keys[key] = true;
}

static void special_keyup(int key, int x, int y) {
	(void)x;
	(void)y;

	specials_keys[key] = false;
}

static void keypress(unsigned char key, int x, int y) {
	(void)x;
	(void)y;

	keys[key] = true;
}

static void keyup(unsigned char key, int x, int y) {
	(void)x;
	(void)y;

	keys[key] = false;
}

static void	set_logs() {
	int	score = (int)(game->get_score() * 0.1);

	string	nickname;
	cout << YELLOW << "Enter your nickname: " RESET << endl;
	getline(cin, nickname);

	stringstream	lasts_scores_buff;
	ifstream		lasts_scores_infile("logs/lasts_scores.logs");

	lasts_scores_buff << lasts_scores_infile.rdbuf();

	ofstream		lasts_scores_outfile("logs/lasts_scores.logs");

	lasts_scores_outfile << nickname << ": " << score << " pts\n" << lasts_scores_buff.str();

	ifstream		bests_scores_infile("logs/bests_scores.logs");
	string			bests_scores_buff;
	string			all_bests_scores_buff;
	int				best_score, i = 0;

	while (i < 10) {
		getline(bests_scores_infile, bests_scores_buff);
		best_score = atoi((bests_scores_buff.substr(bests_scores_buff.find_last_of(':') + 1)).c_str());
		if (score > best_score) {
			all_bests_scores_buff.append(nickname + ": " + to_string(score) + " pts\n");
			if (bests_scores_buff.size() > 0) all_bests_scores_buff.append(bests_scores_buff + '\n');
			for ( ; i < 8; i++) {
				getline(bests_scores_infile, bests_scores_buff);
				if (bests_scores_buff.size() == 0) break ;
				all_bests_scores_buff.append(bests_scores_buff + '\n');
			}
			
			ofstream	bests_scores_outfile("logs/bests_scores.logs");
			
			bests_scores_outfile << all_bests_scores_buff;
			bests_scores_outfile.close();
			break ;
		}
		if (bests_scores_buff.size() > 0) all_bests_scores_buff.append(bests_scores_buff + '\n');
		i++;
	}

	lasts_scores_infile.close();
	lasts_scores_outfile.close();
	bests_scores_infile.close();
}

int	main(int ac, char **av) {
	if (ac > 2) {
		cerr << RED "usage: ./42run (logs)" RESET << endl;
	} else if (ac == 2) {
		if (!string("logs").compare(av[1])) {
			ifstream	bests_scores_infile("logs/bests_scores.logs");
			string	scores_buff;

			cout << YELLOW "-----===== BESTS SCORES =====-----" MAGENTA << endl;

			for (int i = 0; i < 10 && getline(bests_scores_infile, scores_buff); i++) {
				cout << i + 1 << ". " << scores_buff << endl;
			}

			ifstream	lasts_scores_infile("logs/lasts_scores.logs");
			
			cout << RESET << endl;
			cout << YELLOW "-----===== LASTS SCORES =====-----" BLUE << endl;

			for (int i = 0; i < 10 && getline(lasts_scores_infile, scores_buff); i++) {
				cout << i + 1 << ". " << scores_buff << endl;
			}
			cout << RESET;
		} else {
			cerr << RED "usage: ./42run (logs)" RESET << endl;
		}
	} else {
		bzero(keys, 1024);
		bzero(specials_keys, 1024);
	
		game = new Game(Projection * View);
		game->gen_start();
	
		glutInit(&ac, av);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(2560, 1600);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("42run");
		glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
		loadTextures();
		loadObjects();
	
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glutKeyboardFunc(keypress);
		glutSpecialFunc(special_keypress);
		glutKeyboardUpFunc(keyup);
		glutSpecialUpFunc(special_keyup);
		glutDisplayFunc(display);
		glutMainLoop();
	
		set_logs();
		delete game;
	}
}
