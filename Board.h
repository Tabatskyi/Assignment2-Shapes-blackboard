#pragma once
#include <memory>
#include <vector>
#include "Shape.h"

class Board
{
public:
	Board(const unsigned int InWidth, const unsigned int InHeight, const unsigned int InBorderWidth);
	~Board() = default;

	void Draw();
	void Undo();
	void Clear();

	void AddShape(std::shared_ptr<Shape> shape);
	void SetPixel(const unsigned int x, const unsigned int y);

	std::vector<std::string> DumpShapes();
	std::vector<std::shared_ptr<Shape>> GetShapes() const { return shapes; }
private:
	std::vector<std::vector<char>> board;
	std::vector<std::shared_ptr<Shape>> shapes;
	unsigned int width, height;
	const unsigned int borderWidth = 2;
};
