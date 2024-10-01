#include "Line.h"
#include "Board.h"

void Line::Draw(Board& board)
{
	for (unsigned int i = 0; i < length; ++i)
	{
		board.SetPixel(x + i, y, '*');
	}
}