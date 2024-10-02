#pragma once
#include <iostream>
#include <vector>
#include "Shape.h"

class Board
{
public:
	Board(const unsigned int InWidth, const unsigned int InHeight);
	~Board() = default;

	void Draw();
	void Undo();
	void Clear();

	void Save(const std::string& filename);
	void Load(const std::string& filename);

	void AddShape(std::shared_ptr<Shape> shape);
	void SetPixel(const unsigned int x, const unsigned int y, const char c);
private:
	std::vector<std::vector<char>> board;
	std::vector<std::shared_ptr<Shape>> shapes;
	unsigned int width;
	unsigned int height;
};
