#include "helper.h"
using namespace sf;
Vector2f GetPosition(int row, int column) {
	return Vector2f(setting::cell_offset + column * (setting::cell_size + setting::line_space), setting::cell_offset + row * (setting::cell_size + setting::line_space));

}

string GetPath(COLOR color, TYPE type) {
	string path = "resources/images/";
	switch (COLOR)
	{
	case WHITE: path + "W"; break;
	case BLACK: path + "B"; break;
	}
	switch (type)
	{
	case KING: path + "K";
		break;
	case QUEEN: path + "Q";
		break;
	case ROOK: path + "R"; 
		break;
	case KNIGHT: path + "N";
		break;
	case BISHOP: path + "B";
		break;
	case PWAN: path + "P";
		break;
	}
	return path + ".png";
}

int GetIndex(int x)
{
	x -= setting::cell_offset;
	if (x < 0)
		return -1; 
	int space = setting::cell_size + setting::line_space;
	int index = x / space;
	if (index > 2 || x > index * space + setting::cell_size)
		return -1;
	return index; 
}

string GetPiece(COLOR color, TYPE type) {
	string path = ""; 
	switch (COLOR)
	{
	case WHITE: path + "W"; break;
	case BLACK: path + "B"; break;
	}
	switch (type)
	{
	case KING: path + "K";
		break;
	case QUEEN: path + "Q";
		break;
	case ROOK: path + "R";
		break;
	case KNIGHT: path + "N";
		break;
	case BISHOP: path + "B";
		break;
	case PWAN: path + "P";
		break;
	}
	return path;
}