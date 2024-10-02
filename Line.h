#pragma once
#include "Shape.h"
class Line : public Shape
{
public:
	Line(const unsigned int InAX, const unsigned int InAY, const unsigned int InBX, const unsigned int InBY) : xA(InAX), yA(InAY), xB(InBX), yB(InBY) {}
	~Line() = default;
	void Draw(Board& board) override;
private:
	unsigned int xA;
	unsigned int yA;
	unsigned int xB;
	unsigned int yB;
};

