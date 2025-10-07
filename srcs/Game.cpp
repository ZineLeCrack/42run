#include "Game.hpp"
#include "Map.hpp"
#include "Object.hpp"

Game::Game(glm::mat4 MVP): _score(0), _distance(0.0), _player_pos(0.0), _is_jumping(false), _sneak(false), _height(0.0), _MVP(MVP) {}

Game::~Game() {
	for (vector<Map *>::iterator i = _map.begin(); i != _map.end(); i++) {
		delete (*i);
	}
}

vector<GLuint>		&Game::get_textureIDs() { return _textureIDs; }

vector<Map *>		&Game::get_map() { return _map; }

vector<Object *>	&Game::get_objects() { return _objects; }

unsigned long long	&Game::get_score() { return _score; }

double				&Game::get_distance() { return _distance; }

double				&Game::get_pos() { return _player_pos; }

bool				&Game::get_is_jumping() { return _is_jumping; }

bool				&Game::get_sneak() { return _sneak; }

double				&Game::get_height() { return _height; }

glm::mat4			Game::get_MVP() { return _MVP; }

void				Game::set_MVP(const glm::mat4 MVP) { _MVP = MVP; };

void				Game::gen_start() {
	for (unsigned char i = 0; i < 30; i++) {
		Map	*room = new Map(randint(13) + 2, randint(13) + 2, NULL, false, 0);
		_map.push_back(room);
	}
}

void				Game::gen_next() {
	int	turn = randint(60) > 0 ? 0 : 1;
	int	*obs = new int[3];
	int	hole = 0;

	bzero(obs, sizeof(int) * 3);
	if (!turn) {
		hole = randint(12) > 0 ? 0 : randint(2) + 1;
		if (!hole) {
			if (!randint(8)) obs[0] = randint(4) + 1;
			if (!randint(8)) obs[1] = randint(4) + 1;
			if (!randint(8)) obs[2] = randint(4) + 1;
		}
	} else {
		for (int i = 0; i < 5; i++) {
			_map.push_back(new Map(randint(13) + 2, randint(13) + 2, obs, hole, i == 2 ? randint(2) + 2 : turn));
			obs = new int[3];
			bzero(obs, sizeof(int) * 3);
		}
	}

	Map	*next = new Map(randint(13) + 2, randint(13) + 2, obs, hole, turn);
	_map.push_back(next);
}
