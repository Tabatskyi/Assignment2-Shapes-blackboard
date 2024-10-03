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
    // https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/
    // https://zingl.github.io/bresenham.html#:~:text=This%20page%20introduces%20a%20compact%20and%20efficient%20implementation%20of%20Bresenham's
	else
	{
        bool steep = abs(yB - yA) > abs(xB - xA);

        if (steep) 
        {
            std::swap(xA, yA);
            std::swap(xB, yB);
        }

        if (xA > xB) 
        {
            std::swap(xA, xB);
            std::swap(yA, yB);
        }

        int dx = abs(xB - xA), dy = abs(yB - yA);

        int error = 2 * dy - dx;
        int yStep = (yA < yB) ? 1 : -1;

        for (int x = xA, y = yA; x <= xB; x++) 
        {
            if (steep) 
                board.SetPixel(y, x);
            else 
                board.SetPixel(x, y); 

            error -= dy;
            if (error < 0) 
            {
                y += yStep;
                error += dx;
            }
        }
	}
}