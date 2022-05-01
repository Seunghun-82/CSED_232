#include <iostream>
#include "Block.h"

using namespace std;

#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
#define cRED "\x1b[31m"
#define cGREEN "\x1b[32m"
#define cYELLOW "\x1b[33m"
#define cBLUE "\x1b[34m"
#define cMAGENTA "\x1b[35m"
#define cCYAN "\x1b[36m"
#define cWHITE "\x1b[37m"
#define cRESET "\x1b[0m"

Block::Block()
{
	tempt_spin = 0;
	non_empty = false;
}

Block::Block(int x_, int y_, Color color_)
{
	x[0][1] = x_;
	y[0][1] = y_;
	color = color_;
	msg = "■";
	tempt_spin = 0;
	non_empty = true;
}

Block::Block(int x_, int y_, Color color_, string msg_)
{
	x[0][1] = x_;
	y[0][1] = y_;
	color = color_;
	msg = msg_;
	tempt_spin = 0;
}


Block Block::operator+(const Block& pt)
{
	Block tempt;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempt.x[i][j] = x[i][j] + pt.x[i][j];
			tempt.y[i][j] = y[i][j] + pt.y[i][j];
		}
	}
	return tempt;
}

void Block::display()
{
	for (int i = 0; i < 4; i++)
	{
		if(non_empty)
		{
			gotoxy(this->x[tempt_spin][i], this->y[tempt_spin][i]);
			if (color == RED) { cout << cRED << "■" << cRESET; }
			else if (color == GREEN) { cout << cGREEN << "■" << cRESET; }
			else if (color == YELLOW) { cout << cYELLOW << "■" << cRESET; }
			else if (color == BLUE) { cout << cBLUE << "■" << cRESET; }
			else if (color == MAGENTA) { cout << cMAGENTA << "■" << cRESET; }
			else if (color == CYAN) { cout << cCYAN << "■" << cRESET; }
			else if (color == WHITE) { cout << cWHITE << "■" << cRESET; }
			else { cout << "■"; }
		}
	}
	gotoxy(0, 23);
}

void Block::bottom_display()
{
	for (int i = 0; i < 4; i++)
	{
		if (non_empty)
		{
			gotoxy(this->x[tempt_spin][i], this->y[tempt_spin][i]);
			if (color == RED) { cout << cRED << "□" << cRESET; }
			else if (color == GREEN) { cout << cGREEN << "□" << cRESET; }
			else if (color == YELLOW) { cout << cYELLOW << "□" << cRESET; }
			else if (color == BLUE) { cout << cBLUE << "□" << cRESET; }
			else if (color == MAGENTA) { cout << cMAGENTA << "□" << cRESET; }
			else if (color == CYAN) { cout << cCYAN << "□" << cRESET; }
			else if (color == WHITE) { cout << cWHITE << "□" << cRESET; }
			else { cout << "□"; }
		}
	}
	gotoxy(0, 23);
}

void Block::next_display()
{
	for (int i = 0; i < 4; i++)
	{
		if (non_empty)
		{
			gotoxy((this->x[tempt_spin][i] + 9), this->y[tempt_spin][i]);
			if (color == RED) { cout << cRED << "■" << cRESET; }
			else if (color == GREEN) { cout << cGREEN << "■" << cRESET; }
			else if (color == YELLOW) { cout << cYELLOW << "■" << cRESET; }
			else if (color == BLUE) { cout << cBLUE << "■" << cRESET; }
			else if (color == MAGENTA) { cout << cMAGENTA << "■" << cRESET; }
			else if (color == CYAN) { cout << cCYAN << "■" << cRESET; }
			else if (color == WHITE) { cout << cWHITE << "■" << cRESET; }
			else { cout << "■"; }
		}
	}
	gotoxy(0, 23);
}

void Block::hold_display()
{
	for (int i = 0; i < 4; i++)
	{
		if (non_empty)
		{
			gotoxy(this->x[tempt_spin][i] + 16, this->y[tempt_spin][i]);
			if (color == RED) { cout << cRED << "■" << cRESET; }
			else if (color == GREEN) { cout << cGREEN << "■" << cRESET; }
			else if (color == YELLOW) { cout << cYELLOW << "■" << cRESET; }
			else if (color == BLUE) { cout << cBLUE << "■" << cRESET; }
			else if (color == MAGENTA) { cout << cMAGENTA << "■" << cRESET; }
			else if (color == CYAN) { cout << cCYAN << "■" << cRESET; }
			else if (color == WHITE) { cout << cWHITE << "■" << cRESET; }
			else { cout << "■"; }
		}
	}
	gotoxy(0, 23);
}

