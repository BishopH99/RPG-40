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
	"*     |__SMITH__|       |       |   /   \\______\\        \\         |######|    *",
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
vector<string> well_map = {
	"******************************",
	"*   |^|                      *",
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
vector<string> stable_map = {
	"******************************",
	"*  #  H# |^^^^^^^^^^|  #   # *",
	"*#  # #  |          | #  #  #*",
	"*_____#__|         S|__#_____*",
	"* ##  #  |          |# #H  # *",
	"*  #H  # |          | #  #   *",
	"*___#____|          |___#____*",
	"* #   #  |          | #  #  #*",
	"*#   #H  |          |H #  #  *",
	"*_c#_____|          |_____#__*",
	"*  FFF   |          |   FFF  *",
	"*                            *",
	"******************************",
};
char get_stable_location(size_t row, size_t col) {
	if (row >= stable_map.size()) return ' ';
	if (col >= stable_map.at(row).size()) return ' ';
	return stable_map.at(row).at(col);
}

void set_stable_location(size_t row, size_t col, char c) {
	if (row >= stable_map.size()) return;
	if (col >= stable_map.at(row).size()) return;
	stable_map.at(row).at(col) = c;
}


void print_stable(size_t player_row, size_t player_col) {
	clearscreen();
	movecursor(0, 0);
	for (size_t row = 0; row < stable_map.size(); row++) {
		for (size_t col = 0; col < stable_map.at(row).size(); col++) {
			if (row == player_row and col == player_col) cout << "@";
			else
				cout << stable_map.at(row).at(col);
		}
		cout << endl;
	}
}

int main() {
	vector<string> inv(5);
	const int ROWS = world_map.size();
	const int COLS = world_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES
	const int FPS = 60;
	int quest_accepted = 0;
	int quest_tracker = 0;
	int quest_completed = 0;
	int well_entrance = 0;
	int stable_entrance = 0;
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
			cout << "Quest Tracker: " << quest_tracker;
			movecursor(11, COLS + 5);
			cout << "Current Task: ";
			movecursor(14, COLS + 5);
			cout << "Quest Completed: " << GREEN << quest_completed;
			resetcolor();
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
		if (get_world_location(row, col) == '<' and quest_completed != 1) {
			movecursor(ROWS + 8, 0);
			cout << "You can't enter the well yet!\n";
		}
		if (get_world_location(row, col) == '#') {
			movecursor(ROWS + 8, 0);
			cout << "Do you want to enter the stable? (Y/N)\n";
			if (c == 'Y') {
				stable_entrance++;
				break;
			}
		}
		if (get_world_location(row, col) == '?') {
			movecursor(ROWS + 8, 0);
			cout << "There is a help request on the town board\n";
			cout.flush();
			movecursor(ROWS + 10, 0);
			cout << "The request says the stable hand lost their cat around the stables\n";
			movecursor(ROWS + 11, 0);
			cout << "  Do you want to help the stable hand find their cat? (Y/N)\n";
			if (c == 'Y') {
				set_world_location(row, col, ' ');
				quest_accepted++;
				quest_tracker++;
				continue;
			}
		}
		if (quest_accepted == 1) {
			movecursor(12, COLS + 5);
			cout << YELLOW << "Find the stable hand's(S) cat(c)(0/1)";
			resetcolor();
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
	if (stable_entrance >= 1) {
		const int ROWS = stable_map.size();
		const int COLS = stable_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES
		const int FPS = 60;
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
				print_stable(row, col); //...redraw the map
				last_row = row;
				last_col = col;
				movecursor(2, COLS + 5);
				cout << BLUE << "ROW: " << row << RED << " COL: " << col << RESET;
				movecursor(5, COLS + 5);
				cout << RED  << "HP: " << WHITE << Health << endl; //FIXME: add color indictors to the HP
				movecursor(8, COLS + 5);
				cout << "Quest Tracker: " << quest_tracker;
				movecursor(11, COLS + 5);
				cout << "Current Task: ";
				if (quest_accepted == 1) {
					movecursor(12, COLS + 5);
					cout << YELLOW << "Find the stable hand's(S) cat(c)(0/1)";
				}
				if (quest_accepted == 1 and inv.at(0) == "cat") {
					cout.flush();
					movecursor(12, COLS + 5);
					cout << GREEN << "Find the stable hand's(S) cat(c)(1/1)";
				}
				if (quest_accepted == 1 and inv.at(0) == "empty") {
					movecursor(12, COLS + 5);
					cout << "                                     ";
				}
			}
			movecursor(15, COLS + 5);
			cout << "Quest Completed: " << GREEN << quest_completed;
			movecursor(ROWS + 2, 0);
			setcolor(255, 0, 0);
			cout << "You have entered the stable!\n";
			resetcolor();
			movecursor(ROWS + 4, 0);
			cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel\n";
			movecursor(ROWS + 5, 0);
			cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?)\n";
			if (quest_completed == 1) {
				cout.flush();
				movecursor(ROWS + 5, 0);
				cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (1/5) \n";
			}
			movecursor(ROWS + 6, 0);
			cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
			resetcolor();
			cout.flush();
			if (get_stable_location(row, col) == '^') {
				movecursor(ROWS + 8, 0);
				cout << "Do you want to exit the stables? (Y/N)\n";
				if (c == 'Y') break;
			}
			if (get_stable_location(row, col) == 'c') {
				movecursor(ROWS + 8, 0);
				cout << "You found the stable hands cat!\n";
				inv.at(0) = "cat";
			}
			if (get_stable_location(row, col) == 'S' and inv.at(0) == "cat") {
				movecursor(ROWS + 8, 0);
				cout << "You found my cat thank you so much!\n";
				inv.at(0) = "empty";
				quest_completed++;
				quest_tracker--;
				continue;
			}
			if (get_stable_location(row, col) == 'S' and inv.at(0) == "empty") {
				movecursor(ROWS + 9, 0);
				cout << "I have one more urgent request for help!\n";
				movecursor(ROWS + 10, 0);
				cout << "The Evil Kings prized horse got out and fell down the well!\n";
				movecursor(ROWS + 12, 0);
				cout << "Do you wish to help the stable hand once more? (Y/N) \n";
				if (c == 'Y') {
					quest_accepted++;
					quest_tracker++;
					continue;
				}
			}
			if (quest_accepted == 2) {
				movecursor(12, COLS + 5);
				cout << YELLOW << "Find the prized horse in the well! (0/1)";
				resetcolor();
			}
		}
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
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
			cout << "Quest Tracker: " << quest_tracker;
			movecursor(11, COLS + 5);
			cout << "Current Task: ";
			if (quest_accepted == 2) {
				movecursor(12, COLS + 5);
				cout << YELLOW << "Find the prized horse in the well! (0/1)";
				resetcolor();
			}
			movecursor(15, COLS + 5);
			cout << "Quest Completed: " << GREEN << quest_completed;
			if (quest_completed == 1) {
				cout.flush();
				movecursor(ROWS + 5, 0);
				cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (1/5) \n";
				resetcolor();
			}
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
			if (quest_accepted > 1) {
				movecursor(8, 68);
				cout << BOLDBLACK << "______";
				resetcolor();
			}
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
				resetcolor();
			}
			resetcolor();
			cout.flush();
		}
		if (get_world_location(row, col) == '<') {
			movecursor(ROWS + 8, 0);
			cout << "Do you want to enter the Well? (Y/N)\n";
			if (c == 'Y') {
				well_entrance++;
				break;
			}
		}
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
	if (well_entrance >= 1 and quest_completed == 1) {
		const int ROWS = well_map.size();
		const int COLS = well_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES
		const int FPS = 60;
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
				print_well(row, col); //...redraw the map
				last_row = row;
				last_col = col;
				movecursor(2, COLS + 5);
				cout << BLUE << "ROW: " << row << RED << " COL: " << col << RESET;
				movecursor(5, COLS + 5);
				cout << RED  << "HP: " << WHITE << Health << endl; //FIXME: add color indictors to the HP
				movecursor(8, COLS + 5);
				cout << "Quest Tracker: " << quest_accepted;
				movecursor(11, COLS + 5);
				cout << "Current Task: ";
				movecursor(15, COLS + 5);
				cout << "Quest Completed: ";
				movecursor(ROWS + 2, 0);
				setcolor(255, 0, 0);
				cout << "You have entered the WELL!\n";
				resetcolor();
				movecursor(ROWS + 4, 0);
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel\n";
				movecursor(ROWS + 5, 0);
				cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?)\n";
				movecursor(ROWS + 6, 0);
				cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
				movecursor(2, 6);
				cout << BOLDYELLOW << "_";
				resetcolor();
				cout.flush();
			}
			if (get_well_location(row, col) == '^') {
				movecursor(ROWS + 8, 0);
				cout << "Do you want to exit the well? (Y/N)\n";
				cout.flush();
				if (c == 'Y') break;
				resetcolor();
				cout.flush();
			}
		}
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
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

