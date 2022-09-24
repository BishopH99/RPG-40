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

//Global Variable - accessible in all functions below
vector<string> world_map = {
	"*******************************************************************************",
	"*     ___________           _________________________                         *",
	"*    //_________\\\\      ___/                         \\_________________       *",
	"*     |   ___   |______/                                               \\      *",
	"*     |  |   |  |                 ___________                           \\     *",
	"*     |  |___|  |______          /           \\         ___________       \\    *",
	"*     |         |      \\        |    ___      \\        \\          \\      |    *",
	"*     |__SMITH__|       |       |   /   \\______\\        \\         |______|    *",
	"*                       |       |  |     <_______        |        /______\\    *",
	"*______________________/        |   \\___/        \\       |        |      |    *",
	"*                               |   WELL         |       |        |      |    *",
	"*                               |                |       |        |STABLE|    *",
	"*                               |   _____        |       |       _____        *",
	"*______        ________         |  /     \\       |       |      /     \\_______*",
	"*      \\      /        \\        |_/       \\      |       |     |              *",
	"*      |      |         |                  \\     |       |     |     _________*",
	"*      |______|         |            |?|   |     |        \\_____\\  /          *",
	"*    _//      \\\\_       |            | |   |     |              |  |          *",
	"*   //__________\\\\      |        _         /     |              |  |EVIL KING *",
	"*    |   ____   |       |       | \\       /      |              |  |  CASTLE  *",
	"*    |  |    |  |       |       |  \\_____/        \\_____________|  |          *",
	"*    |  |____|  |      /       /                                /  \\__________*",
	"*    |          |     /       /                                |              *",
	"*    |__TAVERN__|    /       /                                 |       _______*",
	"*                    |       |                                  \\_____/       *",
	"*                    |       |                                                *",
	"*******************************************************************************",
};
vector<string> well_map = {
	"******************************",
	"*   |_|                      *",
	"*   |_|                      *",
	"*   |_|     ___      ___     *",
	"*   |_|    |   |    |   |    *",
	"*   |_|    |___|    |___|    *",
	"*   |_|                      *",
	"*   |_|                      *",
	"*   |_|                      *",
	"*___|_|________________H____ *",
	"*                            *",
	"*                            *",
	"******************************",
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
	clearscreen();
	movecursor(0, 0);
	for (size_t row = 0; row < world_map.size(); row++) {
		for (size_t col = 0; col < world_map.at(row).size(); col++) {
			if (row == player_row and col == player_col) cout << "@";
			else
				cout << world_map.at(row).at(col);
		}
		cout << endl;
	}
}

char get_well_location(size_t row, size_t col) {
	if (row >= well_map.size()) return ' ';
	if (col >= well_map.at(row).size()) return ' ';
	return well_map.at(row).at(col);
}

void set_well_location(size_t row, size_t col, char c) {
	if (row >= well_map.size()) return;
	if (col >= well_map.at(row).size()) return;
	well_map.at(row).at(col) = c;
}


void print_well(size_t player_row, size_t player_col) {
	clearscreen();
	movecursor(0, 0);
	for (size_t row = 0; row < well_map.size(); row++) {
		for (size_t col = 0; col < well_map.at(row).size(); col++) {
			if (row == player_row and col == player_col) cout << "@";
			else
				cout << well_map.at(row).at(col);
		}
		cout << endl;
	}
}