int Block::spin_clock(Frame game_frame[][20])
{
	int next_spin;
	next_spin = (tempt_spin + 1) % 4;
	if (next_spin < 0)
	{
		next_spin += 4;
	}
	if (is_it_hit_block(game_frame, next_spin) == false)
	{
		tempt_spin = next_spin;
		return -1;
	}
	else
	{
		if (next_spin == 0)
		{
			move_only_left();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				tempt_spin = next_spin;
				return -1;
			}
			else
			{
				move_down();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					tempt_spin = next_spin;
					return -1;
				}
				else
				{
					move_only_right();
					move_up();
					move_up();
					move_up();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						tempt_spin = next_spin;
						return -1;
					}
					else
					{
						move_only_left();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							tempt_spin = next_spin;
							return -1;
						}
						else
						{
							move_only_right();
							move_down();
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
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				tempt_spin = next_spin;
				return -1;
			}
			else
			{
				move_up();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					tempt_spin = next_spin;
					return -1;
				}
				else
				{
					move_only_right();
					move_down();
					move_down();
					move_down();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						tempt_spin = next_spin;
						return -1;
					}
					else
					{
						move_only_left();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							tempt_spin = next_spin;
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
		else if (next_spin == 2)
		{
			move_only_right();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				tempt_spin = next_spin;
				return -1;
			}
			else
			{
				move_down();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					tempt_spin = next_spin;
					return -1;
				}
				else
				{
					move_only_left();
					move_up();
					move_up();
					move_up();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						tempt_spin = next_spin;
						return -1;
					}
					else
					{
						move_only_right();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							tempt_spin = next_spin;
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
			move_only_right();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				tempt_spin = next_spin;
				return -1;
			}
			else
			{
				move_up();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					tempt_spin = next_spin;
					return -1;
				}
				else
				{
					move_only_left();
					move_down();
					move_down();
					move_down();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						tempt_spin = next_spin;
						return -1;
					}
					else
					{
						move_only_right();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							tempt_spin = next_spin;
							return -1;
						}
						else
						{
							move_only_left();
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

int Block::spin_counter_clock(Frame game_frame[][20])
{
	int next_spin;
	next_spin = (tempt_spin - 1) % 4;
	if (next_spin < 0)
	{
		next_spin += 4;
	}
	if (is_it_hit_block(game_frame, next_spin) == false)
	{
		tempt_spin = next_spin;
		return -1;
	}
	else
	{
		if (next_spin == 0)
		{
			move_only_right();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				tempt_spin = next_spin;
				return -1;
			}
			else
			{
				move_down();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					tempt_spin = next_spin;
					return -1;
				}
				else
				{
					move_only_left();
					move_up();
					move_up();
					move_up();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						tempt_spin = next_spin;
						return -1;
					}
					else
					{
						move_only_right();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							tempt_spin = next_spin;
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
		else if (next_spin == 1)
		{
			move_only_left();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				tempt_spin = next_spin;
				return -1;
			}
			else
			{
				move_up();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					tempt_spin = next_spin;
					return -1;
				}
				else
				{
					move_only_right();
					move_down();
					move_down();
					move_down();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						tempt_spin = next_spin;
						return -1;
					}
					else
					{
						move_only_left();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							tempt_spin = next_spin;
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
		else if (next_spin == 2)
		{
			move_only_left();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				tempt_spin = next_spin;
				return -1;
			}
			else
			{
				move_down();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					tempt_spin = next_spin;
					return -1;
				}
				else
				{
					move_only_right();
					move_up();
					move_up();
					move_up();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						tempt_spin = next_spin;
						return -1;
					}
					else
					{
						move_only_left();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							tempt_spin = next_spin;
							return -1;
						}
						else
						{
							move_only_right();
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
			move_only_right();
			if (is_it_hit_block(game_frame, next_spin) == false)
			{
				tempt_spin = next_spin;
				return -1;
			}
			else
			{
				move_up();
				if (is_it_hit_block(game_frame, next_spin) == false)
				{
					tempt_spin = next_spin;
					return -1;
				}
				else
				{
					move_only_left();
					move_down();
					move_down();
					move_down();
					if (is_it_hit_block(game_frame, next_spin) == false)
					{
						tempt_spin = next_spin;
						return -1;
					}
					else
					{
						move_only_right();
						if (is_it_hit_block(game_frame, next_spin) == false)
						{
							tempt_spin = next_spin;
							return -1;
						}
						else
						{
							move_only_left();
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

void Block::move_only_left()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			x[i][j]--;
		}
	}
	return;
}

void Block::move_only_right()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			x[i][j]++;
		}
	}
	return;
}

void Block::move_left(Frame game_frame[][20])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (x[tempt_spin][j] == 2)
			{
				return;
			}
		}
	}

	if (is_it_okay_move_left(game_frame) == false)
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			x[i][j]--;
		}
	}

	return;
}

void Block::move_right(Frame game_frame[][20])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (x[tempt_spin][j] == 11)
			{
				return;
			}
		}
	}

	if (is_it_okay_move_right(game_frame) == false)
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			x[i][j]++;
		}
	}

	return;
}

void Block::move_down()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			y[i][j]++;
		}
	}
}

void Block::setX_Y(int x_[][4], int y_[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			x[i][j] = x_[i][j];
			y[i][j] = y_[i][j];
		}
	}
}

void Block::move_up()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			y[i][j]--;
		}
	}
	return;
}

