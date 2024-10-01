#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
public:
	Rectangle(const unsigned int InWidth, const unsigned int InHeight, const unsigned int InX, const unsigned int InY) : width(InWidth), height(InHeight), x(InX), y(InY) {}
	~Rectangle() = default;
	void Draw(Board& board) override;
private:
	unsigned int width;
	unsigned int height;
	unsigned int x;
	unsigned int y;
};

