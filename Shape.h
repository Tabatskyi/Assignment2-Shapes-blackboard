#pragma once
#include <string>

class Board;

class Shape
{
public:
	virtual ~Shape() = default;
	virtual void Draw(Board& board) = 0;

	virtual unsigned long long GetId() const = 0;
	virtual std::string GetParameters() const = 0;
};

