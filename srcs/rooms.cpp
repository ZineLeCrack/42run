#include "Includes.hpp"

void	floor(vector<Map*> map, vector<GLuint> textureIDs, glm::mat4 MVP, int index_z, double gap) {

	int	hole = map[index_z]->is_hole();
	if (hole < 2) {
		glBindTexture(GL_TEXTURE_2D, textureIDs[hole == 0 ? FLOOR : LAVA]);

		glBegin(GL_QUADS);

		glTexCoord2d((hole == 1 ? (index_z % 4 == 1 || index_z % 4 == 2) : 1.0), (hole == 1 ? (index_z % 4 < 2) : 0.0)); applyMVP(MVP, glm::vec3(-0.5, 1.0, index_z + 1.0 - gap));
		glTexCoord2d((hole == 1 ? (index_z % 4 < 2) : 1.0), (hole == 1 ? (index_z % 4 == 0 || index_z % 4 == 3) : 1.0)); applyMVP(MVP, glm::vec3(0.5, 1.0, index_z + 1.0 - gap));
		glTexCoord2d((hole == 1 ? (index_z % 4 == 0 || index_z % 4 == 3) : 0.0), (hole == 1 ? (index_z % 4 > 1) : 1.0)); applyMVP(MVP, glm::vec3(0.5, 1.0, index_z + 0.0 - gap));
		glTexCoord2d((hole == 1 ? (index_z % 4 > 1) : 0.0), (hole == 1 ? (index_z % 4 == 1 || index_z % 4 == 2) : 0.0)); applyMVP(MVP, glm::vec3(-0.5, 1.0, index_z + 0.0 - gap));

		if (map[index_z]->is_turn() != 1) {
			glTexCoord2d((hole == 1 ? (index_z % 4 == 1 || index_z % 4 == 2) : 1.0), (hole == 1 ? (index_z % 4 < 2) : 0.0)); applyMVP(MVP, glm::vec3(-0.5, 1.0, index_z + 1.0 - gap));
			glTexCoord2d((hole == 1 ? (index_z % 4 < 2) : 1.0), (hole == 1 ? (index_z % 4 == 0 || index_z % 4 == 3) : 1.0)); applyMVP(MVP, glm::vec3(-1.5, 1.0, index_z + 1.0 - gap));
			glTexCoord2d((hole == 1 ? (index_z % 4 == 0 || index_z % 4 == 3) : 0.0), (hole == 1 ? (index_z % 4 > 1) : 1.0)); applyMVP(MVP, glm::vec3(-1.5, 1.0, index_z + 0.0 - gap));
			glTexCoord2d((hole == 1 ? (index_z % 4 > 1) : 0.0), (hole == 1 ? (index_z % 4 == 1 || index_z % 4 == 2) : 0.0)); applyMVP(MVP, glm::vec3(-0.5, 1.0, index_z + 0.0 - gap));

			glTexCoord2d((hole == 1 ? (index_z % 4 == 1 || index_z % 4 == 2) : 1.0), (hole == 1 ? (index_z % 4 < 2) : 0.0)); applyMVP(MVP, glm::vec3(1.5, 1.0, index_z + 1.0 - gap));
			glTexCoord2d((hole == 1 ? (index_z % 4 < 2) : 1.0), (hole == 1 ? (index_z % 4 == 0 || index_z % 4 == 3) : 1.0)); applyMVP(MVP, glm::vec3(0.5, 1.0, index_z + 1.0 - gap));
			glTexCoord2d((hole == 1 ? (index_z % 4 == 0 || index_z % 4 == 3) : 0.0), (hole == 1 ? (index_z % 4 > 1) : 1.0)); applyMVP(MVP, glm::vec3(0.5, 1.0, index_z + 0.0 - gap));
			glTexCoord2d((hole == 1 ? (index_z % 4 > 1) : 0.0), (hole == 1 ? (index_z % 4 == 1 || index_z % 4 == 2) : 0.0)); applyMVP(MVP, glm::vec3(1.5, 1.0, index_z + 0.0 - gap));
		}

		glEnd();
	} else {
		glBindTexture(GL_TEXTURE_2D, textureIDs[GALAXY]);
		glBegin(GL_QUADS);

		if (index_z < 29 && map[index_z + 1]->is_hole() == 2) {
			glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 2.0, index_z + 0.0 - gap));
			glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-1.5, 2.0, index_z + 0.0 - gap));
			glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(-1.5, 2.0, index_z + 1.0 - gap));
			glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 2.0, index_z + 1.0 - gap));

			glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(0.5, 2.0, index_z + 0.0 - gap));
			glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-0.5, 2.0, index_z + 0.0 - gap));
			glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(-0.5, 2.0, index_z + 1.0 - gap));
			glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(0.5, 2.0, index_z + 1.0 - gap));

			glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(0.5, 2.0, index_z + 0.0 - gap));
			glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(1.5, 2.0, index_z + 0.0 - gap));
			glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(1.5, 2.0, index_z + 1.0 - gap));
			glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(0.5, 2.0, index_z + 1.0 - gap));
		} else {
			glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 1.0, index_z + 1.0 - gap));
			glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-1.5, 1.0, index_z + 1.0 - gap));
			glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(-1.5, 2.0, index_z + 1.0 - gap));
			glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 2.0, index_z + 1.0 - gap));

			glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 1.0, index_z + 1.0 - gap));
			glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 1.0, index_z + 1.0 - gap));
			glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 2.0, index_z + 1.0 - gap));
			glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 2.0, index_z + 1.0 - gap));

			glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(1.5, 1.0, index_z + 1.0 - gap));
			glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 1.0, index_z + 1.0 - gap));
			glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 2.0, index_z + 1.0 - gap));
			glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(1.5, 2.0, index_z + 1.0 - gap));
		}

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-1.5, 1.0, index_z + 1.0 - gap));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-1.5, 1.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(-1.5, 2.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-1.5, 2.0, index_z + 1.0 - gap));

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(1.5, 1.0, index_z + 1.0 - gap));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(1.5, 1.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(1.5, 2.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(1.5, 2.0, index_z + 1.0 - gap));

		glEnd();
	}
}

