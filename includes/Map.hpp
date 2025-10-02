#pragma once

#include "Includes.hpp"

class Map
{
	private:

		GLuint					_left_wall_tex;
		GLuint					_right_wall_tex;
		int						*_obs;
		int						_hole;
		int						_turn;

	public:

		Map(GLuint left_tex, GLuint right_tex, int *obs, int hole, int turn);
		~Map();

		GLuint	get_left_wall_tex();
		GLuint	get_right_wall_tex();
		int		*get_obs();
		int		is_hole();
		int		is_turn();
};
