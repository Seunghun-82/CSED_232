#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Block.h"
#include "tetrimino.h"
#include <fstream>

#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
int T_spin_check(int x, int y, int spin, Frame game_frame[][20]);
void display(Frame game_frame[][20]);
void game_start(Frame game_frame[][20], int& score);
int game_in_tetrimino(Frame game_frame[][20], int& score, Block block, Block shadow, Block next_block, Block& hold, int curr_index);
void fill_arry(int* store);
bool check_same(int* store, int tempt, int index);
int is_it_full(Frame game_frame[][20]);
void clear_frame(Frame game_frame[][20], int index);
void clear_next_field();

int main()
{

	bool game_restart = true;
	bool game_end = true;
	int index = 0;
	int* ary = new int[1];
	while (game_restart)
	{
		string restart;
		string record;
		int score = 0;
		Frame game_frame[10][20];
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				game_frame[i][j].setX_Y(i + 2, j + 2);
				game_frame[i][j].set_empty(false);
			}
		}
		game_start(game_frame, score);
		string trash;
		std::cout << "Press any key ";
		std::getline(cin, trash);

		while (!(record == "y" || record == "n"))
		{
			std::cout << "Do you want to save your score? (y/n) ";
			std::getline(cin, record);
		}
		while (!(restart == "y" || restart == "n"))
		{
			std::cout << "Do you want to restart? (y/n) ";
			std::getline(cin, restart);
		}
		if (record == "y")
		{
			index++;
			int* tempt = new int[index - 1];

			for (int i = 0; i < index - 1; i++)
			{
					tempt[i] = ary[i];
			}
			delete[] ary;
			int* ary = new int[index];
			for (int i = 0; i < index - 1; i++)
			{
				ary[i] = tempt[i];
			}
			delete[] tempt;
			ary[index - 1] = score;
		}

		if (restart == "n")
		{
			game_restart = false;
			break;
		}
	}
	ofstream outFile;
	outFile.open("score.txt", ios::app);
	for (int i = index; i > 0; i--)
	{
		outFile << ary[i - 1] << endl;
	}
	delete[] ary;

	return 0;
}

void game_start(Frame game_frame[][20], int& score)
{
	srand((int)time(NULL));
	int present_index = 0;
	int store_or_next = 0;
	int store[7] = { -1,-1,-1,-1,-1,-1,-1 };
	fill_arry(store);
	int next_store[7] = {-1,-1,-1,-1,-1,-1,-1};
	fill_arry(next_store);
	int check = 0;
	Block hold;
	int combo = 0;
	int back_to_back = 0;
	while (true)
	{
		if (present_index == 0 && store_or_next == 0)
		{
			fill_arry(next_store);
		}
		else if (present_index == 0 && store_or_next == 1)
		{
			fill_arry(store);
		}

		Block* blocks[7];
		blocks[0] = new tetrimino_I;
		blocks[1] = new tetrimino_T;
		blocks[2] = new tetrimino_O;
		blocks[3] = new tetrimino_Z;
		blocks[4] = new tetrimino_L;
		blocks[5] = new tetrimino_J;
		blocks[6] = new tetrimino_S;
		if (store_or_next == 0)
		{
			if (present_index < 6)
			{
				check = game_in_tetrimino(game_frame, score, *blocks[store[present_index]], *blocks[store[present_index]], *blocks[store[present_index + 1]], hold, store[present_index]);
			}
			else
			{
				check = game_in_tetrimino(game_frame, score, *blocks[store[present_index]], *blocks[store[present_index]], *blocks[next_store[0]], hold, store[present_index]);
			}
		}
		else if (store_or_next == 1)
		{
			if (present_index < 6)
			{
				check = game_in_tetrimino(game_frame, score, *blocks[next_store[present_index]], *blocks[next_store[present_index]], *blocks[next_store[present_index + 1]], hold, next_store[present_index]);
			}
			else
			{
				check = game_in_tetrimino(game_frame, score, *blocks[next_store[present_index]], *blocks[next_store[present_index]], *blocks[store[0]], hold, next_store[present_index]);
			}
		}
		present_index++;
		if (present_index == 7)
		{
			present_index = 0;
			if (store_or_next == 0)
			{
				store_or_next = 1;
			}
			else
			{
				store_or_next = 0;
			}
		}
		for (int i = 0; i < 7; i++)
		{
			delete blocks[i];
		}
		if (check == 1)
		{
			return;
		}
		else if (check == 2)
		{
			back_to_back++;
			if (back_to_back >= 2)
			{
				score = score + 200;
			}
		}
		else if (check == 3)
		{
			back_to_back = 0;
			combo = 0;
		}
		if (check == 2 || check == 0)
		{
			if (check == 0)
			{
				back_to_back = 0;
			}
			combo++;
			if (combo >= 2)
			{
				score = score + (100 + 10 * (combo - 1));
			}
		}
	}
}

