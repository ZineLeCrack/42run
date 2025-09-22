#include "Game.hpp"
#include "Map.hpp"

Game::Game(): _score(0), _distance(0.0), _player_pos(0.0), _is_jumping(false), _height(0.0) {}

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

void				Game::gen_start() {
	for (unsigned char i = 0; i < 30; i++) {
		Map	*room = new Map(randint(13) + 2, randint(13) + 2, 0);
		_map.push_back(room);
	}
}

void				Game::gen_next() {
	Map	*next = new Map(randint(13) + 2, randint(13) + 2, randint(5) == 0 ? randint(4) : 0);
	_map.push_back(next);
}
