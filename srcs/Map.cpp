#include "Map.hpp"

Map::Map(GLuint left_tex, GLuint right_tex, int *obs, int hole): _left_wall_tex(left_tex), _right_wall_tex(right_tex), _obs(obs), _hole(hole) {}

Map::~Map() { delete _obs; }

GLuint	Map::get_left_wall_tex() { return _left_wall_tex; }

GLuint	Map::get_right_wall_tex() { return _right_wall_tex; }

int		*Map::get_obs() { return _obs; }

int		Map::is_hole() { return _hole; }
