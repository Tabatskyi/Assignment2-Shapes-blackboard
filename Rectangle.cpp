#include "Rectangle.h"
#include "Board.h"
#include "Line.h"

void Rectangle::Draw(Board& board)
{
	std::shared_ptr<Line> AB = std::make_unique<Line>(x, y, x + width, y);
	std::shared_ptr<Line> BC = std::make_unique<Line>(x + width, y, x + width, y + height);
	std::shared_ptr<Line> CD = std::make_unique<Line>(x + width, y + height, x, y + height);
	std::shared_ptr<Line> DA = std::make_unique<Line>(x, y + height, x, y);
	AB->Draw(board); BC->Draw(board); CD->Draw(board); DA->Draw(board);
}