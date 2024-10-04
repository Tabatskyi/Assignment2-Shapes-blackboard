#include <iostream>
#include <fstream>
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

static void add(std::vector<std::string> shapeParameters, std::unique_ptr<Board>& board)
{
	if (shapeParameters[0] == "line")
	{
		std::shared_ptr<Line> line = std::make_shared<Line>(stoi(shapeParameters[1]), stoi(shapeParameters[2]), stoi(shapeParameters[3]), stoi(shapeParameters[4]));
		board->AddShape(line);
	}
	else if (shapeParameters[0] == "circle")
	{
		std::shared_ptr<Circle> circle = std::make_shared<Circle>(stoi(shapeParameters[1]), stoi(shapeParameters[2]), stoi(shapeParameters[3]));
		board->AddShape(circle);
	}
	else if (shapeParameters[0] == "triangle")
	{
		std::shared_ptr<Triangle> triangle = std::make_shared<Triangle>(stoi(shapeParameters[1]), stoi(shapeParameters[2]), stoi(shapeParameters[3]), stoi(shapeParameters[4]));
		board->AddShape(triangle);
	}
	else if (shapeParameters[0] == "parallelogram")
	{
		std::shared_ptr<Parallelogram> parallelogram = std::make_shared<Parallelogram>(stoi(shapeParameters[1]), stoi(shapeParameters[2]), stoi(shapeParameters[3]), stoi(shapeParameters[4]), stoi(shapeParameters[5]));
		board->AddShape(parallelogram);
	}
	else if (shapeParameters[0] == "rectangle")
	{
		std::shared_ptr<Rectangle> rectangle = std::make_shared<Rectangle>(stoi(shapeParameters[1]), stoi(shapeParameters[2]), stoi(shapeParameters[3]), stoi(shapeParameters[4]));
		board->AddShape(rectangle);
	}
	else if (shapeParameters[0] == "square")
	{
		std::shared_ptr<Square> square = std::make_shared<Square>(stoi(shapeParameters[1]), stoi(shapeParameters[2]), stoi(shapeParameters[3]));
		board->AddShape(square);
	}
	else
	{
		std::cout << "Invalid shape" << endl;
	}
}

static void save(const std::string& filename, const std::vector<std::string>& shapes)
{
	std::ofstream file(filename);
	if (file.is_open())
	{
		for (const std::string& shape : shapes)
			file << shape << std::endl;
		file.close();
	}
	else
		std::cout << "Unable to open file" << endl;
}

static void load(const std::string& filename, std::unique_ptr<Board>& board, std::unique_ptr<Parser>& parser)
{
	std::ifstream file(filename);
	std::vector<std::string> fileContent;

	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			if (!line.empty())
				fileContent.push_back(line);
		}
		file.close();
	}
	else
	{
		std::cout << "Unable to open file" << endl;
		return;
	}
	board->Clear();
	for (const std::string& shape : fileContent)
	{
		std::vector<std::string> shapeParameters = parser->Parse(shape, " ");
		add(shapeParameters, board);
	}
}

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
				std::cout << "line startPointX startPointY endPointX endPointY" << std::endl;
				std::cout << "circle radius startPointX startPointY" << std::endl;
				std::cout << "triangle base height startPointX startPointY" << std::endl;
				std::cout << "parallelogram startPointX startPointY endPointX endPointY baseWidth" << std::endl;
				std::cout << "rectangle base height startPointX startPointY" << std::endl;
				std::cout << "square side startPointX startPointY" << std::endl;
			}
			else if (command == "help")
			{
				std::cout << "Commands: draw: draws board, list: lists all added shapes, shapes: lists all available shapes, save: saves board state to file, load: loads board state from file, help, quit" << endl;
			}
			else if (command == "quit")
			{
				std::cout << "Goodbye!" << endl;
			}
			else if (command == "undo")
			{
				board->Undo();
			}
			else if (command == "clear")
			{
				board->Clear();
			}
			else if (command == "save")
			{
				save(parsedInput[1], board->DumpShapes());
			}
			else if (command == "load")
			{
				load(parsedInput[1], board, parser);
			}
			else if (command == "add")
			{
				std::vector<std::string> shapeParameters(parsedInput.begin() + 1, parsedInput.end());
				add(shapeParameters, board);
			}
			else
				std::cout << "Invalid command" << endl;
		
	} while (input != "quit");
	return 0;
}