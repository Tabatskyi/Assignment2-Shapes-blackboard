#pragma once
#include "Shape.h"
class Parallelogram : public Shape
{
public:
	Parallelogram(const unsigned int InX0, const unsigned int InY0, const unsigned int InX1, const unsigned int Iny1, const unsigned int InWidth) :
		width(InWidth), x0(InX0), y0(InY0), x1(InX1), y1(Iny1) {}
	Parallelogram(const unsigned int InX0, const unsigned int InY0, const unsigned int InX1, const unsigned int Iny1) :
		width(InX0 - InX1), x0(InX0), y0(InY0), x1(InX1), y1(Iny1) {}
	~Parallelogram() = default;
	void Draw(Board& board) override;

	unsigned long long GetId() const override { return std::hash<unsigned int>{}(x0 + y0 + x1 + y1); }
	std::string GetParameters() const override { return std::to_string(x0) + " " + std::to_string(y0) + " " + std::to_string(x1) + " " + std::to_string(y1); }
private:
	unsigned int width;
	unsigned int x0;
	unsigned int y0;
	unsigned int x1;
	unsigned int y1;
};

