#include "Includes.hpp"

static double c = 0;

void	display() {
	glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 0.2, -0.5, 0.0, 0.5, 5.0, 0.0, -1.0, 0.0);

	glBegin(GL_QUADS);

	for (double i = 0; i < 50 ; i += 1.0) {
		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(0.5, 0.0, i + 1.0);
		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(0.5, 1.0, i + 1.0);
		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(0.5, 1.0, i + 0.0);
		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(0.5, 0.0, i + 0.0);

		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(-0.5, 0.0, i + 1.0);
		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(-0.5, 1.0, i + 1.0);
		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(-0.5, 1.0, i + 0.0);
		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(-0.5, 0.0, i + 0.0);

		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(-0.5, 1.0, i + 1.0);
		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(0.5, 1.0, i + 1.0);
		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(0.5, 1.0, i + 0.0);
		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(-0.5, 1.0, i + 0.0);

		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(-0.5, 0.0, i + 1.0);
		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(0.5, 0.0, i + 1.0);
		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(0.5, 0.0, i + 0.0);
		glColor3d(1.0, (int)(i + c) % 15 / 15.0, 1.0); glVertex3d(-0.5, 0.0, i + 0.0);
	}

	// glColor3d(1.0, 0.0, 0.0); glVertex3d(1.0, 0.0, 1.0);
	// glColor3d(1.0, 0.0, 0.0); glVertex3d(1.0, 1.0, 1.0);
	// glColor3d(1.0, 0.0, 0.0); glVertex3d(1.0, 1.0, 0.0);
	// glColor3d(1.0, 0.0, 0.0); glVertex3d(1.0, 0.0, 0.0);

	// glColor3d(1.0, 1.0, 0.0); glVertex3d(1.0, 0.0, 2.0);
	// glColor3d(1.0, 1.0, 0.0); glVertex3d(1.0, 1.0, 2.0);
	// glColor3d(1.0, 1.0, 0.0); glVertex3d(1.0, 1.0, 1.0);
	// glColor3d(1.0, 1.0, 0.0); glVertex3d(1.0, 0.0, 1.0);

	glEnd();

	c += 0.2;

	glutSwapBuffers();
	glutPostRedisplay();
}

int	main(int ac, char **av) {
	Game *game = new Game();

	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(2560, 1600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("42run");
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 2560.0 / 1600.0, 0.1, 100.0);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glutDisplayFunc(display);
	glutMainLoop();

	delete game;
}
