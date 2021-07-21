#include "Board.h"
#include <assert.h>

Board::Board(size_t _width, size_t _height)
	:
width(_width),
height(_height)
{
	assert(width > 0 && height > 0); //If assertion fails: width or height is smaller than 1
	content.resize(width * height);
}

void Board::Draw(Vec2<int> topLeft, Graphics& gfx) const
{
	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			Block block = content[y * width + x];
			if (block.bExists) //Only bother drawing the block if it exists
			{
				Vec2<int> blockPos = topLeft + Vec2<int>(x * blockSize, y * blockSize);
				gfx.PutRect(blockPos,
					blockPos + blockSize,
					block.color,
					blockPadding);
			}
		}
	}
}

void Board::SetBlock(int x, int y, Color c)
{
	assert(x >= 0 && x < width); //If assertion fails: x or y is out of range
	assert(y >= 0 && y < height);
	content[y * width + x].Set(c);

}

void Board::Block::Set(Color c)
{
	color = c;
	bExists = true;
}