bool Block::is_it_hit_block(Frame game_frame[][20], int next_spin)
{
	for (int i = 0; i < 4; i++)
	{
		int tempt_x = x[next_spin][i];
		int tempt_y = y[next_spin][i];
		if (game_frame[tempt_x - 2][tempt_y - 2].get_empty() == true)
		{
			return true;
		}
		if (tempt_x > 11)
		{
			return true;
		}
		else if (tempt_x < 2)
		{
			return true;
		}
		else if (tempt_y > 21)
		{
			return true;
		}
	}

	return false;
}

bool Block::is_it_okay_move_up(Frame gameframe[][20])
{
	for (int i = 0; i < 4; i++)
	{
		if(y[tempt_spin][i] >= 22)
		{
			int tried = 0;
			bool comlete = true;
			while (y[tempt_spin][i] != 21)
			{
				move_up();
				tried++;
				if (is_it_hit_block(gameframe, tempt_spin) == true)
				{
					comlete = false;
					break;
				}
			}
			if (comlete == false)
			{
				for (int i = 0; i < tried; i++)
				{
					move_down();
				}
				return false;
			}
		}
	}
	return true;
}
bool Block::is_it_okay_move_left(Frame gameframe[][20])
{
	for (int i = 0; i < 4; i++)
	{
		int tempt_x = getX(tempt_spin, i);
		int tempt_y = getY(tempt_spin, i);
		if (gameframe[tempt_x - 3][tempt_y - 2].get_empty() == true)
		{
			return false;
		}
	}
	return true;
}

bool Block::is_it_okay_move_right(Frame gameframe[][20])
{
	for (int i = 0; i < 4; i++)
	{
		int tempt_x = getX(tempt_spin, i);
		int tempt_y = getY(tempt_spin, i);
		if (gameframe[tempt_x - 1][tempt_y - 2].get_empty() == true)
		{
			return false;
		}
	}
	return true;
}

bool Block::is_it_bottom(Frame gameframe[][20])
{
	int y_bottom[4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = y[tempt_spin][i] - 2; j < 20; j++)
		{
			if ((gameframe[x[tempt_spin][i] - 2][j].get_empty() == true))
			{
				y_bottom[i] = j + 2;
				break;
			}
			if (j == 19)
			{
				y_bottom[i] = 22;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (y[tempt_spin][i] == (y_bottom[i]))
		{
			return true;
		}
	}

	return false;

}

void Frame::show_frame(int score)
{
	system("clear");
	for (int j = 1; j <= 22; j++)
	{
		for (int i = 1; i <= 19; i++)
		{
			if (j == 1)
			{
				gotoxy(i, j);
				cout << "▦";
			}
			else if ((j >= 2 && j <= 6) || j == 9)
			{
				gotoxy(1, j);
				cout << "▦";
				gotoxy(12, j);
				cout << "▦";
				gotoxy(19, j);
				cout << "▦";
				if (j != 9)
				{
					gotoxy(26, j);
					cout << "▦";
				}
			}
			else if (j == 7 || j == 10)
			{
				gotoxy(1, j);
				cout << "▦";
				if (i >= 12 && i <= 19)
				{
					gotoxy(i, j);
					cout << "▦";
				}
			}
			else if (j == 8 || j == 9)
			{
				gotoxy(1, j);
				cout << "▦";
				gotoxy(12, j);
				cout << "▦";
				gotoxy(19, j);
				cout << "▦";
				if (j == 8)
				{
					gotoxy(13, 8);
					cout << "Score";
				}
			}
			else if (j >= 11 && j <= 22)
			{
				gotoxy(1, j);
				cout << "▦";
				gotoxy(12, j);
				cout << "▦";
				if (j == 22)
				{
					if (i >= 2 && i <= 11)
					{
						gotoxy(i, j);
						cout << "▦";
					}
				}
			}

		}
	}
	for (int i = 20; i < 27; i++)
	{
		gotoxy(i, 1);
		cout << "▦";
		gotoxy(i, 7);
		cout << "▦";
	}
	gotoxy(21, 5);
	cout << "HOLD";
	gotoxy(13, 9);
	cout << score;
	gotoxy(0, 23);
}

void Frame::display()
{
	for (int i = 0; i < 4; i++)
	{
		if (non_empty)
		{
			gotoxy(this->x, this->y);
			if (color == RED) { cout << cRED << "■" << cRESET; }
			else if (color == GREEN) { cout << cGREEN << "■" << cRESET; }
			else if (color == YELLOW) { cout << cYELLOW << "■" << cRESET; }
			else if (color == BLUE) { cout << cBLUE << "■" << cRESET; }
			else if (color == MAGENTA) { cout << cMAGENTA << "■" << cRESET; }
			else if (color == CYAN) { cout << cCYAN << "■" << cRESET; }
			else if (color == WHITE) { cout << cWHITE << "■" << cRESET; }
			else { cout << "■"; }
		}
		else
		{
			gotoxy(this->x, this->y);
			cout << " ";
		}
	}
	gotoxy(0, 23);
}