int game_in_tetrimino(Frame game_frame[][20], int& score, Block block, Block shadow, Block next_block, Block& hold,int curr_index)
{
	game_frame[0][0].show_frame(score);
	bool shadow_bool = true;
	bool already_swap = true;
	int break_is = 0;
	char prev_key = 0;
	while (true)
	{
		int wall_kick = 0;
		if (break_is == 1)
		{
			game_frame[0][0].show_frame(score);
			break_is++;
		}

		while (block.is_it_hit_block(game_frame, block.get_spin()) == true)
		{
			block.move_up();
		}
		clock_t timer = clock();
		clock_t oneclick = clock();
		double time_limit = 1000;
		double key_limit = 150;
		if ((score / 1000) >= 1)
		{
			int tempt = score / 1000;
			time_limit = time_limit / double(double(1) + double(tempt * 0.1));
			key_limit = key_limit / double(double(1) + double(tempt * 0.03));
		}
		bool if_break = false;
		while (true)
		{
			shadow = block;
			while (!(shadow.is_it_bottom(game_frame)))
			{
				shadow.move_down();
			}
			shadow.move_up();
			if (hold.get_empty())
			{
				hold.hold_display();
			}
			display(game_frame);
			clear_next_field();
			next_block.next_display();
			if (shadow_bool == true)
			{
				shadow.bottom_display();
			}
			block.display();
			if ((double)(clock() - timer) > time_limit)
			{
				if_break = true;
				break;
			}
			if (GetAsyncKeyState(0x44) & 0x8000)
			{
				if (clock() - oneclick < 150)
				{
					continue;
				}
				oneclick = clock();
				block.move_right(game_frame);
				prev_key = 'd';
				break;
			}
			else if (GetAsyncKeyState(0x20) & 0x8000)
			{
				if (clock() - oneclick < 150)
				{
					continue;
				}
				oneclick = clock();
				while (!(block.is_it_bottom(game_frame)))
				{
					block.move_down();
				}		
				prev_key = ' ';
				break;
			}
			else if (GetAsyncKeyState(0x43) & 0x8000)
			{
				if (clock() - oneclick < 150)
				{
					continue;
				}
				oneclick = clock();
				prev_key = 'c';
				if (already_swap == true)
				{
					Block tempt = hold;
					hold = block;
					block = tempt;
					already_swap = false;
					hold.set_spin(0);
					while (!(hold.getX(0, 1) == 6))
					{
						if (hold.getX(0, 1) > 6)
						{
							hold.move_only_left();
						}
						else
						{
							hold.move_only_right();
						}
					}
					while (!(hold.getY(0, 1) == 3))
					{
						if (hold.getY(0, 1) > 3)
						{
							hold.move_up();
						}
						else
						{
							hold.move_down();
						}
					}
					if (block.get_empty() == false)
					{
						return 0;
					}
					else
					{
						break_is++;
						break;
					}
				}
			}
			else if (GetAsyncKeyState(0x57) & 0x8000)
			{
				if (clock() - oneclick < 150)
				{
					continue;
				}
				oneclick = clock();
				prev_key = 'w';
				if (curr_index == 1)
				{
					wall_kick = block.spin_clock(game_frame);
				}
				else
				{
					block.spin_clock(game_frame);
				}
				break;
			}
			else if (GetAsyncKeyState(0x41) & 0x8000)
			{
				if (clock() - oneclick < 150)
				{
					continue;
				}
				oneclick = clock();
				prev_key = 'a';
				block.move_left(game_frame);
				break;
			}
			else if (GetAsyncKeyState(0x53) & 0x8000)
			{
				if (clock() - oneclick < 150)
				{
					continue;
				}
				oneclick = clock();
				prev_key = 's';
				if (block.is_it_bottom(game_frame))
				{

				}
				else
				{
					block.move_down();
				}
				break;
			}
			else if (GetAsyncKeyState(0x58) & 0x8000)
			{
				if (clock() - oneclick < 150)
				{
					continue;
				}
				oneclick = clock();
				prev_key = 'x';
				if (curr_index == 1)
				{
					wall_kick = block.spin_counter_clock(game_frame);
				}
				else
				{
					block.spin_counter_clock(game_frame);
				}
				break;
			}
			else if (GetAsyncKeyState(0x4D) & 0x8000)
			{
				if (clock() - oneclick < 150)
				{
					continue;
				}
				oneclick = clock();
				prev_key = 'm';
				if (shadow_bool == true)
				{
					shadow_bool = false;
				}
				else
				{
					shadow_bool = true;
				}
				break;
			}
		}
		if (if_break == true)
		{
			if (block.is_it_bottom(game_frame))
			{

			}
			else 
			{
				block.move_down();
			}
		}

		if (block.is_it_bottom(game_frame))
		{
			for (int i = 0; i < 4; i++)
			{
				int x_, y_;
				x_ = block.getX(block.get_spin(), i);
				y_ = block.getY(block.get_spin(), i) - 1;
				if (y_ < 2)
				{
					return 1;
				}
				game_frame[x_ - 2][y_ - 2].setColor(block.getColor());
				game_frame[x_ - 2][y_ - 2].set_empty(true);
				game_frame[x_ - 2][y_ - 2].setX_Y(x_, y_);
			}

			int score_plus;
			if ((prev_key == 'w' || prev_key == 'x') && curr_index == 1)
			{
				int x, y, spin;
				spin = block.get_spin();
				x = block.getX(spin, 1);
				y = block.getY(spin, 1);
				int T_spin = T_spin_check(x - 2, y - 2, spin, game_frame);
				score_plus = is_it_full(game_frame);
				if (T_spin == 1)
				{
					if (score_plus == 1 && wall_kick == 0)
					{
						score = score + 500;
					}
					else if (score_plus == 1 && wall_kick == 1)
					{
						score = score + 100;
					}
					else if (score_plus == 2)
					{
						score = score + 1000;
					}
					else if (score_plus == 3)
					{
						score = score + 1500;
					}
					else if (score_plus == 0)
					{
						return 3;
					}
					return 2;
				}
				else
				{
					if (score_plus == 1)
					{
						score = score + 100;
					}
					else if (score_plus == 2)
					{
						score = score + 300;
					}
					else if (score_plus == 3)
					{
						score = score + 500;
					}
					else if (score_plus == 4)
					{
						score = score + 1000;
						return 2;
					}
					else if (score_plus == 0)
					{
						return 3;
					}

					return 0;
				}
			}
			else
			{
				score_plus = is_it_full(game_frame);
				if (score_plus == 1)
				{
					score = score + 100;
				}
				else if (score_plus == 2)
				{
					score = score + 300;
				}
				else if (score_plus == 3)
				{
					score = score + 500;
				}
				else if (score_plus == 4)
				{
					score = score + 1000;
					return 2;
				}
				else if (score_plus == 0)
				{
					return 3;
				}
				return 0;
			}
		}
	}
}

