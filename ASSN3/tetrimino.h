#include <string>
#include "Block.h"

class tetrimino_I : public Block
{
	public:
		tetrimino_I();
		int spin_clock(Frame game_frame[][20]);
		int spin_counter_clock(Frame game_frame[][20]);
};

class tetrimino_O : public Block
{
	public:
		tetrimino_O();
};

class tetrimino_T : public Block
{
	public:
		tetrimino_T();
		int spin_clock(Frame game_frame[][20]);
		int spin_counter_clock(Frame game_frame[][20]);
};

class tetrimino_L : public Block
{
	public:
		tetrimino_L();
};

class tetrimino_J : public Block
{
	public:
		tetrimino_J();
};

class tetrimino_S : public Block
{
	public:
		tetrimino_S();
};

class tetrimino_Z : public Block
{
	public:
		tetrimino_Z();
};