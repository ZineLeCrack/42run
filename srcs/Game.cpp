#include "Game.hpp"
#include "Map.hpp"

Game::Game(glm::mat4 MVP): _score(0), _distance(0.0), _player_pos(0.0), _is_jumping(false), _height(0.0), _MVP(MVP) {}

Game::~Game() {
	for (vector<Map *>::iterator i = _map.begin(); i != _map.end(); i++) {
		delete (*i);
	}
}

vector<GLuint>		&Game::get_textureIDs() { return _textureIDs; }

vector<Map *>		&Game::get_map() { return _map; }

unsigned long long	&Game::get_score() { return _score; }

double				&Game::get_distance() { return _distance; }

double				&Game::get_pos() { return _player_pos; }

bool				&Game::get_is_jumping() { return _is_jumping; }

double				&Game::get_height() { return _height; }

glm::mat4			Game::get_MVP() { return _MVP; }

void				Game::gen_start() {
	for (unsigned char i = 0; i < 30; i++) {
		Map	*room = new Map(randint(13) + 2, randint(13) + 2, NULL, false, 0);
		_map.push_back(room);
	}
}

void				Game::gen_next() {
	int	turn = randint(30) > 0 ? 0 : randint(2) + 1;
	int	*obs = new int[3];
	int	hole = 0;
	
	bzero(obs, sizeof(int) * 3);
	if (!turn) {
		hole = randint(12) > 0 ? 0 : randint(2) + 1;
		if (!hole) {
			int random = randint(5);
			if (!random) {
				obs[randint(3)] = randint(2) + 1;
			}
		}
	} else {
		for (int i = 0; i < 5; i++) {
			_map.push_back(new Map(randint(13) + 2, randint(13) + 2, obs, hole, turn));
		}
	}

	Map	*next = new Map(randint(13) + 2, randint(13) + 2, obs, hole, turn);
	_map.push_back(next);
}
