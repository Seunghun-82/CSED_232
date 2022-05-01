#include "tetrimino.h"
#include "Block.h"
#include <string>
#include <iostream>

using namespace std;
tetrimino_I::tetrimino_I()
{
	int x[4][4] = { {5,6,7,8},{7,7,7,7},{5,6,7,8},{6,6,6,6} };
	int y[4][4] = { {3,3,3,3},{2,3,4,5},{4,4,4,4},{2,3,4,5} };
	set_spin(0);
	setMsg("бс");
	setX_Y(x, y);
	setColor(CYAN);
	set_empty(true);
}

int tetrimino_I::spin_clock(Frame game_frame[][20])
{
	int next_spin;
	next_spin = (get_spin() + 1) % 4;
	if (next_spin < 0)
	{
		next_spin += 4;
	}
	if (is_it_hit_block(game_frame, next_spin) == false)
	{
		set_spin(next_spin);
		return -1;
	}
	else
	{
		if (next_spin == 0)
		{
			move_only_right();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return -1;
			}
			else
			{
				move_only_left();
				move_only_left();
				move_only_left();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return -1;
				}
				else
				{
					move_only_right();
					move_only_right();
					move_only_right();
					move_down();
					move_down();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return -1;
					}
					else
					{
						move_only_left();
						move_only_left();
						move_only_left();
						move_up();
						move_up();
						move_up();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return -1;
						}
						else
						{
							move_only_right();
							move_only_right();
							move_down();
							return -1;
						}
					}
				}
			}
		}
		else if (next_spin == 1)
		{
			move_only_left();
			move_only_left();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return -1;
			}
			else
			{
				move_only_right();
				move_only_right();
				move_only_right();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return -1;
				}
				else
				{
					move_only_left();
					move_only_left();
					move_only_left();
					move_down();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return -1;
					}
					else
					{
						move_only_right();
						move_only_right();
						move_only_right();
						move_up();
						move_up();
						move_up();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return -1;
						}
						else
						{
							move_only_left();
							move_down();
							move_down();
							return -1;
						}
					}
				}
			}
		}
		else if (next_spin == 2)
		{
			move_only_left();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return -1;
			}
			else
			{
				move_only_right();
				move_only_right();
				move_only_right();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return -1;
				}
				else
				{
					move_only_left();
					move_only_left();
					move_only_left();
					move_up();
					move_up();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return -1;
					}
					else
					{
						move_only_right();
						move_only_right();
						move_only_right();
						move_down();
						move_down();
						move_down();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return -1;
						}
						else
						{
							move_only_left();
							move_only_left();
							move_up();
							return -1;
						}
					}
				}
			}
		}
		else if (next_spin == 3)
		{
			move_only_right();
			move_only_right();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return -1;
			}
			else
			{
				move_only_left();
				move_only_left();
				move_only_left();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return -1;
				}
				else
				{
					move_only_right();
					move_only_right();
					move_only_right();
					move_up();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return -1;
					}
					else
					{
						move_only_left();
						move_only_left();
						move_only_left();
						move_down();
						move_down();
						move_down();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return -1;
						}
						else
						{
							move_only_right();
							move_up();
							move_up();
							return -1;
						}
					}
				}
			}
		}
	}
	return -1;
}

