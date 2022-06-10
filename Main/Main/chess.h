#ifndef  CHESS_H
#define CHESS_H
#include <SFML/Graphics.hpp>
#include "helper.h"
#include "setting.h"

class Chess {
public:
	Chess(COLOR _color);
	sf::Sprite sprite;
	COLOR color; 
	TYPE type;
	void load_texture();
};

#endif // ! CHESS_H