void	celling(int turn, vector<GLuint> textureIDs, glm::mat4 MVP, int index_z, double gap) {
	glBindTexture(GL_TEXTURE_2D, textureIDs[CELLING]);
	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 0.0, index_z + 1.0 - gap));
	glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 0.0, index_z + 1.0 - gap));
	glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 0.0, index_z + 0.0 - gap));
	glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 0.0, index_z + 0.0 - gap));

	if (turn != 1) {
		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-1.5, 0.0, index_z + 1.0 - gap));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-0.5, 0.0, index_z + 1.0 - gap));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(-0.5, 0.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-1.5, 0.0, index_z + 0.0 - gap));

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(1.5, 0.0, index_z + 1.0 - gap));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 0.0, index_z + 1.0 - gap));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 0.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(1.5, 0.0, index_z + 0.0 - gap));
	}

	glEnd();
}

void	wall(vector<GLuint> textureIDs, glm::mat4 MVP, Map *map, int index_z, double gap) {
	int		turn = map->is_turn();
	double	mov = 0.0;

	if (turn) {
		glBindTexture(GL_TEXTURE_2D, textureIDs[LOGO_42_1]);

		glBegin(GL_QUADS);

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-1.5, 0.0, index_z + 0.0 - gap));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-1.5, 1.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(-0.5, 1.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 0.0, index_z + 0.0 - gap));

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(0.5, 0.0, index_z + 0.0 - gap));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 1.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(1.5, 1.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(1.5, 0.0, index_z + 0.0 - gap));

		glEnd();
		mov++;
	}

	if (turn == 2) {
		glBindTexture(GL_TEXTURE_2D, textureIDs[map->get_left_wall_tex()]);

		glBegin(GL_QUADS);

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 0.0, index_z + 1.0 - gap));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-0.5, 1.0, index_z + 1.0 - gap));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 1.0, index_z + 1.0 - gap));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(0.5, 0.0, index_z + 1.0 - gap));

		glEnd();

		glBindTexture(GL_TEXTURE_2D, textureIDs[map->get_right_wall_tex()]);

		glBegin(GL_QUADS);

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(1.5 - mov, 0.0, index_z + 1.0 - gap));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(1.5 - mov, 1.0, index_z + 1.0 - gap));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(1.5 - mov, 1.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(1.5 - mov, 0.0, index_z + 0.0 - gap));

		glEnd();
	}

	else if (turn == 3) {
		glBindTexture(GL_TEXTURE_2D, textureIDs[map->get_left_wall_tex()]);

		glBegin(GL_QUADS);

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-1.5 + mov, 0.0, index_z + 1.0 - gap));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-1.5 + mov, 1.0, index_z + 1.0 - gap));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(-1.5 + mov, 1.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-1.5 + mov, 0.0, index_z + 0.0 - gap));

		glEnd();

		glBindTexture(GL_TEXTURE_2D, textureIDs[map->get_right_wall_tex()]);

		glBegin(GL_QUADS);

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(0.5, 0.0, index_z + 1.0 - gap));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(0.5, 1.0, index_z + 1.0 - gap));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(-0.5, 1.0, index_z + 1.0 - gap));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-0.5, 0.0, index_z + 1.0 - gap));

		glEnd();
	}

	else {

		glBindTexture(GL_TEXTURE_2D, textureIDs[map->get_left_wall_tex()]);

		glBegin(GL_QUADS);

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-1.5 + mov, 0.0, index_z + 1.0 - gap));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-1.5 + mov, 1.0, index_z + 1.0 - gap));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(-1.5 + mov, 1.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(-1.5 + mov, 0.0, index_z + 0.0 - gap));

		glEnd();

		glBindTexture(GL_TEXTURE_2D, textureIDs[map->get_right_wall_tex()]);

		glBegin(GL_QUADS);

		glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(1.5 - mov, 0.0, index_z + 1.0 - gap));
		glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(1.5 - mov, 1.0, index_z + 1.0 - gap));
		glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(1.5 - mov, 1.0, index_z + 0.0 - gap));
		glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(1.5 - mov, 0.0, index_z + 0.0 - gap));

		glEnd();
	}
}

