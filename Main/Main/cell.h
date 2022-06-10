#ifndef CELL_H
#define CELL_H

#include "vector"
#include "data.h"
#include "chess.h"
using namespace std; 
class Cell {
public:
	sf::RectangleShape rect;
	STATUS status = EMPTY;
	Chess* chess;

};
typedef typename vector<vector<Cell>> Cells;
#endif // CELL_H

