#include "Triangle.h"
#include "Board.h"
#include "Line.h"

void Triangle::Draw(Board& board)
{
	std::shared_ptr<Line> AB = std::make_unique<Line>(x, y, x + base, y);
	std::shared_ptr<Line> BC = std::make_unique<Line>(x + base, y, x + base / 2, y - height);
	std::shared_ptr<Line> CA = std::make_unique<Line>(x + base / 2, y - height, x, y);
	AB->Draw(board); BC->Draw(board); CA->Draw(board);
}