int main() {
	const int ROWS = world_map.size();
	const int COLS = world_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES
	const int FPS = 60;
	int quest_accepted = 0;
	int well_entrance = 0;
	int Health = 50;
	int row = ROWS / 2, col = COLS / 2;
	int last_row = -1, last_col = -1; //Save our last position so we only redraw on update
	set_raw_mode(true);
	show_cursor(false);
	while (true) {
		int c = toupper(quick_read());
		if (c == 'Q') break;
		if (c == 'W' or c == UP_ARROW) row--;
		if (c == 'S' or c == DOWN_ARROW) row++;
		if (c == 'A' or c == LEFT_ARROW) col--;
		if (c == 'D' or c == RIGHT_ARROW) col++;
		row = clamp(row, 1, ROWS - 2);
		col = clamp(col, 1, COLS - 2);
		if (!(row == last_row and col == last_col)) { //If we moved...
			print_world(row, col); //...redraw the map
			last_row = row;
			last_col = col;
			movecursor(2, COLS + 5);
			cout << BLUE << "ROW: " << row << RED << " COL: " << col << RESET;
			movecursor(5, COLS + 5);
			cout << RED  << "HP: " << WHITE << Health << endl; //FIXME: add color indictors to the HP
			movecursor(8, COLS + 5);
			cout << "Quest Tracker: " << quest_accepted;
			movecursor(ROWS + 2, 0);
			setcolor(255, 0, 0);
			cout << "Welcome to the EVIL KING RECURSION'S DOMAIN\n";
			resetcolor();
			movecursor(ROWS + 4, 0);
			cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel\n";
			movecursor(ROWS + 5, 0);
			cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?)\n";
			movecursor(ROWS + 6, 0);
			cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
			movecursor(17, 39);
			cout << BOLDYELLOW << "?";
			movecursor(24, 9);
			cout << BOLDYELLOW << "TAVERN";
			movecursor(8, 10);
			cout << BOLDYELLOW << "SMITH";
			movecursor(11, 37);
			cout << BOLDYELLOW << "WELL";
			movecursor(12, 68);
			cout << BOLDYELLOW << "STABLE";
			movecursor(19, 69);
			cout << BOLDYELLOW << "EVIL";
			movecursor(19, 74);
			cout << BOLDYELLOW << "KING";
			movecursor(20, 71);
			cout << BOLDYELLOW << "CASTLE";
			movecursor(17, 9);
			cout << BOLDYELLOW << "______";
			movecursor(5, 17);
			cout << BOLDYELLOW << "|";
			movecursor(6, 17);
			cout << BOLDYELLOW << "|";
			movecursor(9, 42);
			cout << BOLDYELLOW << "|";
			movecursor(8, 68);
			cout << BOLDYELLOW << "______";
			movecursor(18, 65);
			cout << BOLDYELLOW << "|";
			movecursor(19, 65);
			cout << BOLDYELLOW << "|";
			movecursor(20, 65);
			cout << BOLDYELLOW << "|";
			movecursor(21, 65);
			cout << BOLDYELLOW << "|";
			if (quest_accepted > 0) {
				movecursor(17, 39);
				cout << BOLDBLACK << "?";
			}
			resetcolor();
			cout.flush();
		}
		if (get_world_location(row, col) == '<') {
			movecursor(ROWS + 8, 0);
			cout << "Do you want to enter the well? (Y/N)\n";
			if (c == 'Y') {
				well_entrance++;
				break;
			}
		}
		if (get_world_location(row, col) == '?') {
			movecursor(ROWS + 8, 0);
			cout << "There is a help request on the town board\n";
			cout.flush();
			movecursor(ROWS + 9, 0);
			cout << "     do you wish to read it? (Y/N)\n";
			if (c == 'Y') {
				cout << RESET;
				movecursor(ROWS + 11, 0);
				cout << "The request says someone lost their cat around the stables\n";
				movecursor(ROWS + 12, 0);
				cout << "Do you want to accept the request from the villager? (Y/N)\n";
				if (c == 'Y') {
					set_world_location(row, col, ' ');
					quest_accepted++;
					continue;
				}
			}
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
	set_raw_mode(true);
	show_cursor(false);
	while (true) {
		const int ROWS = well_map.size();
		const int COLS = well_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES
		const int FPS = 60;
		int row = ROWS / 2, col = COLS / 2;
		int last_row = -1, last_col = -1; //Save our last position so we only redraw on update
		while (well_entrance == 1) {
			int c = toupper(quick_read());
			if (c == 'Q') break;
			if (c == 'W' or c == UP_ARROW) row--;
			if (c == 'S' or c == DOWN_ARROW) row++;
			if (c == 'A' or c == LEFT_ARROW) col--;
			if (c == 'D' or c == RIGHT_ARROW) col++;
			row = clamp(row, 1, ROWS - 2);
			col = clamp(col, 1, COLS - 2);
			if (!(row == last_row and col == last_col)) { //If we moved...
				print_well(row, col); //...redraw the map
				last_row = row;
				last_col = col;
			}
		}
		resetcolor();
		cout.flush();
	}
	/*
	   cout << "Please enter a row and column" << endl;
	   int row, col;
	   cin >> row >> col;
	   if (world_map.at(row).at(col) == '*') cout << "There is a wall there.\n";

	//A vector is a data structure, "Something that holds multiple variables"
	//Syntax: vector<type of thing to hold> name of the vector(size of the vector)
	vector<int> help = {1,2,3,4,50};
	//Print the contents of help:
	for (int x : help) cout << x << endl;

	//This just made 40 integers, within a vector named help
	for (size_t i = 0; i < help.size(); i++) {
	cout << "Please enter the value for help.at(" << i << ")\n";
	cin >> help.at(i);
	}
	cout << "Here is the help vector!\n";
	for (int x : help) {
	cout << x << endl;
	}
	*/
}

