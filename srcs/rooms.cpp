#include "Includes.hpp"

void	floor(vector<GLuint> textureIDs, glm::mat4 MVP, double i, double z) {
	glBindTexture(GL_TEXTURE_2D, textureIDs[FLOOR]);

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

	glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-0.2 + player_pos, 0.4 + jumping, 1.0));
	glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-0.2 + player_pos, 0.8 + jumping, 1.0));
	glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.2 + player_pos, 0.8 + jumping, 1.0));
	glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(0.2 + player_pos, 0.4 + jumping, 1.0));

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
		double	pos = (j - 2) * 0.8;

		glBindTexture(GL_TEXTURE_2D, textureIDs[VAL]);

		glBegin(GL_QUADS);

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-0.2 + pos, 0.75, i + 1.5 - z));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-0.2 + pos, 0.9, i + 1.0 - z));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.2 + pos, 0.9, i + 1.0 - z));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(0.2 + pos, 0.75, i + 1.5 - z));

		glEnd();
	}
}

void	corridor(Game *game) {
	vector<GLuint>	textureIDs = game->get_textureIDs();
	glm::mat4 MVP = game->get_MVP();
	double	distance = game->get_distance();
	double	z = distance - (int)distance;

	for (int i = 0; i < 30 ; i += 1.0) {
		floor(textureIDs, MVP, i, z);
		celling(textureIDs, MVP, i, z);
		wall(textureIDs, MVP, game->get_map()[i], i, z);
	}

	for (int i = 0; i < 30 ; i += 1.0) {
		display_obs(textureIDs, MVP, game->get_map()[i], i, z);
	}

	display_player(textureIDs, MVP, game->get_pos(), game->get_height());
}
