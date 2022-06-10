#include "board.h"
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(520, 520), "Chess", Style::Titlebar | Style::Close);
	Board board(&window);
	board.run();
}