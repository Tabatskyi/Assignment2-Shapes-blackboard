#include "Parallelogram.h"
#include "Board.h"
#include "Line.h"

void Parallelogram::Draw(Board& board)
{
	int height = y1 - y0;
	int xA = x0;
	int yA = y0;
	int xB = x0 + width;
	int yB = y0;
	int xC = x1;
	int yC = y1;
	int xD = x1 - width;
	int yD = y1;
	std::shared_ptr<Line> AB = std::make_shared<Line>(xA, yA, xB, yB);
	std::shared_ptr<Line> BC = std::make_shared<Line>(xB, yB, xC, yC);
	std::shared_ptr<Line> CD = std::make_shared<Line>(xC, yC, xD, yD);
	std::shared_ptr<Line> DA = std::make_shared<Line>(xD, yD, xA, yA);
	AB->Draw(board); BC->Draw(board); CD->Draw(board); DA->Draw(board);
}