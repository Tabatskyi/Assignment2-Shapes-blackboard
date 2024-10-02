#pragma once
#include "Shape.h"
class Line : public Shape
{
public:
	Line(const int InAX, const int InAY, const int InBX, const int InBY) : xA(InAX), yA(InAY), xB(InBX), yB(InBY) {}
	~Line() = default;
	void Draw(Board& board) override;

	unsigned long long GetId() const override { return std::hash<int>{}(xA + yA + xB + yB); }
	std::string GetParameters() const override { return std::to_string(xA) + " " + std::to_string(yA) + " " + std::to_string(xB) + " " + std::to_string(yB); }
private:
	int xA;
	int yA;
	int xB;
	int yB;
};

