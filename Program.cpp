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
		
		switch (parsedInput.size())
		{
		case 1:
			if (command == "draw")
			{
				board->Draw();
				break;
			}
			else if (command == "list")
			{
				cout << "Shapes:" << endl;
				for (std::shared_ptr<Shape> shape : board->GetShapes())
					cout << std::format("ID: {}\n\t{}", shape->GetId(), shape->GetParameters()) << endl;
				break;
			}
			else if (command == "shapes")
			{
				std::cout << "Available shapes: " << std::endl;
				std::cout << "line startPointX startPointY endPointX endPointY" << std::endl;
				std::cout << "circle radius startPointX startPointY" << std::endl;
				std::cout << "triangle base height startPointX startPointY" << std::endl;
				std::cout << "parallelogram startPointX startPointY endPointX endPointY baseWidth" << std::endl;
				std::cout << "rectangle base height startPointX startPointY" << std::endl;
				std::cout << "square side startPointX startPointY" << std::endl;
				break;
			}
			else if (command == "help")
			{
				std::cout << "Commands: draw: draws board, list: lists all added shapes, shapes: lists all available shapes, save: saves board state to file, load: loads board state from file, help, quit" << endl;
				break;
			}
			else if (command == "quit")
			{
				std::cout << "Goodbye!" << endl;
				break;
			}
			else if (command == "undo")
			{
				board->Undo();
				break;
			}
			else if (command == "clear")
			{
				board->Clear();
				break;
			}
			else
			{
				std::cout << "Invalid command" << endl;
				break;
			}
		case 2:
			if (command == "save")
			{
				board->Save(parsedInput[1]);
				break;
			}
			else if (command == "load")
			{
				board->Load(parsedInput[1]);
				break;
			}
			else
			{
				std::cout << "Invalid command" << endl;
				break;
			}
		case 5:
			if (command != "add")
			{
				std::cout << "Invalid command" << endl;
				break;
			}
			else if (parsedInput[1] == "circle")
			{
				std::shared_ptr<Circle> circle = std::make_shared<Circle>(stoi(parsedInput[2]), stoi(parsedInput[3]), stoi(parsedInput[4]));
				board->AddShape(circle);
				break;
			}
			else if (parsedInput[1] == "square")
			{
				std::shared_ptr<Square> square = std::make_shared<Square>(stoi(parsedInput[2]), stoi(parsedInput[3]), stoi(parsedInput[4]));
				board->AddShape(square);
				break;
			}
			else
			{
				std::cout << "Invalid command" << endl;
				break;
			}
		case 6:
			if (command != "add")
			{
				std::cout << "Invalid command" << endl;
				break;
			}
			else if (parsedInput[1] == "line")
			{
				std::shared_ptr<Line> line = std::make_shared<Line>(stoi(parsedInput[2]), stoi(parsedInput[3]), stoi(parsedInput[4]), stoi(parsedInput[5]));
				board->AddShape(line);
				break;
			}
			else if (parsedInput[1] == "triangle")
			{
				std::shared_ptr<Triangle> triangle = std::make_shared<Triangle>(stoi(parsedInput[2]), stoi(parsedInput[3]), stoi(parsedInput[4]), stoi(parsedInput[5]));
				board->AddShape(triangle);
				break;
			}
			else if (parsedInput[1] == "rectangle")
			{
				std::shared_ptr<Rectangle> rectangle = std::make_shared<Rectangle>(stoi(parsedInput[2]), stoi(parsedInput[3]), stoi(parsedInput[4]), stoi(parsedInput[5]));
				board->AddShape(rectangle);
				break;
			}
			else
			{
				std::cout << "Invalid command" << endl;
				break;
			}
		case 7:
			if (parsedInput[1] == "parallelogram")
			{
				std::shared_ptr<Parallelogram> parallelogram = std::make_shared<Parallelogram>(stoi(parsedInput[1]), stoi(parsedInput[2]), stoi(parsedInput[3]), stoi(parsedInput[4]), stoi(parsedInput[5]));
				board->AddShape(parallelogram);
				break;
			}
			else
			{
				std::cout << "Invalid command" << endl;
				break;
			}
		default:
			std::cout << "Invalid command" << endl;
		}
		
	} while (input != "quit");
	return 0;
}