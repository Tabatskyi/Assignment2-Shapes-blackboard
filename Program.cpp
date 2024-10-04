#include <iostream>
#include <format>
#include "Shape.h"
#include "Parallelogram.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "Line.h"
#include "Board.h"
#include "Parser.h"

int main() 
{
	std::unique_ptr<Board> board = std::make_unique<Board>(60, 20);
	std::unique_ptr<Parser> parser = std::make_unique<Parser>();

	std::shared_ptr<Line> line1 = std::make_shared<Line>(10, 5, 20, 15);
	std::shared_ptr<Line> line2 = std::make_shared<Line>(10, 5, 20, 5);
	std::shared_ptr<Line> line3 = std::make_shared<Line>(22, 15, 12, 5);
	std::shared_ptr<Line> line4 = std::make_shared<Line>(10, 5, 10, 15);
	std::shared_ptr<Line> line5 = std::make_shared<Line>(30, 15, 40, 10);
	std::shared_ptr<Line> line6 = std::make_shared<Line>(42, 10, 32, 18);
	std::shared_ptr<Circle> circle = std::make_shared<Circle>(5, 20, 10);
	std::shared_ptr<Triangle> triangle = std::make_shared<Triangle>(15, 5, 30, 10);
	std::shared_ptr<Parallelogram> parallelogram = std::make_shared<Parallelogram>(10, 5, 30, 15, 5);
	std::shared_ptr<Rectangle> rectangle = std::make_shared<Rectangle>(10, 5, 30, 15);
	std::shared_ptr<Square> square = std::make_shared<Square>(10, 2, 2);

	//board->AddShape(line1);
	//board->AddShape(line2);
	//board->AddShape(line3);
	//board->AddShape(line4);
	//board->AddShape(line5);
	//board->AddShape(line6);
	board->AddShape(circle);
	//board->AddShape(triangle);
	//board->AddShape(parallelogram);
	//board->AddShape(rectangle);
	board->AddShape(square);
	board->Draw();

	std::string input;
	do
	{
		cout << ">";
		std::vector<string> parsedInput;
		getline(cin, input);

		if (input.empty())
			continue;

		parsedInput = parser->Parse(input, " ");

		std::string command = parsedInput[0];
		if (command == "draw")
		{
			board->Draw();
		}
		else if (command == "list")
		{
			cout << "Shapes:" << endl;
			for (std::shared_ptr<Shape> shape : board->GetShapes())
				cout << std::format("ID: {}\n\t{}", shape->GetId(), shape->GetParameters()) << endl;
		}
		else if (command == "shapes")
		{
			std::cout << "Available shapes: " << std::endl;
			std::cout << "line startPointX startPointY endPointX endPointY\n circle radius startPointX startPointY\n triangle base height startPointX startPointY\n parallelogram startPointX startPointY endPointX endPointY baseWidth\n rectangle base height startPointX startPointY\n square side startPointX startPointY" << std::endl;
		}/*
		else if (command == "view")
		{
			if (parsedInput.size() < 2)
			{
				cout << "Invalid input" << endl;
				continue;
			}
			string type = parsedInput[1];
			if (!any_of(type.begin(), type.end(), isdigit))
			{
				if (parsedInput.size() > 2)
					for (int i = 2; i < parsedInput.size(); i++)
						type += " " + parsedInput[i];

				view(type);
			}
			else
			{
				if (all_of(type.begin(), type.end(), isdigit))
				{
					unsigned long ticketID = stoul(type);
					view(ticketID);
				}
				else if (parser->Parse(type, ".").size() == 3)
				{
					string date = type;
					string number = parsedInput[2];
					view(date, number);
				}
			}
		}*/
		else if (command == "help")
			cout << "Commands:\n check date flightNo\n book date flightNo place Username\n return ID\n view ID\n view Username\n view date flightNo\n help\n quit" << endl;
		else if (command == "quit")
			cout << "Goodbye!" << endl;
		else
			cout << "Invalid command" << endl;
	} while (input != "quit");

	return 0;
}