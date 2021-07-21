#include "Board.h"
#include <assert.h>

Board::Board(size_t _width, size_t _height)
	:
width(_width),
height(_height)
{
	assert(width > 0 && height > 0);
	content.resize(width * height);
}

