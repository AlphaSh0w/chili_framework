#pragma once
#include <vector>
#include "Colors.h"

//Represents the game board
class Board
{
public:
	Board(size_t width, size_t height);

private:
	//Represents the state of a block inside of the board
	class Block
	{
	public:
		Color color = Colors::Black;
		bool bExists = false;
	};

private:
	std::vector<Block> content;
	size_t width;
	size_t height;
};