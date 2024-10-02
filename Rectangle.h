#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
public:
	Rectangle(const unsigned int InWidth, const unsigned int InHeight, const unsigned int InX, const unsigned int InY) : width(InWidth), height(InHeight), x(InX), y(InY) {}
	~Rectangle() = default;
	void Draw(Board& board) override;

	unsigned long long GetId() const override { return std::hash<unsigned int>{}(width + height + x + y); }
	std::string GetParameters() const override { return std::to_string(width) + " " + std::to_string(height) + " " + std::to_string(x) + " " + std::to_string(y); }
private:
	unsigned int width;
	unsigned int height;
	unsigned int x;
	unsigned int y;
};

