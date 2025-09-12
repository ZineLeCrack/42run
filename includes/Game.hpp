#pragma once

#include "Includes.hpp"

class Game
{
	private:

		vector<GLuint>	_textureIDs;
		double			_distance;
		double			_player_pos;

	public:

		Game();
		~Game();

		vector<GLuint>	&get_textureIDs();
		double			&get_distance();
		double			&get_pos();
};