int T_spin_check(int x, int y, int spin, Frame game_frame[][20])
{
	int check;
	if (x == 0 || x == 9)
	{
		check = check + 2;
		if (x == 0)
		{
			if (game_frame[x + 1][y - 1].get_empty() == true)
				check++;
			if (game_frame[x + 1][y + 1].get_empty() == true)
				check++;
		}
		else
		{
			if (game_frame[x - 1][y - 1].get_empty() == true)
				check++;
			if (game_frame[x - 1][y + 1].get_empty() == true)
				check++;
		}
	}
	else
	{
		if (y == 19)
		{
			if (game_frame[x + 1][y - 1].get_empty() == true)
				check++;
			if (game_frame[x - 1][y - 1].get_empty() == true)
				check++;
		}
		else
		{
			if (game_frame[x + 1][y - 1].get_empty() == true)
				check++;
			if (game_frame[x + 1][y + 1].get_empty() == true)
				check++;
			if (game_frame[x - 1][y - 1].get_empty() == true)
				check++;
			if (game_frame[x - 1][y + 1].get_empty() == true)
				check++;
		}
	}

	if (check == 4 || check == 3)
		return 1;
	else if (check == 2 && spin == 2)
		return 1;
	else
		return 0;

 }

int is_it_full(Frame game_frame[][20])
{
	int clear_num = 0;
	for (int i = 19; i >= 0; i--)
	{
		int check = 0;
		for (int j = 0; j < 10; j++)
		{
			if (game_frame[j][i].get_empty() == true)
			{
				check++;
			}
		}
		if (check == 10)
		{
			clear_frame(game_frame, i);
			clear_num++;
			i++;
		}
	}
	return clear_num;
}

void clear_next_field()
{
	for (int i = 13; i < 19; i++)
	{
		for (int j = 2; j < 7; j++)
		{
			gotoxy(i, j);
			cout << " ";
		}
	}
	for (int i = 20; i < 25; i++)
	{
		for (int j = 2; j < 4; j++)
		{
			gotoxy(i, j);
			cout << " ";
		}
	}
	return;
}

void clear_frame(Frame game_frame[][20], int index)
{
	for (int i = index; i > 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			game_frame[j][i].setColor(game_frame[j][i - 1].getColor());
			game_frame[j][i].set_empty(game_frame[j][i - 1].get_empty());
		}
	}
	for (int i = 0; i < 10; i++)
	{
		game_frame[i][0].set_empty(false);
	}

	return;
}

void display(Frame game_frame[][20])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			game_frame[i][j].display();
		}
	}

	return;
}

void fill_arry(int* store)
{
	for (int i = 0; i < 7; i++)
	{
		int index = i;
		int tempt = rand() % 7;
		cout << store[i] << endl;
		if (!(check_same(store, tempt, index)))
		{
			store[i] = tempt;
		}
		else
		{
			i--;
		}
	}
}

bool check_same(int* store, int tempt, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (tempt == store[i])
		{
			return true;
		}
	}

	return false;

}