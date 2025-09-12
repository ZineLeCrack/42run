#include "Game.hpp"

Game::Game(): _distance(0.0), _player_pos(0.0) {}

Game::~Game() {}

vector<GLuint>	&Game::get_textureIDs() { return _textureIDs; }

double			&Game::get_distance() { return _distance; }

double			&Game::get_pos() { return _player_pos; }
