#include "Includes.hpp"

void	floor(GLuint textureId[], double i, double z) {
	glBindTexture(GL_TEXTURE_2D, textureId[FLOOR]);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); glVertex3d(-0.5, 1.0, i + 1.0 - z);
	glTexCoord2d(0.0, 1.0); glVertex3d(0.5, 1.0, i + 1.0 - z);
	glTexCoord2d(1.0, 1.0); glVertex3d(0.5, 1.0, i + 0.0 - z);
	glTexCoord2d(1.0, 0.0); glVertex3d(-0.5, 1.0, i + 0.0 - z);

	glEnd();
}

void	celling(GLuint textureId[], double i, double z) {
	glBindTexture(GL_TEXTURE_2D, textureId[CELLING]);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); glVertex3d(-0.5, 0.0, i + 1.0 - z);
	glTexCoord2d(0.0, 1.0); glVertex3d(0.5, 0.0, i + 1.0 - z);
	glTexCoord2d(1.0, 1.0); glVertex3d(0.5, 0.0, i + 0.0 - z);
	glTexCoord2d(1.0, 0.0); glVertex3d(-0.5, 0.0, i + 0.0 - z);

	glEnd();
}

void	wall(GLuint textureId[], int tex, double i, double z) {
	glBindTexture(GL_TEXTURE_2D, textureId[tex]);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); glVertex3d(0.5, 0.0, i + 1.0 - z);
	glTexCoord2d(0.0, 1.0); glVertex3d(0.5, 1.0, i + 1.0 - z);
	glTexCoord2d(1.0, 1.0); glVertex3d(0.5, 1.0, i + 0.0 - z);
	glTexCoord2d(1.0, 0.0); glVertex3d(0.5, 0.0, i + 0.0 - z);

	glTexCoord2d(0.0, 0.0); glVertex3d(-0.5, 0.0, i + 1.0 - z);
	glTexCoord2d(0.0, 1.0); glVertex3d(-0.5, 1.0, i + 1.0 - z);
	glTexCoord2d(1.0, 1.0); glVertex3d(-0.5, 1.0, i + 0.0 - z);
	glTexCoord2d(1.0, 0.0); glVertex3d(-0.5, 0.0, i + 0.0 - z);

	glEnd();
}

void	corridor(GLuint textureID[], double z) {
	
	for (double i = 0; i < 6 ; i += 1.0) {
		floor(textureID, i, z);
	}

	for (double i = 0; i < 6 ; i += 1.0) {
		celling(textureID, i, z);
	}

	for (int i = 0; i < 6; i++)
		wall(textureID, RIGHT_WALL_CORRIDOR_1 + i, (double)i, z);
}
