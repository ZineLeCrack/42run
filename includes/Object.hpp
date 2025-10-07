#pragma once

#include "Includes.hpp"

class Object
{
	private:

		vector<string>	_vertices;
		vector<string>	_faces;
		GLuint			_tex;

	public:

		Object(const char *filename, GLuint tex);
		~Object();

		void	put_obj(vector<GLuint> textureIDs, double index_z, double pos, double gap, glm::mat4 MVP);
};
