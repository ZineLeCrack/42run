/*-------- INCLUDES -------*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <GL/glut.h>
#include <GL/gl.h>
#include <SOIL/SOIL.h>

/*-------- CLASSES --------*/
#include "Game.hpp"

/*------- FUNCTIONS ------ */
void	corridor(GLuint textureId[]);

/*----- DEFINE COLORS -----*/
#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"

/*-------- Namespace -------*/
using namespace std;
