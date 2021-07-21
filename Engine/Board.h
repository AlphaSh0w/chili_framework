#pragma once
#include <vector>
#include "Colors.h"
#include "Vec2.h"
#include "Graphics.h"
//Represents the game board
class Board
{
public:
	Board(size_t width, size_t height);
	void Draw(Vec2<int> topLeft, Graphics& gfx) const;
	void SetBlock(int x, int y, Color c);
private:
	//Represents the state of a block inside of the board
	class Block
	{
	public:
		void Set(Color c);
	public:
		Color color = Colors::Black;
		bool bExists = false;
	};

private:
	std::vector<Block> content;
	size_t width;
	size_t height;
	static constexpr int blockSize = 20; //The size of each block in pixels
	static constexpr int blockPadding = 2;
};