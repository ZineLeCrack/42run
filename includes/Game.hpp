#pragma once

#include "Includes.hpp"

class Game
{
	private:

		double			_distance;
		double			_player_pos;

	public:

		Game();
		~Game();

		double			&get_distance();
		double			&get_pos();
};
