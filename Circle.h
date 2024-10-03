#pragma once
#include "Board.h"

class Circle : public Shape
{
public:
	Circle(const unsigned int InRadius, const unsigned int InX, const unsigned int InY) : radius(InRadius), x(InX), y(InY) {}
	~Circle() = default;
	void Draw(Board& board) override;

	unsigned long long GetId() const override { return std::hash<unsigned int>{}(radius + x + y); }
	std::string GetParameters() const override { return std::to_string(radius) + " " + std::to_string(x) + " " + std::to_string(y); }
private:
	int radius;
	unsigned int x, y;
};