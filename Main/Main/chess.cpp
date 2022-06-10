#include "chess.h"
std::map<COLOR, sf::Texture> texture;

Chess::Chess(COLOR _color) : color(_color) {
	this->load_texture();
}

void Chess::load_texture() {
	if(texture.find(this->color) == texture.end())
		texture[this->color].loadFromFile(GetPath())
}