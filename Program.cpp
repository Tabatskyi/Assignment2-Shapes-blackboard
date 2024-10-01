#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Line.h"
#include "Board.h"

int main() 
{
	std::unique_ptr<Board> board = std::make_unique<Board>(20, 20);
	std::shared_ptr<Line> line = std::make_shared<Line>(10, 5, 5);

	board->AddShape(line);
	board->Draw();
	return 0;
}