int tetrimino_I::spin_counter_clock(Frame game_frame[][20])
{
	int next_spin;
	next_spin = (get_spin() - 1) % 4;
	if (next_spin < 0)
	{
		next_spin += 4;
	}
	if (is_it_hit_block(game_frame, next_spin) == false)
	{
		set_spin(next_spin);
		return -1;
	}
	else
	{
		if (next_spin == 0)
		{
			move_only_right();
			move_only_right();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return -1;
			}
			else
			{
				move_only_left();
				move_only_left();
				move_only_left();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return -1;
				}
				else
				{
					move_only_right();
					move_only_right();
					move_only_right();
					move_up();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return -1;
					}
					else
					{
						move_only_left();
						move_only_left();
						move_only_left();
						move_down();
						move_down();
						move_down();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return -1;
						}
						else
						{
							move_only_right();
							move_up();
							move_up();
							return -1;
						}
					}
				}
			}
		}
		else if (next_spin == 1)
		{
			move_only_right();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return -1;
			}
			else
			{
				move_only_left();
				move_only_left();
				move_only_left();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return -1;
				}
				else
				{
					move_only_right();
					move_only_right();
					move_only_right();
					move_down();
					move_down();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return -1;
					}
					else
					{
						move_only_left();
						move_only_left();
						move_only_left();
						move_up();
						move_up();
						move_up();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return -1;
						}
						else
						{
							move_only_right();
							move_only_right();
							move_down();
							return -1;
						}
					}
				}
			}
		}
		else if (next_spin == 2)
		{
			move_only_left();
			move_only_left();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return -1;
			}
			else
			{
				move_only_right();
				move_only_right();
				move_only_right();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return -1;
				}
				else
				{
					move_only_left();
					move_only_left();
					move_only_left();
					move_down();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return -1;
					}
					else
					{
						move_only_right();
						move_only_right();
						move_only_right();
						move_up();
						move_up();
						move_up();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return -1;
						}
						else
						{
							move_only_left();
							move_down();
							move_down();
							return -1;
						}
					}
				}
			}
		}
		else if (next_spin == 3)
		{
			move_only_left();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return -1;
			}
			else
			{
				move_only_right();
				move_only_right();
				move_only_right();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return -1;
				}
				else
				{
					move_only_left();
					move_only_left();
					move_only_left();
					move_up();
					move_up();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return -1;
					}
					else
					{
						move_only_right();
						move_only_right();
						move_only_right();
						move_down();
						move_down();
						move_down();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return -1;
						}
						else
						{
							move_only_left();
							move_only_left();
							move_up();
							return -1;
						}
					}
				}
			}
		}
	}
	return -1;
}

tetrimino_O::tetrimino_O()
{
	int x[4][4] = { {6,6,7,7},{6,6,7,7},{6,6,7,7},{6,6,7,7} };
	int y[4][4] = { {2,3,3,2},{2,3,3,2},{2,3,3,2},{2,3,3,2} };
	set_spin(0);
	setX_Y(x, y);
	setMsg("бс");
	setColor(YELLOW);
	set_empty(true);
}

tetrimino_T::tetrimino_T()
{
	int x[4][4] = { {6,6,5,7},{6,6,6,7},{5,6,7,6},{6,6,6,5} };
	int y[4][4] = { {2,3,3,3},{2,3,4,3},{3,3,3,4},{2,3,4,3} };
	set_spin(0);
	setX_Y(x, y);
	setMsg("бс");
	setColor(MAGENTA);
	set_empty(true);
}

int tetrimino_T::spin_clock(Frame game_frame[][20])
{
	int next_spin;
	next_spin = (get_spin() + 1) % 4;
	if (next_spin < 0)
	{
		next_spin += 4;
	}
	if (is_it_hit_block(game_frame, next_spin) == false)
	{
		set_spin(next_spin);
		return 0;
	}
	else
	{
		if (next_spin == 0)
		{
			move_only_left();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return 1;
			}
			else
			{
				move_down();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return 1;
				}
				else
				{
					move_only_right();
					move_up();
					move_up();
					move_up();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return 1;
					}
					else
					{
						move_only_left();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return 1;
						}
						else
						{
							move_only_right();
							move_down();
							move_down();
							return 0;
						}
					}
				}
			}
		}
		else if (next_spin == 1)
		{
			move_only_left();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return 1;
			}
			else
			{
				move_up();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return 1;
				}
				else
				{
					move_only_right();
					move_down();
					move_down();
					move_down();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return 1;
					}
					else
					{
						move_only_left();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return 1;
						}
						else
						{
							move_only_right();
							move_up();
							move_up();
							return 0;
						}
					}
				}
			}
		}
		else if (next_spin == 2)
		{
			move_only_right();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return 1;
			}
			else
			{
				move_down();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return 1;
				}
				else
				{
					move_only_left();
					move_up();
					move_up();
					move_up();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return 1;
					}
					else
					{
						move_only_right();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return 1;
						}
						else
						{
							move_only_left();
							move_down();
							move_down();
							return 0;
						}
					}
				}
			}
		}
		else if (next_spin == 3)
		{
			move_only_right();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return 1;
			}
			else
			{
				move_up();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return 1;
				}
				else
				{
					move_only_left();
					move_down();
					move_down();
					move_down();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return 1;
					}
					else
					{
						move_only_right();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return 1;
						}
						else
						{
							move_only_left();
							move_up();
							move_up();
							return 0;
						}
					}
				}
			}
		}
	}
	return 0;
}

