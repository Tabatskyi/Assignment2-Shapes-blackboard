#include "Rectangle.h"
#include "Board.h"

void Rectangle::Draw(Board& board)
{
	for (unsigned int i = 0; i <= width; i++)
	{
		board.SetPixel(x + i, y, '*');
		board.SetPixel(x + i, y + height, '*');
	}
	for (unsigned int i = 0; i < height; i++)
	{
		board.SetPixel(x, y + i, '*');
		board.SetPixel(x + width, y + i, '*');
	}
}