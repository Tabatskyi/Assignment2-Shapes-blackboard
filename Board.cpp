#include "Board.h"

Board::Board(const unsigned int InWidth, const unsigned int InHeight) : width(InWidth), height(InHeight) 
{
	board.resize(height);
	for (unsigned int i = 0; i < height; ++i)
	{
		board[i].resize(width);
		for (unsigned int j = 0; j < width; ++j)
		{
			board[i][j] = ' ';
		}
	}

}

void Board::SetPixel(const unsigned int x, const unsigned int y, const char c)
{
	board[y][x] = c;
}

void Board::Draw()
{
	for (std::shared_ptr<Shape> shape : shapes)
	{
		shape->Draw(*this);
	}

	for (unsigned int i = 0; i < height; ++i)
	{
		for (unsigned int j = 0; j < width; ++j)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

void Board::AddShape(std::shared_ptr<Shape> shape)
{
	shapes.push_back(shape);
}
