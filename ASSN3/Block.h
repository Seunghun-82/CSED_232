#ifndef POINT_H
#define POINT_H
#include <string>

enum Color {
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
};

using namespace std;

class Frame
{
private:
	int x;
	int y;
	string msg;
	Color color;
	bool non_empty;

public:
	Frame() { non_empty = false; }
	int getX() { return x; }
	int getY() { return y; }
	bool get_empty() { return non_empty; }
	void setX_Y(int x_, int y_) { x = x_; y = y_; }
	void setMsg(string msg_) { msg = msg_[0]; }
	void setColor(Color color_) { color = color_; }
	Color getColor() const { return color; }
	void set_empty(bool empty_) { non_empty = empty_; }
	void show_frame(int score);
	void display();
};

class Block {
	private:
		int x[4][4];
		int y[4][4];
		string msg;
		Color color;
		int tempt_spin;
		bool non_empty;

	public :
		Block();
		Block(int, int, Color);
		Block(int, int, Color, string);
		int getX(int i, int j) {return x[i][j];}
		int getY(int i, int j) {return y[i][j];}
		bool get_empty(){ return non_empty; };
		int get_spin() { return tempt_spin; }
		virtual int spin_clock(Frame game_frame[][20]);
		virtual int spin_counter_clock(Frame game_frame[][20]);
		void move_left(Frame game_frame[][20]);
		void move_right(Frame game_frame[][20]);
		void move_down();
		void display();
		void bottom_display();
		void next_display();
		void hold_display();
		void set_empty(bool empty_) { non_empty = empty_; }
		void move_up();
		void move_only_left();
		void move_only_right();
		bool is_it_hit_block(Frame game_frame[][20], int next_spin);
		bool is_it_bottom(Frame gameframe[][20]);
		bool is_it_okay_move_left(Frame gameframe[][20]);
		bool is_it_okay_move_right(Frame gameframe[][20]);
		bool is_it_okay_move_up(Frame gameframe[][20]);
		string getMsg() {return msg;}
		Color getColor() const {return color;}
		void set_spin(int spin) { tempt_spin = spin; }
		void setX_Y(int x_[][4], int y_[][4]);
		void setMsg(string msg_) {msg = msg_[0];}
		void setColor(Color color_) {color = color_;}
		Block operator+(const Block &pt);
		virtual ~Block() {};
};
#endif
