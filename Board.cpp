#include "Board.h"

Board::Board(const unsigned int InWidth, const unsigned int InHeight) : width(InWidth), height(InHeight)
{
	board.resize(height);
	for (unsigned int i = 0; i < height; ++i)
	{
		board[i].resize(width);
		for (unsigned int j = 0; j < width; ++j)
		{
			if (i < BORDER_WIDTH || (i >= height - BORDER_WIDTH && i <= height))
				board[i][j] = '-';
			else if (j < BORDER_WIDTH || (j >= width - BORDER_WIDTH && j <= width))
				board[i][j] = '|';
			else
				board[i][j] = ' ';
		}
	}
}
void Board::SetPixel(const unsigned int x, const unsigned int y)
{
	if (x < BORDER_WIDTH || x >= width - BORDER_WIDTH || y < BORDER_WIDTH || y >= height - BORDER_WIDTH)
		return;
	board[y][x] = '*';
}

void Board::AddShape(std::shared_ptr<Shape> shape)
{
	shapes.push_back(shape);
}

void Board::Undo()
{
	if (shapes.size() > 0)
		shapes.pop_back();
}

void Board::Clear()
{
	shapes.clear();
}

void Board::Draw()
{
	for (std::shared_ptr<Shape> shape : shapes)
		shape->Draw(*this);

	for (unsigned int i = 0; i < height; ++i)
	{
		for (unsigned int j = 0; j < width; ++j)
			std::cout << board[i][j];
		std::cout << std::endl;
	}
}

void Board::Save(const std::string& filename)
{
	
}

void Board::Load(const std::string& filename)
{

}
