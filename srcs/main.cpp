#include "Includes.hpp"

static Game *game;
static bool	is_dying = false;
static int	keys[256];
static int	specials_keys[256];

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

    int width      = png_get_image_width(png_ptr, info_ptr);
    int height     = png_get_image_height(png_ptr, info_ptr);
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

static void	display() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	corridor(game);
	unsigned long long	score = game->get_score() * 0.1;
	put_score(score, to_string(score).size());

	double &d = game->get_distance();

	if (game->get_is_jumping()) {
		if (game->get_height() < -0.5)
			game->get_is_jumping() = false;
		else
			game->get_height() -= (game->get_height() + 0.7) * 0.05;
	}
	else if (game->get_height() < 0.0) {
		game->get_height() += (game->get_height() + 0.55) * 0.05;
	}

	if (specials_keys[GLUT_KEY_LEFT] && game->get_pos() > -0.8) {
		game->get_pos() -= 0.01;
	}

	if (specials_keys[GLUT_KEY_RIGHT] && game->get_pos() < 0.8) {
		game->get_pos() += 0.01;
	}

	double	pos = game->get_pos();
	int *obs = game->get_map()[0]->get_obs();
	if (obs && (d - (int)d) < 0.3) {
		int i;
		for (i = 0; i < 3; i++) {
			if (obs[i]) break;
		}
		if (i < 3) {
			double	col = (i - 1) * 1.0;
			if (game->get_height() > -0.1 && (pos < col + 0.35 && pos > col - 0.35)) {
				glBindTexture(GL_TEXTURE_2D, game->get_textureIDs()[BOOM]);

				glBegin(GL_QUADS);

				glTexCoord2d(0.0, 0.0); applyMVP(game->get_MVP(), glm::vec3(-0.4 + pos, 0.3, 1.3));
				glTexCoord2d(0.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(-0.4 + pos, 0.9, 1.3));
				glTexCoord2d(1.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(0.4 + pos, 0.9, 1.3));
				glTexCoord2d(1.0, 0.0); applyMVP(game->get_MVP(), glm::vec3(0.4 + pos, 0.3, 1.3));

				glEnd();

				glutSwapBuffers();
				glutPostRedisplay();

				sleep(1);
				exit(0);
			}
		}
	}

	if (((game->get_map()[2]->is_lava() && d - (int)d > 0.5) || (game->get_map()[1]->is_lava() && d - (int)d < 0.5)) && game->get_height() >= 0.0) is_dying = true;

	if (is_dying) {
		game->get_height() += 0.01;
		if (game->get_height() > 1.0) exit(0);
		glutSwapBuffers();
		glutPostRedisplay();
		return ;
	}

	if (keys[' '] && game->get_height() >= 0.0) {
		game->get_is_jumping() = true;
	}

	d += 0.0625;

	if (d == 1.0) {
		d = 0;
		game->get_map().erase(game->get_map().begin());
		game->gen_next();
	}

	game->get_score()++;

	glutSwapBuffers();
	glutPostRedisplay();
}

static void special_keypress(int key, int x, int y) {
	(void)x;
	(void)y;

	specials_keys[key] = 1;
}

static void special_keyup(int key, int x, int y) {
	(void)x;
	(void)y;

	specials_keys[key] = 0;
}

static void keypress(unsigned char key, int x, int y) {
	(void)x;
	(void)y;

	keys[key] = 1;
}

static void keyup(unsigned char key, int x, int y) {
	(void)x;
	(void)y;

	keys[key] = 0;
}

int	main(int ac, char **av) {
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 2560.0f / 1600.0f, 0.1f, 100.0f);
	glm::mat4 View = glm::lookAt(glm::vec3(0.0, 0.2, -0.5), glm::vec3(0.0, 0.5, 5.0), glm::vec3(0.0, -1.0, 0.0));

	bzero(keys, 1024);
	bzero(specials_keys, 1024);

	game = new Game(Projection * View);
	game->gen_start();

	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(2560, 1600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("42run");
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	loadTextures();

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glutKeyboardFunc(keypress);
	glutSpecialFunc(special_keypress);
	glutKeyboardUpFunc(keyup);
	glutSpecialUpFunc(special_keyup);
	glutDisplayFunc(display);
	glutMainLoop();

	delete game;
}
