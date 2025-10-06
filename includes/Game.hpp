#pragma once

#include "Includes.hpp"

class Map;
class Object;

class Game
{
	private:

		vector<GLuint>		_textureIDs;
		vector<Map *>		_map;
		vector<Object *>	_objects;
		unsigned long long	_score;
		double				_distance;
		double				_player_pos;
		bool				_is_jumping;
		double				_height;
		glm::mat4			_MVP;

	public:

		Game(glm::mat4 MVP);
		~Game();

		vector<GLuint>		&get_textureIDs();
		vector<Map *>		&get_map();
		vector<Object *>	&get_objects();
		unsigned long long	&get_score();
		double				&get_distance();
		double				&get_pos();
		bool				&get_is_jumping();
		double				&get_height();
		glm::mat4			get_MVP();

		void				set_MVP(const glm::mat4 MVP);

		void			gen_start();
		void			gen_next();
};
