#include "user.h"

User::User(COLOR _color) : color(_color) {};

bool User::check_win(Cell& cell) {

};
bool User::ForU(Cell& cell)
{
	return cell.chess&& cell.chess->color == this->color;
}