#include "board.h"
#include <iostream>

using namespace sf;
Board::Board(RenderWindow* _window) : window(_window) {
	this->white = new User(WHITE);
	this->black = new User(BLACK);
	this->window->setFramerateLimit(60);
}
void Board::init()
{
	end = false;
	this->cells.resize(8);
	for (int row = 0; row < 8; row++)
	{
		this->cells[row].resize(8);
		for (int column = 0; column < 8; column++)
		{
			this->cells[row][column].rect.setSize(Vector2f(setting::cell_size, setting::cell_size));
			this->cells[row][column].rect.setFillColor(setting::cell_color);
			this->cells[row][column].rect.setPosition(GetPosition(row, column));
		}
	}
	this->current = this->white;
	font.loadFromFile("resource/fonts/roboto.tt");
	status_text.setFont(font);
	status_text.setCharacterSize(20);
	status_text.setStyle(Text::Regular);
	status_text.setFillColor(Color::Black);
	status_text.setPosition(500.f, 250.f);
	this->update_status_text();
	
}

void Board::draw() {
	for(int row = 0 ; row < 8 ; row++)
		for (int column = 0; column < 8; column++) {
			this->window->draw(this->cells[row][column].rect);
			if (this->cells[row][column].status == OCCUPIED)
				this->window->draw(this->cells[row][column].chess->sprite);
		}
	this->window->draw(this->status_text);
}

void Board::run() {
	this->init;
	this->window->display();
	while (this->window->isOpen()) {
		Event event;
		while (this->window->pollEvent(event)) {
			if (event.type == Event::Closed)
				this->window->close();
			if (!this->end && Mouse::isButtonPressed(Mouse::Left))
				this->mouse_clicked(Mouse::getPosition(*(this->window)));
		}
		this->window->clear(Color(150, 150, 150));
		this->update_status_text();
		this->draw;
		this->window->display();
	}

}
void Board::mouse_clicked(const Vector2i& position)
{
	int row = GetIndex(position.y), column = GetIndex(position.x);
	if (row == -1 || column == -1)
		return;
	if (this->cells[row][column].status == EMPTY)
		this->cell_empty_clicked(row, column);
}

void Board::put_piece_in_cell(int row, int column) {
	Chess* chess = new Chess(this->current->color);
	chess->sprite.setPosition(this->cells[row][column].rect.getPosition());
	this->cells[row][column].chess = chess;
	this->cells[row][column].status = OCCUPIED;

}

void Board::update_status_text() {
	if (this->end)
		status_text.setString(GetPiece(this->current->color,KING) + "Wins!");
	else
		status_text.setString(GetPiece(this->current->color,KING) + "Wins!");
}