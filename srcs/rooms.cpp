#include "Includes.hpp"

void	floor(GLuint textureId[], double i, double z) {
	glBindTexture(GL_TEXTURE_2D, textureId[FLOOR]);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); glVertex3d(-0.5, 1.0, i + 1.0 - z);
	glTexCoord2d(0.0, 1.0); glVertex3d(0.5, 1.0, i + 1.0 - z);
	glTexCoord2d(1.0, 1.0); glVertex3d(0.5, 1.0, i + 0.0 - z);
	glTexCoord2d(1.0, 0.0); glVertex3d(-0.5, 1.0, i + 0.0 - z);

	glTexCoord2d(0.0, 0.0); glVertex3d(-0.5, 1.0, i + 1.0 - z);
	glTexCoord2d(0.0, 1.0); glVertex3d(-1.5, 1.0, i + 1.0 - z);
	glTexCoord2d(1.0, 1.0); glVertex3d(-1.5, 1.0, i + 0.0 - z);
	glTexCoord2d(1.0, 0.0); glVertex3d(-0.5, 1.0, i + 0.0 - z);

	glTexCoord2d(0.0, 0.0); glVertex3d(1.5, 1.0, i + 1.0 - z);
	glTexCoord2d(0.0, 1.0); glVertex3d(0.5, 1.0, i + 1.0 - z);
	glTexCoord2d(1.0, 1.0); glVertex3d(0.5, 1.0, i + 0.0 - z);
	glTexCoord2d(1.0, 0.0); glVertex3d(1.5, 1.0, i + 0.0 - z);

	glEnd();
}

void	celling(GLuint textureId[], double i, double z) {
	glBindTexture(GL_TEXTURE_2D, textureId[CELLING]);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); glVertex3d(-0.5, 0.0, i + 1.0 - z);
	glTexCoord2d(0.0, 1.0); glVertex3d(0.5, 0.0, i + 1.0 - z);
	glTexCoord2d(1.0, 1.0); glVertex3d(0.5, 0.0, i + 0.0 - z);
	glTexCoord2d(1.0, 0.0); glVertex3d(-0.5, 0.0, i + 0.0 - z);

	glTexCoord2d(0.0, 0.0); glVertex3d(-1.5, 0.0, i + 1.0 - z);
	glTexCoord2d(0.0, 1.0); glVertex3d(-0.5, 0.0, i + 1.0 - z);
	glTexCoord2d(1.0, 1.0); glVertex3d(-0.5, 0.0, i + 0.0 - z);
	glTexCoord2d(1.0, 0.0); glVertex3d(-1.5, 0.0, i + 0.0 - z);

	glTexCoord2d(0.0, 0.0); glVertex3d(1.5, 0.0, i + 1.0 - z);
	glTexCoord2d(0.0, 1.0); glVertex3d(0.5, 0.0, i + 1.0 - z);
	glTexCoord2d(1.0, 1.0); glVertex3d(0.5, 0.0, i + 0.0 - z);
	glTexCoord2d(1.0, 0.0); glVertex3d(1.5, 0.0, i + 0.0 - z);

	glEnd();
}

void	wall(GLuint textureId[], int tex, double i, double z) {
	glBindTexture(GL_TEXTURE_2D, textureId[tex]);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); glVertex3d(1.5, 0.0, i + 1.0 - z);
	glTexCoord2d(0.0, 1.0); glVertex3d(1.5, 1.0, i + 1.0 - z);
	glTexCoord2d(1.0, 1.0); glVertex3d(1.5, 1.0, i + 0.0 - z);
	glTexCoord2d(1.0, 0.0); glVertex3d(1.5, 0.0, i + 0.0 - z);

	glTexCoord2d(0.0, 0.0); glVertex3d(-1.5, 0.0, i + 1.0 - z);
	glTexCoord2d(0.0, 1.0); glVertex3d(-1.5, 1.0, i + 1.0 - z);
	glTexCoord2d(1.0, 1.0); glVertex3d(-1.5, 1.0, i + 0.0 - z);
	glTexCoord2d(1.0, 0.0); glVertex3d(-1.5, 0.0, i + 0.0 - z);

	glEnd();
}

void	display_player(GLuint tex, double player_pos) {
	glBindTexture(GL_TEXTURE_2D, tex);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); glVertex3d(-0.2 + player_pos, 0.4, 1.0);
	glTexCoord2d(0.0, 1.0); glVertex3d(-0.2 + player_pos, 0.8, 1.0);
	glTexCoord2d(1.0, 1.0); glVertex3d(0.2 + player_pos, 0.8, 1.0);
	glTexCoord2d(1.0, 0.0); glVertex3d(0.2 + player_pos, 0.4, 1.0);

	glEnd();
}

void	corridor(GLuint textureID[], Game *game) {

	double	distance = game->get_distance();
	int		rounded_distance = (int)distance;

	for (int i = 0; i < 30 ; i += 1.0) {
		floor(textureID, i, distance - rounded_distance);
	}

	for (int i = 0; i < 30 ; i += 1.0) {
		celling(textureID, i, distance - rounded_distance);
	}

	for (int i = 0; i < 30; i++) {
		wall(textureID, RIGHT_WALL_CORRIDOR_1 + (i + rounded_distance) % 6, i, distance - (int)distance);
	}

	display_player(textureID[NPC_1], game->get_pos());
}
