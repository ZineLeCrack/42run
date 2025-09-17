#include "Includes.hpp"

static Game *game;

static void	loadTextures()
{
	vector<GLuint>	&textureIDs = game->get_textureIDs();

	textureIDs.push_back(SOIL_load_OGL_texture("imgs/floor.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/celling.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/paint1.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/paint2.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/paint3.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/paint4.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/paint5.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/42_1.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/42_2.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/right_wall_corridor1.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/right_wall_corridor2.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/right_wall_corridor3.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/right_wall_corridor4.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/right_wall_corridor5.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/right_wall_corridor6.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/npc1.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	textureIDs.push_back(SOIL_load_OGL_texture("imgs/npc2.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));

	for (vector<GLuint>::iterator i = textureIDs.begin(); i != textureIDs.end(); i++) {
		if (!(*i)) {
			cerr << RED "SOIL Error at texture " << (*i) << ": " << SOIL_last_result() << "." << endl;
		}
	}
}

static void drawText(const char *text, float x, float y, float scale) {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 2560, 0, 1600);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glTranslatef(x, y, 0);
	glScalef(scale, scale, scale);

	glColor3f(0.0, 0.0, 0.0);

	for (int i = 0; text[i] != '\0'; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

static void	display() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 0.2, -0.5, 0.0, 0.5, 5.0, 0.0, -1.0, 0.0);

	corridor(game);

	drawText(to_string((int)game->get_distance()).c_str(), 40, 1500, 0.5f);

	game->get_distance() += 0.01;

	glutSwapBuffers();
	glutPostRedisplay();
}

static void special_keypress(int key, int x, int y) {
	(void)x;
	(void)y;

	if (key == GLUT_KEY_LEFT) {
		game->get_pos() -= game->get_pos() > -0.5 ? 0.6 : 0;
	}

	else if (key == GLUT_KEY_RIGHT) {
		game->get_pos() += game->get_pos() < 0.5 ? 0.6 : 0;
	}
}

static void keypress(unsigned char key, int x, int y) {
	(void)x;
	(void)y;

	if (key == ' ') {

	}
}

int	main(int ac, char **av) {
	game = new Game();

	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(2560, 1600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("42run");
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 2560.0 / 1600.0, 0.1, 100.0);

	loadTextures();

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glutKeyboardFunc(keypress);
	glutSpecialFunc(special_keypress);
	glutDisplayFunc(display);
	glutMainLoop();

	delete game;
}
