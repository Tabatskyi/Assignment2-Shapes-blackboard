#pragma once
#include "Shape.h"
class Line : public Shape
{
public:
	Line(const unsigned int InLength, const unsigned int InX, const unsigned int InY) : length(InLength), x(InX), y(InY) {}
	~Line() = default;
	void Draw(Board& board) override;
private:
	unsigned int length;
	unsigned int x;
	unsigned int y;
};

