#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Parallelogram.h"
#include "Triangle.h"
#include "Circle.h"
#include "Line.h"
#include "Board.h"

int main() 
{
	std::unique_ptr<Board> board = std::make_unique<Board>(60, 20);
	std::shared_ptr<Line> line1 = std::make_shared<Line>(10, 5, 20, 15);
	std::shared_ptr<Line> line2 = std::make_shared<Line>(10, 5, 20, 5);
	std::shared_ptr<Line> line3 = std::make_shared<Line>(22, 15, 12, 5);
	std::shared_ptr<Line> line4 = std::make_shared<Line>(10, 5, 10, 15);
	std::shared_ptr<Line> line5 = std::make_shared<Line>(30, 15, 40, 10);
	std::shared_ptr<Line> line6 = std::make_shared<Line>(42, 10, 32, 15);
	std::shared_ptr<Rectangle> rectangle = std::make_shared<Rectangle>(10, 5, 5, 10);
	std::shared_ptr<Circle> circle = std::make_shared<Circle>(5, 20, 10);
	std::shared_ptr<Triangle> triangle = std::make_shared<Triangle>(10, 5, 30, 10);
	std::shared_ptr<Parallelogram> parallelogram = std::make_shared<Parallelogram>(15, 10, 5, 30, 15);

	//board->AddShape(line1);
	//board->AddShape(line2);
	//board->AddShape(line3);
	//board->AddShape(line4);
	//board->AddShape(line5);
	//board->AddShape(line6);
	//board->AddShape(rectangle);
	//board->AddShape(circle);
	//board->AddShape(triangle);
	board->AddShape(parallelogram);
	board->Draw();
	return 0;
}