#ifndef HELPER_H
#define HELPER_H

#include "SFML/Graphics.hpp"
#include "setting.h"
#include "data.h"

using namespace std; 

sf::Vector2f GetPosition(int row, int column);
string GetPath(COLOR color, TYPE type);
int GetIndex(int x);
string GetPiece(COLOR color, TYPE type);

#endif // !HELPER_H
