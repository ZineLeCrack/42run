#pragma once

#include "Includes.hpp"

class Map;

class Game
{
	private:

		vector<GLuint>		_textureIDs;
		vector<Map *>		_map;
		unsigned long long	_score;
		double				_distance;
		double				_player_pos;
		bool				_is_jumping;
		double				_height;

	public:

		Game();
		~Game();

		vector<GLuint>		&get_textureIDs();
		vector<Map *>		&get_map();
		unsigned long long	&get_score();
		double				&get_distance();
		double				&get_pos();
		bool				&get_is_jumping();
		double				&get_height();

		void			gen_start();
		void			gen_next();
};
