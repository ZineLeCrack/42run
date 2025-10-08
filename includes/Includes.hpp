/*------- GL Version ------*/
//glxinfo | grep "OpenGL version"

/*-------- INCLUDES -------*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <unistd.h>
#include <sys/time.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <glm/glm/glm/glm.hpp>
#include <glm/glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/glm/gtc/type_ptr.hpp>
#include <png.h>

/*-------- CLASSES --------*/
#include "Game.hpp"
#include "Map.hpp"
#include "Object.hpp"

class Game;
class Map;
class Object;

/*------- FUNCTIONS ------ */
void		loadTextures(Game *game);

void		corridor(Game *game, bool is_turning, double to_turn);
void		applyMVP(const glm::mat4 &MVP, const glm::vec3 &v);
int			randint(int x);
long long	get_timestamp();
void		wait(long long time);

/*----- DEFINE COLORS -----*/
#define RESET	"\033[0m"
#define RED		"\033[31;1m"
#define GREEN	"\033[32;1m"
#define YELLOW	"\033[33;1m"
#define BLUE	"\033[34;1m"
#define MAGENTA	"\033[35;1m"
#define CYAN	"\033[36;1m"

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
#define VAL						17
#define BOOM					18
#define NB_0					19
#define NB_1					20
#define NB_2					21
#define NB_3					22
#define NB_4					23
#define NB_5					24
#define NB_6					25
#define NB_7					26
#define NB_8					27
#define NB_9					28
#define LAVA					29
#define METAL					30
#define GALAXY					31

#define KEY_ESC					27

#define VAL_OBS					1
#define SPIKE					2
#define TABLE					3
#define COIN_42					4

#define NO_HOLE					0
#define LAVA_TRAP				1
#define GALAXY_HOLE				2

#define NO_TURN					0
#define IS_TURN					1
#define TURN_LEFT				2
#define TURN_RIGHT				3
