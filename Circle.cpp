#include "Circle.h"
#include "Board.h"

void Circle::Draw(Board& board) const // https://zingl.github.io/bresenham.html#:~:text=This%20page%20introduces%20a%20compact%20and%20efficient%20implementation%20of%20Bresenham's
{
    int oX = x + radius, oY = y , r;
    int x = -radius, y = 0;
    int error = 2 - 2 * radius;
    int k = 2;
    do
    {
        board.SetPixel(oX - x * k, oY + y);
        board.SetPixel(oX - y * k, oY - x);
        board.SetPixel(oX + x * k, oY - y);
        board.SetPixel(oX + y * k, oY + x);
        r = error;
        if (r <= y)
        {
            y++;
            error += y * 2 + 1;
        }
        if (r > x || error > y)
        {
            x++;
            error += x * 2 + 1;
        }
    } while (x < 0);
}