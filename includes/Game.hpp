#pragma once

#include "Includes.hpp"

class Game
{
	private:

		vector<GLuint>	_textureIDs;
		double			_distance;
		double			_player_pos;
		bool			_is_jumping;
		double			_height;

	public:

		Game();
		~Game();

		vector<GLuint>	&get_textureIDs();
		double			&get_distance();
		double			&get_pos();
		bool			&get_is_jumping();
		double			&get_height();
};
