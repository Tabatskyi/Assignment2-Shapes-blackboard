#pragma once
#include "Board.h"

class Circle : public Shape
{
public:
	Circle(const unsigned int InRadius, const unsigned int InX, const unsigned int InY) : radius(InRadius), x(InX), y(InY) {}
	~Circle() = default;
	void Draw(Board& board) override;
private:
	unsigned int radius;
	unsigned int x;
	unsigned int y;
};