int tetrimino_T::spin_counter_clock(Frame game_frame[][20])
{
	int next_spin;
	next_spin = (get_spin() - 1) % 4;
	if (next_spin < 0)
	{
		next_spin += 4;
	}
	if (is_it_hit_block(game_frame, next_spin) == false)
	{
		set_spin(next_spin);
		return 0;
	}
	else
	{
		if (next_spin == 0)
		{
			move_only_right();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return 1;
			}
			else
			{
				move_down();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return 1;
				}
				else
				{
					move_only_left();
					move_up();
					move_up();
					move_up();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return 1;
					}
					else
					{
						move_only_right();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return 1;
						}
						else
						{
							move_only_left();
							move_down();
							move_down();
							return 0;
						}
					}
				}
			}
		}
		else if (next_spin == 1)
		{
			move_only_left();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return 1;
			}
			else
			{
				move_up();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return 1;
				}
				else
				{
					move_only_right();
					move_down();
					move_down();
					move_down();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return 1;
					}
					else
					{
						move_only_left();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return 1;
						}
						else
						{
							move_only_right();
							move_up();
							move_up();
							return 0;
						}
					}
				}
			}
		}
		else if (next_spin == 2)
		{
			move_only_left();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return 1;
			}
			else
			{
				move_down();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return 1;
				}
				else
				{
					move_only_right();
					move_up();
					move_up();
					move_up();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return 1;
					}
					else
					{
						move_only_left();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return 1;
						}
						else
						{
							move_only_right();
							move_down();
							move_down();
							return 0;
						}
					}
				}
			}
		}
		else if (next_spin == 3)
		{
			move_only_right();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				set_spin(next_spin);
				return 1;
			}
			else
			{
				move_up();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					set_spin(next_spin);
					return 1;
				}
				else
				{
					move_only_left();
					move_down();
					move_down();
					move_down();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						set_spin(next_spin);
						return 1;
					}
					else
					{
						move_only_right();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							set_spin(next_spin);
							return 1;
						}
						else
						{
							move_only_left();
							move_up();
							move_up();
							return 0;
						}
					}
				}
			}
		}
	}
	return 0;
}


tetrimino_L::tetrimino_L()
{
	int x[4][4] = { {5,6,7,7},{6,6,6,7},{5,6,7,5},{6,6,6,5} };
	int y[4][4] = { {3,3,3,2},{2,3,4,4},{3,3,3,4},{2,3,4,2} };
	set_spin(0);
	setX_Y(x, y);
	setMsg("бс");
	setColor(WHITE);
	set_empty(true);
}

tetrimino_J::tetrimino_J()
{
	int x[4][4] = { {5,6,5,7},{6,6,6,7},{5,6,7,7},{6,6,6,5} };
	int y[4][4] = { {2,3,3,3},{2,3,4,2},{3,3,3,4},{2,3,4,4} };
	set_spin(0);
	setX_Y(x, y);
	setMsg("бс");
	setColor(BLUE);
	set_empty(true);
}

tetrimino_S::tetrimino_S()
{
	int x[4][4] = { {6,6,7,5},{6,6,7,7},{6,7,6,5},{5,5,6,6} };
	int y[4][4] = { {2,3,2,3},{2,3,3,4},{3,3,4,4},{2,3,3,4} };
	set_spin(0);
	setX_Y(x, y);
	setMsg("бс");
	setColor(GREEN);
	set_empty(true);
}

tetrimino_Z::tetrimino_Z()
{
	int x[4][4] = { {5,6,6,7},{6,6,7,7},{5,6,6,7},{5,5,6,6} };
	int y[4][4] = { {2,3,2,3},{3,4,2,3},{3,3,4,4},{3,4,3,2} };
	set_spin(0);
	setX_Y(x, y);
	setMsg("бс");
	setColor(RED);
	set_empty(true);
}