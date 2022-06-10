#ifndef USER_H
#define USER_H

#include "data.h"
#include "cell.h"

class User {
public :
	User(COLOR);
	COLOR color;
	bool check_win(Cells& cells);
	bool ForU(Cell cell);

};
#endif // !USER_H
