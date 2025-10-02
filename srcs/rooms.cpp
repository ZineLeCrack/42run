#include "Includes.hpp"

void	floor(int hole, vector<GLuint> textureIDs, glm::mat4 MVP, double i, double z) {

	if (hole < 2) {
		glBindTexture(GL_TEXTURE_2D, textureIDs[hole == 0 ? FLOOR : LAVA]);

		glBegin(GL_QUADS);

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 1.0, i + 1.0 - z));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 1.0, i + 1.0 - z));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 1.0, i + 0.0 - z));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 1.0, i + 0.0 - z));

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 1.0, i + 1.0 - z));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-1.5, 1.0, i + 1.0 - z));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(-1.5, 1.0, i + 0.0 - z));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 1.0, i + 0.0 - z));

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(1.5, 1.0, i + 1.0 - z));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 1.0, i + 1.0 - z));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 1.0, i + 0.0 - z));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(1.5, 1.0, i + 0.0 - z));

		glEnd();
	} else {
		glDisable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);

		glColor3d(0.8, 0.8, 0.8); applyMVP(MVP, glm::vec3(-1.5, 1.0, i + 1.0 - z));
		glColor3d(0.8, 0.8, 0.8); applyMVP(MVP, glm::vec3(-1.5, 1.0, i + 0.0 - z));
		glColor3d(0.8, 0.8, 0.8); applyMVP(MVP, glm::vec3(-1.5, 2.0, i + 0.0 - z));
		glColor3d(0.8, 0.8, 0.8); applyMVP(MVP, glm::vec3(-1.5, 2.0, i + 1.0 - z));

		glColor3d(0.7, 0.7, 0.7); applyMVP(MVP, glm::vec3(-0.5, 1.0, i + 1.0 - z));
		glColor3d(0.8, 0.8, 0.8); applyMVP(MVP, glm::vec3(-1.5, 1.0, i + 1.0 - z));
		glColor3d(0.8, 0.8, 0.8); applyMVP(MVP, glm::vec3(-1.5, 2.0, i + 1.0 - z));
		glColor3d(0.7, 0.7, 0.7); applyMVP(MVP, glm::vec3(-0.5, 2.0, i + 1.0 - z));

		glColor3d(0.7, 0.7, 0.7); applyMVP(MVP, glm::vec3(-0.5, 1.0, i + 1.0 - z));
		glColor3d(0.6, 0.6, 0.6); applyMVP(MVP, glm::vec3(0.5, 1.0, i + 1.0 - z));
		glColor3d(0.6, 0.6, 0.6); applyMVP(MVP, glm::vec3(0.5, 2.0, i + 1.0 - z));
		glColor3d(0.7, 0.7, 0.7); applyMVP(MVP, glm::vec3(-0.5, 2.0, i + 1.0 - z));

		glColor3d(0.5, 0.5, 0.5); applyMVP(MVP, glm::vec3(1.5, 1.0, i + 1.0 - z));
		glColor3d(0.6, 0.6, 0.6); applyMVP(MVP, glm::vec3(0.5, 1.0, i + 1.0 - z));
		glColor3d(0.6, 0.6, 0.6); applyMVP(MVP, glm::vec3(0.5, 2.0, i + 1.0 - z));
		glColor3d(0.5, 0.5, 0.5); applyMVP(MVP, glm::vec3(1.5, 2.0, i + 1.0 - z));

		glColor3d(0.5, 0.5, 0.5); applyMVP(MVP, glm::vec3(1.5, 1.0, i + 1.0 - z));
		glColor3d(0.5, 0.5, 0.5); applyMVP(MVP, glm::vec3(1.5, 1.0, i + 0.0 - z));
		glColor3d(0.5, 0.5, 0.5); applyMVP(MVP, glm::vec3(1.5, 2.0, i + 0.0 - z));
		glColor3d(0.5, 0.5, 0.5); applyMVP(MVP, glm::vec3(1.5, 2.0, i + 1.0 - z));

		glEnd();
		glEnable(GL_TEXTURE_2D);
	}
}

void	celling(vector<GLuint> textureIDs, glm::mat4 MVP, double i, double z) {
	glBindTexture(GL_TEXTURE_2D, textureIDs[CELLING]);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 0.0, i + 1.0 - z));
	glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 0.0, i + 1.0 - z));
	glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 0.0, i + 0.0 - z));
	glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 0.0, i + 0.0 - z));

	glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-1.5, 0.0, i + 1.0 - z));
	glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-0.5, 0.0, i + 1.0 - z));
	glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(-0.5, 0.0, i + 0.0 - z));
	glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-1.5, 0.0, i + 0.0 - z));

	glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(1.5, 0.0, i + 1.0 - z));
	glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 0.0, i + 1.0 - z));
	glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 0.0, i + 0.0 - z));
	glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(1.5, 0.0, i + 0.0 - z));

	glEnd();
}

