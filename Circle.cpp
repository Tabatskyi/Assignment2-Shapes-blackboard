#include "Circle.h"
#include "Board.h"

void Circle::Draw(Board& board)  // https://zingl.github.io/bresenham.html#:~:text=This%20page%20introduces%20a%20compact%20and%20efficient%20implementation%20of%20Bresenham's
{
	int oX = x + radius, oY = y;
    int x = -radius, y = 0, slopeError = 2 - 2 * radius; 
    do 
    {
        board.SetPixel(oX - x, oY + y); 
        board.SetPixel(oX - y, oY - x); 
        board.SetPixel(oX + x, oY - y); 
        board.SetPixel(oX + y, oY + x); 
        radius = slopeError;
        if (radius <= y) 
        {
			y++;
            slopeError += y * 2 + 1;
        }
        if (radius > x || slopeError > y) 
        {
			x++;
            slopeError += x * 2 + 1;
        }
    } while (x < 0);
}