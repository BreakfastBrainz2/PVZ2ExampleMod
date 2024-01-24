#pragma once

#define GRID_TILE_WIDTH 64.0f

#define BOARD_START_POS 232.0f
#define BOARD_END_POS 776.0f

class Board
{
public:
	char pad_0000[148]; //0x0000
	int m_columnCount; //0x0094
	int m_rowCount; //0x0098
	char pad_009C[676]; //0x009C
	Rect m_lawnRect; //0x0340
};