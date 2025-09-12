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

class Game;

/*------- FUNCTIONS ------ */
void	corridor(Game *game);

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

/*--------- DEFINES --------*/
#define FLOOR					0
#define CELLING					1
#define PAINT_1					2
#define PAINT_2					3
#define PAINT_3					4
#define PAINT_4					5
#define PAINT_5					6
#define LOGO_42_1				7
#define LOGO_42_2				8
#define RIGHT_WALL_CORRIDOR_1	9
#define RIGHT_WALL_CORRIDOR_2	10
#define RIGHT_WALL_CORRIDOR_3	11
#define RIGHT_WALL_CORRIDOR_4	12
#define RIGHT_WALL_CORRIDOR_5	13
#define RIGHT_WALL_CORRIDOR_6	14
#define NPC_1					15
#define NPC_2					16