void	display_player(vector<GLuint> textureIDs, glm::mat4 MVP, double player_pos, double jumping, bool sneak, bool is_turning, double to_turn) {
	double	sneak_gap = sneak * 0.3;
	glBindTexture(GL_TEXTURE_2D, textureIDs[NPC_1]);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0); applyMVP(MVP, glm::vec3(-0.4 + player_pos + (is_turning ? to_turn : 0.0), 0.3 + jumping + (is_turning ? 0.1 : 0.0) + sneak_gap, 1.5 + (is_turning ? 0.5 : 0.0)));
	glTexCoord2d(0.0, 1.0); applyMVP(MVP, glm::vec3(-0.4 + player_pos + (is_turning ? to_turn : 0.0), 0.9 + jumping + (is_turning ? 0.1 : 0.0), 1.5 + (is_turning ? 0.5 : 0.0)));
	glTexCoord2d(1.0, 1.0); applyMVP(MVP, glm::vec3(0.4 + player_pos + (is_turning ? to_turn : 0.0), 0.9 + jumping + (is_turning ? 0.1 : 0.0), 1.5 + (is_turning ? 0.5 : 0.0)));
	glTexCoord2d(1.0, 0.0); applyMVP(MVP, glm::vec3(0.4 + player_pos + (is_turning ? to_turn : 0.0), 0.3 + jumping + (is_turning ? 0.1 : 0.0) + sneak_gap, 1.5 + (is_turning ? 0.5 : 0.0)));

	glEnd();
}

void	display_obs(Game *game, Map *map, double index_z, double gap) {
	int	*obs = map->get_obs();
	if (!obs) return ;

	for (int j = 0; j < 3; j++) {
		double	pos = (j - 1) * 0.8;

		if (obs[j] == 1) {
			glBindTexture(GL_TEXTURE_2D, game->get_textureIDs()[VAL]);

			glBegin(GL_QUADS);

			glTexCoord2d(0.0, 0.0); applyMVP(game->get_MVP(), glm::vec3(-0.2 + pos, 0.75, index_z + 0.7 - gap));
			glTexCoord2d(0.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(-0.2 + pos, 0.9, index_z + 0.2 - gap));
			glTexCoord2d(1.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(0.2 + pos, 0.9, index_z + 0.2 - gap));
			glTexCoord2d(1.0, 0.0); applyMVP(game->get_MVP(), glm::vec3(0.2 + pos, 0.75, index_z + 0.7 - gap));

			glEnd();
		}
		else if (obs[j] == 2) {
			glBindTexture(GL_TEXTURE_2D, game->get_textureIDs()[METAL]);
			glBegin(GL_TRIANGLES);

			glTexCoord2d(0.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(-0.2 + pos, 1.0, index_z + 0.5 - gap));
			glTexCoord2d(1.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(0.2 + pos, 1.0, index_z + 0.5 - gap));
			glTexCoord2d(1.0, 0.0); applyMVP(game->get_MVP(), glm::vec3(0.0 + pos, 0.5, index_z + 0.7 - gap));

			glTexCoord2d(0.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(-0.2 + pos, 1.0, index_z + 0.7 - gap));
			glTexCoord2d(1.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(-0.2 + pos, 1.0, index_z + 0.5 - gap));
			glTexCoord2d(1.0, 0.0); applyMVP(game->get_MVP(), glm::vec3(0.0 + pos, 0.5, index_z + 0.7 - gap));

			glTexCoord2d(0.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(0.2 + pos, 1.0, index_z + 0.7 - gap));
			glTexCoord2d(1.0, 1.0); applyMVP(game->get_MVP(), glm::vec3(0.2 + pos, 1.0, index_z + 0.5 - gap));
			glTexCoord2d(1.0, 0.0); applyMVP(game->get_MVP(), glm::vec3(0.0 + pos, 0.5, index_z + 0.7 - gap));

			glEnd();
		} else if (obs[j] == 3) {
			game->get_objects()[0]->put_obj(game->get_textureIDs(), index_z, pos, gap, game->get_MVP());
		}
	}
}

void	corridor(Game *game, bool is_turning, double to_turn) {
	vector<GLuint>	textureIDs = game->get_textureIDs();
	glm::mat4 MVP = game->get_MVP();
	double	distance = game->get_distance();
	double	gap = distance - (int)distance;

	for (int i = 0; i < 30 ; i++) {
		floor(game->get_map(), textureIDs, MVP, i, gap);
		celling(game->get_map()[i]->is_turn(), textureIDs, MVP, i, gap);
		wall(textureIDs, MVP, game->get_map()[i], i, gap);
	}

	for (int i = 29; i >= 0 ; i--) {
		display_obs(game, game->get_map()[i], i, gap);
	}

	display_player(textureIDs, MVP, game->get_pos(), game->get_height(), game->get_sneak(), is_turning, to_turn);
}
