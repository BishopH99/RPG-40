//Fill out this comment with your names and which bullet points you did
//Partners: Hockman, Tipton, Feagin, Grewal
//Bullet Points:
//Extra Credit:
//URL to cover art and music:
#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> world_map = { //FIXME: finish the world map
	"*************************************************************************************************************************",
	"* r   |                                                                                                                 *",
	"*  s  |                                                                                                              d  *",
	"*     |                                                                                                                 *",
	"*   x ---                                                                                                               *",
	"*        z                                                                                                              *",
	"*      g                                                                                                                *",
	"* d                                                                                                                     *",
	"*    s r                                                                                                                *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*                                                                                                                       *",
	"*************************************************************************************************************************",
};

char get_world_location(size_t row, size_t col) {
	if (row >= world_map.size()) return ' ';
	if (col >= world_map.at(row).size()) return ' ';
	return world_map.at(row).at(col);
}

void set_world_location(size_t row, size_t col, char c) {
	if (row >= world_map.size()) return;
	if (col >= world_map.at(row).size()) return;
	world_map.at(row).at(col) = c;
}

void print_world(size_t player_row, size_t player_col) {
	const auto [ROWS, COLS] = get_terminal_size();
	int x = COLS / 2;
	int y = ROWS / 2;
	clearscreen();
	movecursor(y, x);
	for (size_t row = 0; row < world_map.size(); row++) {
		for (size_t col = 0; col < world_map.at(row).size(); col++) {
			if (row == player_row and col == player_col) cout << '@';
			else
				cout << world_map.at(row).at(col);
		}
		cout << endl;
	}
}
/*  FIXME:code needed to add map to the game. (NOT ALL OF IT WORKS, IM FIGURING OUT HOW TO INTEGRATE IT TO OUR CODE)

        if (get_world_location(row, col) == 'r') {
            set_world_location(row, col, ' ');
            movecursor(ROWS + 2, 0);
            cout << "You picked up a radish!\n";
        }
        if (get_world_location(row, col) == 'z') {
            movecursor(ROWS + 2, 0);
            cout << "YOU WIN!!!!!!!!!^G^G^G\n";
            usleep(2'000'000);
            break;
        }
        if (c == ERR) usleep(1'000'000 / FPS);
    }
    set_raw_mode(false);
    show_cursor(true);
    movecursor(0, 0);
    clearscreen();
*/
int main() {

	const auto [ROWS, COLS] = get_terminal_size(); //How big the screen
	const int world_ROWS = world_map.size();
	const int world_COLS = world_map.at(0).size();
	const int FPS = 60;
	int world_row = world_ROWS / 2, world_col = world_COLS / 2;
	int last_row = -1, last_col = -1;
	int x = COLS / 2;
	int y = ROWS / 2;

	set_cursor_mode(false);
	movecursor(y, x - 18);
	clearscreen();
	set_raw_mode(true);
	show_cursor(false);
	while (true) {
		int ch = quick_read();
		cout << "🤴 Welcome To The Coding Crusade 👸" << endl;
		cout << endl;
		movecursor(y + 1, x - 18);
		cout << "     press any key to continue" << endl;
		if (cin.get()) break;
	}
	set_raw_mode(false);
	clearscreen();
	movecursor(0, 0);
	//Move a monster on screen.
	//FIXME:add world map to game
	setcolor(53, 97, 43);
	set_raw_mode(true); //Nonblocking I/O
	while (true) {
		int ch = toupper(quick_read()); //Read from the keyboard
		if (ch == 'Q') break;
		if (ch == UP_ARROW or ch == 'W') y--;
		if (ch == DOWN_ARROW or ch == 'S') y++;
		if (ch == LEFT_ARROW or ch == 'A') x--;
		if (ch == RIGHT_ARROW or ch == 'D') x++;
		if (!(world_row == last_row and world_col == last_col)) { //checking movement
			print_world(world_row, world_col); //redraw map
			last_row = world_row;
			last_col = world_col;
			y = clamp(y, 0, ROWS - 2);
			x = clamp(x, 0, COLS - 2);
			movecursor(y, x);
			cout << "🐰" << endl;
		}
		//clean up after yourself
		set_raw_mode(false);
		resetcolor();
		show_cursor(true);
		movecursor(0, 0);
		clearscreen();
	}
}
