#include "Includes.hpp"

void	floor(vector<GLuint> textureIDs, double i, double z) {
	glBindTexture(GL_TEXTURE_2D, textureIDs[FLOOR]);

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

void	celling(vector<GLuint> textureIDs, double i, double z) {
	glBindTexture(GL_TEXTURE_2D, textureIDs[CELLING]);

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

void	wall(vector<GLuint> textureIDs, int tex, double i, double z) {
	glBindTexture(GL_TEXTURE_2D, textureIDs[tex]);

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
	if (tex % 2 == 0) {
		double	pos;
		if (tex == 10)
			pos = -0.8;
		else if (tex == 12)
			pos = 0.8;
		else
			pos = 0.0;

		glBindTexture(GL_TEXTURE_2D, textureIDs[VAL]);

		glBegin(GL_QUADS);

		glTexCoord2d(0.0, 0.0); glVertex3d(-0.2 + pos, 0.75, i + 1.5 - z);
		glTexCoord2d(0.0, 1.0); glVertex3d(-0.2 + pos, 0.9, i + 1.0 - z);
		glTexCoord2d(1.0, 1.0); glVertex3d(0.2 + pos, 0.9, i + 1.0 - z);
		glTexCoord2d(1.0, 0.0); glVertex3d(0.2 + pos, 0.75, i + 1.5 - z);

		glEnd();
	}
}

void	display_player(vector<GLuint> textureIDs, double player_pos, double jumping) {
	glBindTexture(GL_TEXTURE_2D, textureIDs[NPC_1]);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); glVertex3d(-0.2 + player_pos, 0.4 + jumping, 1.0);
	glTexCoord2d(0.0, 1.0); glVertex3d(-0.2 + player_pos, 0.8 + jumping, 1.0);
	glTexCoord2d(1.0, 1.0); glVertex3d(0.2 + player_pos, 0.8 + jumping, 1.0);
	glTexCoord2d(1.0, 0.0); glVertex3d(0.2 + player_pos, 0.4 + jumping, 1.0);

	glEnd();
}

void	corridor(Game *game) {
	vector<GLuint>	textureIDs = game->get_textureIDs();
	double	distance = game->get_distance();
	int		rounded_distance = (int)distance;

	for (int i = 0; i < 30 ; i += 1.0) {
		floor(textureIDs, i, distance - rounded_distance);
	}

	for (int i = 0; i < 30 ; i += 1.0) {
		celling(textureIDs, i, distance - rounded_distance);
	}

	for (int i = 0; i < 30; i++) {
		wall(textureIDs, RIGHT_WALL_CORRIDOR_1 + (i + rounded_distance) % 6, i, distance - (int)distance);
	}

	display_player(textureIDs, game->get_pos(), game->get_height());
}