void	wall(vector<GLuint> textureIDs, glm::mat4 MVP, Map *map, double i, double z) {
	glBindTexture(GL_TEXTURE_2D, textureIDs[map->get_left_wall_tex()]);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-1.5, 0.0, i + 1.0 - z));
	glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-1.5, 1.0, i + 1.0 - z));
	glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(-1.5, 1.0, i + 0.0 - z));
	glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-1.5, 0.0, i + 0.0 - z));

	glEnd();

	glBindTexture(GL_TEXTURE_2D, textureIDs[map->get_right_wall_tex()]);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(1.5, 0.0, i + 1.0 - z));
	glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(1.5, 1.0, i + 1.0 - z));
	glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(1.5, 1.0, i + 0.0 - z));
	glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(1.5, 0.0, i + 0.0 - z));

	glEnd();
}

void	display_player(vector<GLuint> textureIDs, glm::mat4 MVP, double player_pos, double jumping) {
	glBindTexture(GL_TEXTURE_2D, textureIDs[NPC_1]);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-0.4 + player_pos, 0.3 + jumping, 1.5));
	glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-0.4 + player_pos, 0.9 + jumping, 1.5));
	glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.4 + player_pos, 0.9 + jumping, 1.5));
	glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(0.4 + player_pos, 0.3 + jumping, 1.5));

	glEnd();
}

void	display_obs(vector<GLuint> textureIDs, glm::mat4 MVP, Map *map, double i, double z) {
	int	*obs = map->get_obs();
	if (!obs) return ;
	int	j;
	for (j = 0; j < 3; j++) {
		if (obs[j]) break;
	}
	if (j < 3) {
		double	pos = (j - 1) * 0.8;

		if (obs[j] == 1) {
			glBindTexture(GL_TEXTURE_2D, textureIDs[VAL]);

			glBegin(GL_QUADS);

			glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-0.2 + pos, 0.75, i + 0.7 - z));
			glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-0.2 + pos, 0.9, i + 0.2 - z));
			glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.2 + pos, 0.9, i + 0.2 - z));
			glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(0.2 + pos, 0.75, i + 0.7 - z));
			
			
		}
		else if (obs[j] == 2) {
			glDisable(GL_TEXTURE_2D);
			glBegin(GL_TRIANGLES);

			glColor3d(0.8, 0.8, 0.8); applyMVP(MVP, glm::vec3(-0.2 + pos, 1.0, i + 0.5 - z));
			glColor3d(0.5, 0.5, 0.5); applyMVP(MVP, glm::vec3(0.2 + pos, 1.0, i + 0.5 - z));
			glColor3d(0.3, 0.3, 0.3); applyMVP(MVP, glm::vec3(0.0 + pos, 0.5, i + 0.7 - z));

			glColor3d(0.8, 0.8, 0.8); applyMVP(MVP, glm::vec3(-0.2 + pos, 1.0, i + 0.7 - z));
			glColor3d(0.5, 0.5, 0.5); applyMVP(MVP, glm::vec3(-0.2 + pos, 1.0, i + 0.5 - z));
			glColor3d(0.3, 0.3, 0.3); applyMVP(MVP, glm::vec3(0.0 + pos, 0.5, i + 0.7 - z));

			glColor3d(0.8, 0.8, 0.8); applyMVP(MVP, glm::vec3(0.2 + pos, 1.0, i + 0.7 - z));
			glColor3d(0.5, 0.5, 0.5); applyMVP(MVP, glm::vec3(0.2 + pos, 1.0, i + 0.5 - z));
			glColor3d(0.3, 0.3, 0.3); applyMVP(MVP, glm::vec3(0.0 + pos, 0.5, i + 0.7 - z));
		}

		glEnd();
		glEnable(GL_TEXTURE_2D);
	}
}

void	corridor(Game *game) {
	vector<GLuint>	textureIDs = game->get_textureIDs();
	glm::mat4 MVP = game->get_MVP();
	double	distance = game->get_distance();
	double	z = distance - (int)distance;

	for (int i = 0; i < 30 ; i++) {
		floor(game->get_map()[i]->is_hole(), textureIDs, MVP, i, z);
		celling(textureIDs, MVP, i, z);
		wall(textureIDs, MVP, game->get_map()[i], i, z);
	}

	for (int i = 29; i >= 0 ; i--) {
		display_obs(textureIDs, MVP, game->get_map()[i], i, z);
	}

	display_player(textureIDs, MVP, game->get_pos(), game->get_height());
}
