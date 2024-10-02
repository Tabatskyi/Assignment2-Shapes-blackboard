#include "Line.h"
#include "Board.h"

void Line::Draw(Board& board)  
{
	if (xA == xB)  // vertical line
	{
		if (yA > yB)
			std::swap(yA, yB);
		for (int y = yA; y <= yB; y++)
			board.SetPixel(xA, y);
	}
	else if (yA == yB)  // horizontal line
	{
		if (xA > xB)
			std::swap(xA, xB);
		for (int x = xA; x <= xB; x++)
			board.SetPixel(x, yA);
	}
	else  // https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/
	{
		if (xA > xB && yA > yB)
		{
			std::swap(xA, xB);
			std::swap(yA, yB);
		}
		else if (xA > xB && yA < yB)
		{
			std::swap(xA, xB);
			std::swap(yA, yB);
		}
		int m = 2 * (yB - yA);
		int slope_error = m - (xB - xA);
		for (int x = xA, y = yA; x <= xB; x++)
		{
			board.SetPixel(x, y);
			slope_error += m;
			if (slope_error >= 0)
			{
				y++;
				slope_error -= 2 * (xB - xA);
			}
			else
			{
				y--;
				slope_error -= 2 * (xB - xA);
			}
		}
	}
}