#include "Includes.hpp"

void	corridor(GLuint textureID[])
{
	glBindTexture(GL_TEXTURE_2D, textureID[2]);
	
	glBegin(GL_QUADS);

	for (double i = 0; i < 50 ; i += 1.0) {
		glTexCoord2d(0.0, 0.0); glVertex3d(0.5, 0.0, i + 1.0);
		glTexCoord2d(0.0, 1.0); glVertex3d(0.5, 1.0, i + 1.0);
		glTexCoord2d(1.0, 1.0); glVertex3d(0.5, 1.0, i + 0.0);
		glTexCoord2d(1.0, 0.0); glVertex3d(0.5, 0.0, i + 0.0);

		glTexCoord2d(0.0, 0.0); glVertex3d(-0.5, 0.0, i + 1.0);
		glTexCoord2d(0.0, 1.0); glVertex3d(-0.5, 1.0, i + 1.0);
		glTexCoord2d(1.0, 1.0); glVertex3d(-0.5, 1.0, i + 0.0);
		glTexCoord2d(1.0, 0.0); glVertex3d(-0.5, 0.0, i + 0.0);
	}

	glEnd();

	glBindTexture(GL_TEXTURE_2D, textureID[0]);
	
	glBegin(GL_QUADS);

	for (double i = 0; i < 50 ; i += 1.0) {
		glTexCoord2d(0.0, 0.0); glVertex3d(-0.5, 1.0, i + 1.0);
		glTexCoord2d(0.0, 1.0); glVertex3d(0.5, 1.0, i + 1.0);
		glTexCoord2d(1.0, 1.0); glVertex3d(0.5, 1.0, i + 0.0);
		glTexCoord2d(1.0, 0.0); glVertex3d(-0.5, 1.0, i + 0.0);
	}

	glEnd();

	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	
	glBegin(GL_QUADS);

	for (double i = 0; i < 50 ; i += 1.0) {
		glTexCoord2d(0.0, 0.0); glVertex3d(-0.5, 0.0, i + 1.0);
		glTexCoord2d(0.0, 1.0); glVertex3d(0.5, 0.0, i + 1.0);
		glTexCoord2d(1.0, 1.0); glVertex3d(0.5, 0.0, i + 0.0);
		glTexCoord2d(1.0, 0.0); glVertex3d(-0.5, 0.0, i + 0.0);
	}

	glEnd();
}
