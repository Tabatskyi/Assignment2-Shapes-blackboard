#pragma once
#include "Shape.h"
class Triangle : public Shape
{
public:
	Triangle(const unsigned int InBase, const unsigned int InHeight, const unsigned int InX, const unsigned int InY) : base(InBase), height(InHeight), x(InX), y(InY) {}
	~Triangle() = default;
	void Draw(Board& board) override;
private:
	unsigned int base;
	unsigned int height;
	unsigned int x;
	unsigned int y;
};

