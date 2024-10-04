#pragma once
#include "Shape.h"
class Line : public Shape
{
public:
	Line(const int InAX, const int InAY, const int InBX, const int InBY) : xA(InAX), yA(InAY), xB(InBX), yB(InBY) {}
	~Line() = default;
	void Draw(Board& board) override;

	unsigned long long GetId() const override { return std::hash<int>{}(xA + yA + xB + yB); }
	std::string GetParameters() const override { return std::format("Line, from X{}, Y{} to X{}, Y{}", xA, yA, xB, yB); }
private:
	int xA, yA, xB, yB;
};