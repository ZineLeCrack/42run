#pragma once

#include "Includes.hpp"

class Map
{
	private:

		GLuint					_left_wall_tex;
		GLuint					_right_wall_tex;
		int						*_obs;
		bool					_lava;

	public:

		Map(GLuint left_tex, GLuint right_tex, int *obs, bool lava);
		~Map();

		GLuint	get_left_wall_tex();
		GLuint	get_right_wall_tex();
		int		*get_obs();
		bool	is_lava();
};
