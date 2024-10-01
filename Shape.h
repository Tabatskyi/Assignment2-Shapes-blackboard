#pragma once

class Board;

class Shape
{
public:
	virtual ~Shape() = default;
	virtual void Draw(Board& board) = 0;
};

