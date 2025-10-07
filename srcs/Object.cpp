#include "Object.hpp"

Object::Object(const char *filename) {
	ifstream file(filename);

	if (file.fail()) {
		cerr << RED "Can't open obj file: " << filename << RESET << endl;
	}

	string	line;

	while (getline(file, line)) {
		if (line[0] == 'v') _vertices.push_back(string(line));
		else if (line[0] == 'f') _faces.push_back(string(line));
	}
}

Object::~Object() {}

void	Object::put_obj(vector<GLuint> textureIDs, double index_z, double pos, double gap, glm::mat4 MVP) {
	int	i;
	for (vector<string>::iterator it = _faces.begin(); it != _faces.end(); it++) {
		string	num = (*it).substr(1);
		i = 0;
		glBindTexture(GL_TEXTURE_2D, textureIDs[FLOOR]);
		glBegin(GL_QUADS);
		while (num.find_first_not_of(' ') != string::npos) {
			unsigned int	n = atoi(num.c_str()) - 1;
			double	x, y, z;
			string vertex = _vertices[n];

			vertex.erase(vertex.begin());
			vertex = vertex.substr(vertex.find_first_not_of(' '));
			x = atof(vertex.c_str());
			vertex = vertex.substr(vertex.find_first_of(' '));
			vertex = vertex.substr(vertex.find_first_not_of(' '));
			y = atof(vertex.c_str());
			vertex = vertex.substr(vertex.find_first_of(' '));
			vertex = vertex.substr(vertex.find_first_not_of(' '));
			z = atof(vertex.c_str());

			glTexCoord2d(i % 4 > 1, i % 4 == 1 || i % 4 == 2); applyMVP(MVP, glm::vec3(x + pos, y, index_z + z + 0.8 - gap));

			if (num.find_first_not_of(' ') == string::npos) break ;
			num = num.substr(num.find_first_not_of(' '));
			if (num.find_first_of(' ') == string::npos) break ;
			num = num.substr(num.find_first_of(' '));
			i++;
		}
		glEnd();
	}
}
