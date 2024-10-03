#pragma once
#include "Shape.h"
class Parallelogram : public Shape
{
public:
	Parallelogram(const int InX0, const int InY0, const int InX1, const int InY1, const int InWidth) :
		width(InWidth), x0(InX0), y0(InY0), x1(InX1), y1(InY1) {}
	Parallelogram(const int InX0, const int InY0, const int InX1, const int InY1) :
		width(InX1 - InX0), x0(InX0), y0(InY0), x1(InX1), y1(InY1) {}
	~Parallelogram() = default;
	void Draw(Board& board) override;

	unsigned long long GetId() const override { return std::hash<int>{}(x0 + y0 + x1 + y1); }
	std::string GetParameters() const override { return std::to_string(x0) + " " + std::to_string(y0) + " " + std::to_string(x1) + " " + std::to_string(y1); }
private:
	int width, x0, y0, x1, y1;
};