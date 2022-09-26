//Fill out this comment with your names and which bullet points you did
//Partners: Hockman, Tipton, Feagin, Grewal
//Bullet Points:
// Hockman:        Tipton:            Feagin:           Grewal:
// world_map,      smith_map,         tavern_map,       well_map
// stable_map,     castle_map,        combat system,    riddles/dialogue,
// map layers,     combat scenarios,  dialogue/riddles, AI art,
// dialogue,       riddle scenarios,  invetory system,  keith,
// colors,         King recursion,    King recursion,
// code,
//Extra Credit: 1) Nonblocking I/O (also in colors.h)
//              2) Compose Original Music and Cover Art (Make it yourself) Upload music to
//                Youtube.
//              3) Inventory System

//URL to cover art and music: https://cdn.discordapp.com/attachments/1007428122485981349/1023902356955467877/00000.png <-- cover art, music/video --> https://www.youtube.com/watch?v=zct13EU608Y&ab_channel=JohnTipton
#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Global Variable - accessible in all functions below
vector<string> world_map = { //HOCKMAN
	"*******************************************************************************",
	"*     ___________           _________________________                         *",
	"*    //_________\\\\      ___/                         \\_________________       *",
	"*     |   ___   |______/                                               \\      *",
	"*     |  |   |  S                 ___________                           \\     *",
	"*     |  |___|  S______          /           \\         ___________       \\    *",
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
	"*      |TTTTTT|         |            |?|   |     |        \\_____\\  /          *",
	"*    _//      \\\\_       |            | |   |     |              E  |          *",
	"*   //__________\\\\      |        _         /     |              E  |EVIL KING *",
	"*    |   ____   |       |       | \\       /      |              E  |  CASTLE  *",
	"*    |  |    |  |       |       |  \\_____/        \\_____________E  |          *",
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
vector<string> well_map = { //GREWAL
	"******************************",
	"*   |^|                      *",
	"*   |_|                      *",
	"*   |_|     ___      ___     *",
	"*   |_|    |   |    |   |    *",
	"*   |_|    |___|    |___|    *",
	"*   |_|                      *",
	"*   |_|                      *",
	"*   |_|                      *",
	"*___|_|________________K_____*",
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
vector<string> stable_map = { //HOCKMAN
	"******************************",
	"*  #  H# |^^^^^^^^^^|  #   # *",
	"*#  # #  |          | #  #  #*",
	"*_____#__|         S|__#_____*",
	"* ##  #  |          |# #H  # *",
	"*  #H  # |          | #  #   *",
	"*___#____|          |___#____*",
	"* #   #  |S         | #  #  #*",
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
vector<string> smith_map = { //TIPTON
	"******************************",
	"*      /  ^^^^^^^^^^  \\      *",
	"*    _o_                     *",
	"*  o|___|o                   *",
	"*     o _             _      *",
	"* [F]  |_|           |_| [F] *",
	"* [F]                    [F] *",
	"* [F]  |=             =| [F] *",
	"* [F]  |=    {===}    =| [F] *",
	"* [F]          S         [F] *",
	"*           _______          *",
	"*          |=======|         *",
	"******************************",
};
char get_smith_location(size_t row, size_t col) {
	if (row >= smith_map.size()) return ' ';
	if (col >= smith_map.at(row).size()) return ' ';
	return smith_map.at(row).at(col);
}
void set_smith_location(size_t row, size_t col, char c) {
	if (row >= smith_map.size()) return;
	if (col >= smith_map.at(row).size()) return;
	smith_map.at(row).at(col) = c;
}
void print_smith(size_t player_row, size_t player_col) {
	clearscreen();
	movecursor(0, 0);
	for (size_t row = 0; row < smith_map.size(); row++) {
		for (size_t col = 0; col < smith_map.at(row).size(); col++) {
			if (row == player_row and col == player_col) cout << "@";
			else
				cout << smith_map.at(row).at(col);
		}
		cout << endl;
	}
}
vector<string> tavern_map = { //Feagin
	"************************",
	"*  |_BB__BB__BB__BB_|  *",
	"*      ____TK____      *",
	"*     |__________|     *",
	"*      o  o  o  o      *",
	"*   _o_o_      __o__   *",
	"*  |     |   o|     |  *",
	"*  |_____|    |_____|  *",
	"*   o   o      o   o   *",
	"*                      *",
	"*   o___o      o___o   *",
	"*  |     |    |     |  *",
	"*  |_____|    |_____|  *",
	"*   o   o       o  o   *",
	"*          _ /         *",
	"************************",
};
char get_tavern_location(size_t row, size_t col) {
	if (row >= tavern_map.size()) return ' ';
	if (col >= tavern_map.at(row).size()) return ' ';
	return tavern_map.at(row).at(col);
}
void set_tavern_location(size_t row, size_t col, char c) {
	if (row >= tavern_map.size()) return;
	if (col >= tavern_map.at(row).size()) return;
	tavern_map.at(row).at(col) = c;
}
void print_tavern(size_t player_row, size_t player_col) {
	clearscreen();
	movecursor(0, 0);
	for (size_t row = 0; row < tavern_map.size(); row++) {
		for (size_t col = 0; col < tavern_map.at(row).size(); col++) {
			if (row == player_row and col == player_col) cout << "@";
			else
				cout << tavern_map.at(row).at(col);
		}
		cout << endl;
	}
}
vector<string> castle_map = { //Tipton
	"*****************************************************",
	"*    _______           _______           _______    *",
	"*   |       |         |       |         |   I   |   *",
	"*   | * _ * |         | 6 6 6 |         |  <3   |   *",
	"*   |  ***  |   (F)   |       |   (F)   |Recursn|   *",
	"*   | * - * |    V    |   P   |    V    |  -KR  |   *",
	"*   |_______|         |_______|         |_______|   *",
	"*                                                  ]*",
	"*                                                K ]*",
	"*      (F)       ||      (F)       ||      (F)  __] *",
	"*       V        ||       V        ||       V__|    *",
	"*                ||                ||               *",
	"*****************************************************",
};
char get_castle_location(size_t row, size_t col) {
	if (row >= castle_map.size()) return ' ';
	if (col >= castle_map.at(row).size()) return ' ';
	return castle_map.at(row).at(col);
}
void set_castle_location(size_t row, size_t col, char c) {
	if (row >= castle_map.size()) return;
	if (col >= castle_map.at(row).size()) return;
	castle_map.at(row).at(col) = c;
}
void print_castle(size_t player_row, size_t player_col) {
	clearscreen();
	movecursor(0, 0);
	for (size_t row = 0; row < castle_map.size(); row++) {
		for (size_t col = 0; col < castle_map.at(row).size(); col++) {
			if (row == player_row and col == player_col) cout << "@";
			else
				cout << castle_map.at(row).at(col);
		}
		cout << endl;
	}
}

int main() { // FIRST WORLD MAP INSTANCE (COMPLETE) // HOCKMAN
	vector<string> inv(5);
	const int ROWS = world_map.size();
	const int COLS = world_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES
	const int FPS = 60;
	int quest_accepted = 0;
	int quest_tracker = 0;
	int quest_completed = 0;
	int location_completed = 0;
	int well_entrance = 0;
	int stable_entrance = 0;
	int smith_entrance = 0;
	int tavern_entrance = 0;
	int castle_entrance = 0;
	int Health = 50;
	int keithHP = 15;
	int kingHP = 1000;
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
			movecursor(ROWS + 3, 0);
			cout << "You were hired by an anonymous party to restore the kingdom to its former glory.\n";
			movecursor(ROWS + 5, 0);
			cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel (0/5)\n";
			movecursor(ROWS + 6, 0);
			cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (0/5)\n";
			movecursor(ROWS + 7, 0);
			cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
			movecursor(17, 39);
			cout << BOLDYELLOW << "?";
			movecursor(24, 9);
			cout << WHITE << "TAVERN";
			movecursor(8, 10);
			cout << WHITE << "SMITH";
			movecursor(11, 37);
			cout << WHITE << "WELL";
			movecursor(12, 68);
			cout << WHITE << "STABLE";
			if (quest_accepted == 1) {
				movecursor(12, 68);
				cout << BOLDYELLOW << "STABLE";
			}
			movecursor(19, 69);
			cout << WHITE << "EVIL";
			movecursor(19, 74);
			cout << WHITE << "KING";
			movecursor(20, 71);
			cout << WHITE << "CASTLE";
			movecursor(17, 9);
			cout << WHITE << "______";
			movecursor(5, 17);
			cout << WHITE << "|";
			movecursor(6, 17);
			cout << WHITE << "|";
			movecursor(9, 42);
			cout << WHITE << "|";
			movecursor(8, 68);
			cout << WHITE << "______";
			if (quest_accepted == 1) {
				movecursor(8, 68);
				cout << BOLDYELLOW << "______";
			}
			movecursor(18, 65);
			cout << WHITE << "|";
			movecursor(19, 65);
			cout << WHITE << "|";
			movecursor(20, 65);
			cout << WHITE << "|";
			movecursor(21, 65);
			cout << WHITE << "|";
			if (quest_accepted > 0) {
				movecursor(17, 39);
				cout << BOLDBLACK << "?";
			}
			resetcolor();
			cout.flush();
		}
		if (get_world_location(row, col) == '<' and quest_completed != 1 and quest_accepted == 1) {
			movecursor(ROWS + 9, 0);
			cout << "You can't enter the well yet! You need to go to the stable.\n";
		}
		if (get_world_location(row, col) == '<' and quest_completed != 1 and quest_accepted == 0) {
			movecursor(ROWS + 9, 0);
			cout << "You can't enter the well yet! You need to check the town board ->(?)\n";
		}
		if (get_world_location(row, col) == 'S' and quest_completed != 1 and quest_accepted == 1) {
			movecursor(ROWS + 9, 0);
			cout << "You can't enter the smith yet! You need to go to the stable.\n";
		}
		if (get_world_location(row, col) == 'S' and quest_completed != 1 and quest_accepted == 0) {
			movecursor(ROWS + 9, 0);
			cout << "You can't enter the smith yet! You need to check the town board ->(?)\n";
		}
		if (get_world_location(row, col) == 'T' and quest_completed != 1 and quest_accepted == 1) {
			movecursor(ROWS + 9, 0);
			cout << "You can't enter the tavern yet! You need to go to the stable.\n";
		}
		if (get_world_location(row, col) == 'T' and quest_completed != 1 and quest_accepted == 0) {
			movecursor(ROWS + 9, 0);
			cout << "You can't enter the tavern yet! You need to check the town board ->(?)\n";
		}
		if (get_world_location(row, col) == 'E' and quest_completed != 1 and quest_accepted == 1) {
			movecursor(ROWS + 9, 0);
			cout << "You can't enter the castle yet! You need to go to the stable.\n";
		}
		if (get_world_location(row, col) == 'E' and quest_completed != 1 and quest_accepted == 0) {
			movecursor(ROWS + 9, 0);
			cout << "You can't enter the castle yet! You need to check the town board ->(?)\n";
		}
		if (get_world_location(row, col) == '#' and quest_accepted == 1) {
			movecursor(ROWS + 9, 0);
			cout << "Do you want to enter the stable? (Y/N)\n";
			if (c == 'Y') {
				stable_entrance++;
				break;
			}
		}
		if (get_world_location(row, col) == '#' and quest_accepted == 0) {
			movecursor(ROWS + 9, 0);
			cout << "You need to check the town board ->(?)\n";
		}
		if (get_world_location(row, col) == '?' and quest_accepted == 0) {
			movecursor(ROWS + 9, 0);
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
		if (c == ERR) usleep(1'000'000 / FPS);
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
	if (stable_entrance >= 1) { //FIRST STABLES INSTANCE (complete). // Hockman
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
				movecursor(2, 10);
				setcolor(144, 106, 42);
				cout << "|";
				movecursor(3, 10);
				cout << "|";
				movecursor(4, 10);
				cout << "|";
				movecursor(5, 10);
				cout << "|";
				movecursor(6, 10);
				cout << "|";
				movecursor(7, 10);
				cout << "|";
				movecursor(8, 10);
				cout << "|";
				movecursor(9, 10);
				cout << "|";
				movecursor(10, 10);
				cout << "|";
				movecursor(11, 10);
				cout << "|";
				movecursor(2, 21);
				cout << "|";
				movecursor(3, 21);
				cout << "|";
				movecursor(4, 21);
				cout << "|";
				movecursor(5, 21);
				cout << "|";
				movecursor(6, 21);
				cout << "|";
				movecursor(7, 21);
				cout << "|";
				movecursor(8, 21);
				cout << "|";
				movecursor(9, 21);
				cout << "|";
				movecursor(10, 21);
				cout << "|";
				movecursor(11, 21);
				cout << "|";
				movecursor(4, 8);
				cout << "__";
				movecursor(4, 2);
				cout << "_____";
				movecursor(7, 6);
				cout << "____";
				movecursor(7, 2);
				cout << "___";
				movecursor(4, 22);
				cout << "__";
				movecursor(4, 25);
				cout << "_____";
				movecursor(7, 22);
				cout << "___";
				movecursor(7, 26);
				cout << "____";
				movecursor(10, 22);
				cout << "_____";
				movecursor(10, 28);
				cout << "__";
				movecursor(2, 7);
				cout << "H";
				movecursor(6, 5);
				cout << "H";
				movecursor(9, 7);
				cout << "H";
				movecursor(5, 25);
				cout << "H";
				movecursor(9, 22);
				cout << "H";
				if ((inv.at(0) == "cat") or (inv.at(0) == "empty" and quest_accepted == 2)) {
					movecursor(10, 3);
					cout << "_";
				}
				movecursor(10, 2);
				cout << "_";
				movecursor(10, 5);
				cout << "_____";
				resetcolor();
				movecursor(2, 8);
				cout << YELLOW << "#";
				movecursor(3, 7);
				cout << YELLOW << "#";
				movecursor(4, 7);
				cout << YELLOW << "#";
				movecursor(3, 5);
				cout << YELLOW << "#";
				movecursor(2, 4);
				cout << YELLOW << "#";
				movecursor(3, 2);
				cout << YELLOW << "#";
				movecursor(5, 7);
				cout << YELLOW << "#";
				movecursor(6, 8);
				cout << YELLOW << "#";
				movecursor(7, 5);
				cout << YELLOW << "#";
				movecursor(6, 4);
				cout << YELLOW << "#";
				movecursor(5, 4);
				cout << YELLOW << "#";
				movecursor(5, 3);
				cout << YELLOW << "#";
				movecursor(8, 7);
				cout << YELLOW << "#";
				movecursor(9, 6);
				cout << YELLOW << "#";
				movecursor(10, 4);
				cout << YELLOW << "#";
				movecursor(9, 2);
				cout << YELLOW << "#";
				movecursor(8, 3);
				cout << YELLOW << "#";
				movecursor(2, 24);
				cout << YELLOW << "#";
				movecursor(3, 23);
				cout << YELLOW << "#";
				movecursor(4, 24);
				cout << YELLOW << "#";
				movecursor(3, 26);
				cout << YELLOW << "#";
				movecursor(2, 28);
				cout << YELLOW << "#";
				movecursor(3, 29);
				cout << YELLOW << "#";
				movecursor(5, 28);
				cout << YELLOW << "#";
				movecursor(6, 26);
				cout << YELLOW << "#";
				movecursor(7, 25);
				cout << YELLOW << "#";
				movecursor(6, 23);
				cout << YELLOW << "#";
				movecursor(5, 24);
				cout << YELLOW << "#";
				movecursor(5, 22);
				cout << YELLOW << "#";
				movecursor(8, 29);
				cout << YELLOW << "#";
				movecursor(8, 26);
				cout << YELLOW << "#";
				movecursor(8, 23);
				cout << YELLOW << "#";
				movecursor(9, 23);
				cout << YELLOW << "#";
				movecursor(9, 27);
				cout << YELLOW << "#";
				movecursor(10, 27);
				cout << YELLOW << "#";
				movecursor(9, 24);
				cout << YELLOW << "#";
				if (quest_accepted == 2) {
					movecursor(2, 11);
					cout << BOLDYELLOW << "^^^^^^^^^^";
				}
				if (inv.at(0) != "cat" and inv.at(0) != "empty") {
					movecursor(10, 3);
					cout << BOLDYELLOW << "c";
				}
				if (inv.at(0) == "cat" and quest_accepted != 2) {
					movecursor(8, 11);
					cout << BOLDYELLOW << "S";
					movecursor(4, 20);
					cout << BOLDYELLOW << "S";
				}
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
					movecursor(13, COLS + 5);
					cout << YELLOW << "Return the cat to the stable hand.";
					resetcolor();
				}
				if (quest_accepted == 1 and inv.at(0) == "empty") {
					movecursor(12, COLS + 5);
					cout << "                                                                                   ";
					movecursor(13, COLS + 5);
					cout << "                                                                                   ";
				}
			}
			if (quest_completed == 0) {
				movecursor(14, COLS + 5);
				cout << "Quest Completed: " << GREEN << quest_completed;
			}
			if (quest_completed == 1) {
				movecursor(14, COLS + 5);
				cout << "Quest Completed: " << GREEN << quest_completed;
			}
			movecursor(ROWS + 2, 0);
			setcolor(255, 0, 0);
			cout << "You have entered the stable!\n";
			resetcolor();
			if (quest_completed == 0) {
				movecursor(ROWS + 4, 0);
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel (0/5)\n";
				movecursor(ROWS + 5, 0);
				cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (0/5) \n";
			}
			if (quest_completed == 1) {
				cout.flush();
				movecursor(ROWS + 4, 0);
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel (1/5)\n";
				movecursor(ROWS + 5, 0);
				cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (1/5) \n";
			}
			movecursor(ROWS + 6, 0);
			cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
			resetcolor();
			cout.flush();
			if (get_stable_location(row, col) == '^' and quest_accepted == 2) {
				movecursor(ROWS + 8, 0);
				cout << "Do you want to exit the stables? (Y/N)\n";
				if (c == 'Y') break;
			}
			if (get_stable_location(row, col) == '^' and inv.at(0) == "cat") {
				movecursor(ROWS + 8, 0);
				cout << "DO NOT TAKE THE STABLE HANDS CAT! Give it to one of them before you leave.\n";
			}
			if (get_stable_location(row, col) == '^' and quest_accepted != 2 and inv.at(0) == "empty") {
				movecursor(ROWS + 8, 0);
				cout << "You have not finished talking to the stable hand, make sure you accept the next task!\n";
			}
			if (get_stable_location(row, col) == '^' and quest_accepted != 2 and quest_completed != 1 and inv.at(0) != "cat") {
				movecursor(ROWS + 8, 0);
				cout << "You better find the cat and give it to the stable hand before leaving!\n";
			}
			if (get_stable_location(row, col) == 'c') {
				movecursor(ROWS + 8, 0);
				cout << "You found the stable hands cat!\n";
				inv.at(0) = "cat";
				set_stable_location(row, col, '_');
			}
			if (get_stable_location(row, col) == 'S' and inv.at(0) == "cat" and quest_accepted < 2) {
				movecursor(ROWS + 8, 0);
				cout << "         You found my cat thank you so much!\n";
				inv.at(0) = "empty";
				quest_completed++;
				quest_tracker--;
				continue;
			}
			if (get_stable_location(row, col) == 'S' and inv.at(0) == "empty" and quest_accepted < 2) {
				movecursor(ROWS + 9, 0);
				cout << "       I have one more urgent request for help!\n";
				movecursor(ROWS + 10, 0);
				cout << "The Evil Kings prized horse got out and fell down the well!\n";
				movecursor(ROWS + 12, 0);
				cout << "    Do you wish to help the stable hand once more? (Y/N) \n";
				if (c == 'Y') {
					set_stable_location(row, col, ' ');
					quest_accepted++;
					quest_tracker++;
					continue;
				}
			}
			if (quest_accepted == 2) {
				movecursor(12, COLS + 5);
				cout << YELLOW << "Find the prized horse in the well! (0/1)\n";
				movecursor(13, COLS + 5);
				cout << YELLOW << "                                                                                                            \n";
				resetcolor();
			}
		}
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
	if (quest_completed == 1) { //SECOND WORLD MAP INSTANCE (COMPLETE)
		print_world(row, col);
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
				movecursor(14, COLS + 5);
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
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel. (0/5)\n";
				movecursor(ROWS + 5, 0);
				cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?)\n";
				movecursor(ROWS + 6, 0);
				cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
				movecursor(17, 39);
				cout << WHITE << "?";
				movecursor(24, 9);
				cout << WHITE << "TAVERN";
				movecursor(8, 10);
				cout << WHITE << "SMITH";
				movecursor(11, 37);
				cout << BOLDYELLOW << "WELL";
				movecursor(12, 68);
				cout << WHITE << "STABLE";
				movecursor(19, 69);
				cout << WHITE << "EVIL";
				movecursor(19, 74);
				cout << WHITE << "KING";
				movecursor(20, 71);
				cout << WHITE << "CASTLE";
				movecursor(17, 9);
				cout << WHITE << "______";
				movecursor(5, 17);
				cout << WHITE << "|";
				movecursor(6, 17);
				cout << WHITE << "|";
				movecursor(9, 42);
				cout << BOLDYELLOW << "|";
				movecursor(8, 68);
				cout << WHITE << "______";
				if (quest_accepted > 1) {
					movecursor(8, 68);
					cout << BOLDBLACK << "______";
					resetcolor();
				}
				movecursor(18, 65);
				cout << WHITE << "|";
				movecursor(19, 65);
				cout << WHITE << "|";
				movecursor(20, 65);
				cout << WHITE << "|";
				movecursor(21, 65);
				cout << WHITE << "|";
				if (quest_accepted == 2) {
					movecursor(17, 39);
					set_world_location(16, 38, '=');
					cout << WHITE << "=";
					resetcolor();
				}
				resetcolor();
				cout.flush();
			}
			if (get_world_location(row, col) == '#' and quest_completed != 2 and quest_accepted == 2) {
				movecursor(ROWS + 8, 0);
				cout << "You can't enter the stables again, you just left. go check out the well to find the horse.\n";
			}
			if (get_world_location(row, col) == 'S' and quest_completed != 2 and quest_accepted == 2) {
				movecursor(ROWS + 8, 0);
				cout << "The smith doesn't trust you yet. You need to go rescure the horse in the well to gain his trust!\n";
			}
			if (get_world_location(row, col) == 'T' and quest_completed != 2 and quest_accepted == 2) {
				movecursor(ROWS + 8, 0);
				cout << "WHY ARE YOU NOT RESCUING THE HORSE??? GO TO THE WELL DUMBY.\n";
			}
			if (get_world_location(row, col) == 'E' and quest_completed != 2 and quest_accepted == 2) {
				movecursor(ROWS + 8, 0);
				cout << "You really don't care about that horse do you? GO TO THE WELL...\n";
			}
			if (get_world_location(row, col) == '=' and quest_completed != 2 and quest_accepted == 2) {
				movecursor(ROWS + 8, 0);
				cout << "You have already completed the requests on the town board come back another time to check for more!\n";
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
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
	if (well_entrance >= 1 and quest_completed == 1) { //FIRST AND LAST WELL INSTANCE (COMPLETE)
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
				cout << "Quest Tracker: " << quest_tracker;
				movecursor(11, COLS + 5);
				cout << "Current Task: ";
				if (quest_accepted == 2) {
					movecursor(12, COLS + 5);
					cout << YELLOW << "Find the prized horse in the well! (0/1)";
					resetcolor();
				}
				if (quest_accepted == 2 and inv.at(0) == "horse") {
					movecursor(12, COLS + 5);
					cout << GREEN << "Find the prized horse in the well! (1/1)";
					movecursor(13, COLS + 5);
					cout << YELLOW << "Return the horse to the stable hand.";
					resetcolor();
				}
				movecursor(15, COLS + 5);
				cout << "Quest Completed: " << GREEN << quest_completed;
				resetcolor();
				if (quest_completed == 1) {
					cout.flush();
					movecursor(ROWS + 5, 0);
					cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (1/5) \n";
					resetcolor();
				}
				movecursor(ROWS + 2, 0);
				setcolor(255, 0, 0);
				cout << "You have entered the WELL!\n";
				resetcolor();
				movecursor(ROWS + 4, 0);
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel. (0/5)\n";
				movecursor(ROWS + 6, 0);
				cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
				setbgcolor(41, 152, 134);
				movecursor(11, 2);
				cout << "!                          !";
				movecursor(12, 2);
				cout << "!                          !";
				movecursor(6, 13);
				cout << "   ";
				movecursor(7, 13);
				cout << "   ";
				movecursor(8, 13);
				cout << "   ";
				movecursor(9, 13);
				cout << "   ";
				movecursor(10, 13);
				cout << "   ";
				resetcolor();
				setcolor(144, 106, 42);
				movecursor(2, 5);
				cout << "|";
				movecursor(3, 5);
				cout << "|";
				movecursor(4, 5);
				cout << "|";
				movecursor(5, 5);
				cout << "|";
				movecursor(6, 5);
				cout << "|";
				movecursor(7, 5);
				cout << "|";
				movecursor(8, 5);
				cout << "|";
				movecursor(9, 5);
				cout << "|";
				movecursor(10, 5);
				cout << "|";
				movecursor(2, 7);
				cout << "|";
				movecursor(2, 7);
				cout << "|";
				movecursor(3, 7);
				cout << "|";
				movecursor(4, 7);
				cout << "|";
				movecursor(5, 7);
				cout << "|";
				movecursor(6, 7);
				cout << "|";
				movecursor(7, 7);
				cout << "|";
				movecursor(8, 7);
				cout << "|";
				movecursor(9, 7);
				cout << "|";
				movecursor(10, 7);
				cout << "|";
				movecursor(2, 6);
				cout << "_";
				movecursor(3, 6);
				cout << "_";
				movecursor(4, 6);
				cout << "_";
				movecursor(5, 6);
				cout << "_";
				movecursor(6, 6);
				cout << "_";
				movecursor(7, 6);
				cout << "_";
				movecursor(8, 6);
				cout << "_";
				movecursor(9, 6);
				cout << "_";
				movecursor(10, 6);
				cout << "_";
				if (inv.at(0) != "horse") {
					movecursor(10, 24);
					cout << "H";
					movecursor(2, 6);
					cout << "_";
				}
				resetcolor();
				if (inv.at(0) == "horse") {
					movecursor(2, 6);
					cout << BOLDYELLOW << "_";
				}
				resetcolor();
				cout.flush();
			}
			if (get_well_location(row, col) == 'K') {
				movecursor(ROWS + 8, 0);
				cout << "AYOO im a big ass rat I got that Evil King's horse who would of though. FIGHT ME FOR IT.\n";
				movecursor(ROWS + 9, 0);
				cout << "What would you like to do: \n";
				movecursor(ROWS + 10, 0);
				cout << "   (1) Attack (2) Defend \n";
				if (c == '1') {
					movecursor(ROWS + 11, 0);
					keithHP -= 3;
					Health -= 4;
					cout << "You have: " << Health << " HP Left                                                                                            \n";
					movecursor(ROWS + 12, 0);
					cout << "Keith has: " << keithHP << " HP Left                                                                                        \n";
				} else if (c == '2') {
					movecursor(ROWS + 11, 0);
					keithHP -= 1;
					Health -= 2;
					cout << "You have: " << Health << " HP Left                                                                                          \n";
					movecursor(ROWS + 12, 0);
					cout << "Keith has: " << keithHP << " HP Left                                                                                       \n";
				}
				if (keithHP == 0) {
					movecursor(ROWS + 13, 0);
					cout << "Damn if you want your horse back so bad take it.\n";
					set_well_location(row, col, 'H');
				}
			}
			/*if (c == '1') {
			  movecursor(ROWS + 11, 0);
			  keithHP -= 3;
			  Health -= 4;
			  cout << "You have: " << Health << " HP Left                                                                                            \n";
			  movecursor(ROWS + 12, 0);
			  cout << "Keith has: " << keithHP << " HP Left                                                                                        \n";
			  } else if (c == '2') {
			  movecursor(ROWS + 11, 0);
			  keithHP -= 1;
			  Health -= 2;
			  cout << "You have: " << Health << " HP Left                                                                                          \n";
			  movecursor(ROWS + 12, 0);
			  cout << "Keith has: " << keithHP << " HP Left                                                                                       \n";
			  }
			  if (keithHP == 0) {
			  movecursor(ROWS + 13, 0);
			  cout << "Damn if you want your horse back so bad take it.\n";
			  set_well_location(row, col, 'H');
			  }

			*/
			if (get_well_location(row, col) == 'H') {
				movecursor(ROWS + 8, 0);
				cout << "You found the Evil King's prized Horse!\n";
				movecursor(ROWS + 9, 0);
				cout << "   Bring it back to the stable hand\n";
				inv.at(0) = "horse";
				set_well_location(row, col, '_');
				continue;
			}
			if (get_well_location(row, col) == '^' and inv.at(0) != "horse") {
				movecursor(ROWS + 8, 0);
				cout << "You should probably get the horse before you leave. scoundrel...";
			}
			if (get_well_location(row, col) == '^' and inv.at(0) == "horse") {
				movecursor(ROWS + 8, 0);
				cout << "Do you want to exit the well? (Y/N)\n";
				cout.flush();
				if (c == 'Y') break;
				resetcolor();
				cout.flush();
			}
		}
		location_completed++;
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
	if (inv.at(0) == "horse") { // THIRD MAP INSTANCE (COMPLETE)
		print_world(row, col);
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
				if (quest_accepted == 2 and inv.at(0) == "horse") {
					movecursor(12, COLS + 5);
					cout << GREEN << "Find the prized horse in the well! (1/1)";
					movecursor(13, COLS + 5);
					cout << YELLOW << "Return the horse to the stable hand.";
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
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel. (1/5)\n";
				movecursor(ROWS + 6, 0);
				cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
				if (quest_completed == 1) {
					set_world_location(16, 38, '=');
					movecursor(17, 39);
					cout << BOLDBLACK << "=";
				}
				movecursor(24, 9);
				cout << WHITE << "TAVERN";
				movecursor(8, 10);
				cout << WHITE << "SMITH";
				movecursor(11, 37);
				cout << GREEN << "WELL";
				movecursor(12, 68);
				cout << BOLDYELLOW << "STABLE";
				movecursor(19, 69);
				cout << WHITE << "EVIL";
				movecursor(19, 74);
				cout << WHITE << "KING";
				movecursor(20, 71);
				cout << WHITE << "CASTLE";
				movecursor(17, 9);
				cout << WHITE << "______";
				movecursor(5, 17);
				cout << WHITE << "|";
				movecursor(6, 17);
				cout << WHITE << "|";
				movecursor(9, 42);
				cout << BOLDBLACK << "|";
				movecursor(8, 68);
				cout << BOLDYELLOW << "______";
				movecursor(18, 65);
				cout << WHITE << "|";
				movecursor(19, 65);
				cout << WHITE << "|";
				movecursor(20, 65);
				cout << WHITE << "|";
				movecursor(21, 65);
				cout << WHITE << "|";
				resetcolor();
				cout.flush();
			}
			if (get_world_location(row, col) == '<' and quest_completed != 2 and quest_accepted == 2) {
				movecursor(ROWS + 8, 0);
				cout << "You can't enter the well again, you just left. Go check out the stable to return the horse.\n";
			}
			if (get_world_location(row, col) == 'S' and quest_completed != 2 and quest_accepted == 2) {
				movecursor(ROWS + 8, 0);
				cout << "You can't go into the smith. You need to take the horse back to the stables don't think he would appreciate a horse in his store.\n";
			}
			if (get_world_location(row, col) == 'T' and quest_completed != 2 and quest_accepted == 2) {
				movecursor(ROWS + 8, 0);
				cout << "looks like you want to bring the horse into the tavern. TOO BAD NO HORSES ALLOWED SIGN.\n";
			}
			if (get_world_location(row, col) == 'E' and quest_completed != 2 and quest_accepted == 2) {
				movecursor(ROWS + 8, 0);
				cout << "Why would you want to go into the Evil kings castle before getting rid of this horse?\n";
			}
			if (get_world_location(row, col) == '=' and quest_completed != 2 and quest_accepted == 2) {
				movecursor(ROWS + 8, 0);
				cout << "You have already completed the requests on the town board come back another time to check for more!\n";
			}
			if (get_world_location(row, col) == '#') {
				movecursor(ROWS + 8, 0);
				cout << "Do you want to enter the stable? (Y/N)\n";
				if (c == 'Y') {
					stable_entrance++;
					break;
				}
			}

		}
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
	if (stable_entrance == 2) { //SECOND STABLE INSTANCE (COMPLETE)
		set_raw_mode(true);
		show_cursor(false);
		const int ROWS = stable_map.size();
		const int COLS = stable_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES
		const int FPS = 60;
		int row = ROWS / 2, col = COLS / 2;
		int last_row = -1, last_col = -1;//Save our last position so we only redraw on update
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
				movecursor(2, 10);
				setcolor(144, 106, 42);
				cout << "|";
				movecursor(3, 10);
				cout << "|";
				movecursor(4, 10);
				cout << "|";
				movecursor(5, 10);
				cout << "|";
				movecursor(6, 10);
				cout << "|";
				movecursor(7, 10);
				cout << "|";
				movecursor(8, 10);
				cout << "|";
				movecursor(9, 10);
				cout << "|";
				movecursor(10, 10);
				cout << "|";
				movecursor(11, 10);
				cout << "|";
				movecursor(2, 21);
				cout << "|";
				movecursor(3, 21);
				cout << "|";
				movecursor(4, 21);
				cout << "|";
				movecursor(5, 21);
				cout << "|";
				movecursor(6, 21);
				cout << "|";
				movecursor(7, 21);
				cout << "|";
				movecursor(8, 21);
				cout << "|";
				movecursor(9, 21);
				cout << "|";
				movecursor(10, 21);
				cout << "|";
				movecursor(11, 21);
				cout << "|";
				movecursor(4, 8);
				cout << "__";
				movecursor(4, 2);
				cout << "_____";
				movecursor(7, 6);
				cout << "____";
				movecursor(7, 2);
				cout << "___";
				movecursor(4, 22);
				cout << "__";
				movecursor(4, 25);
				cout << "_____";
				movecursor(7, 22);
				cout << "___";
				movecursor(7, 26);
				cout << "____";
				movecursor(10, 22);
				cout << "_____";
				movecursor(10, 28);
				cout << "__";
				movecursor(2, 7);
				cout << "H";
				movecursor(6, 5);
				cout << "H";
				movecursor(9, 7);
				cout << "H";
				movecursor(5, 25);
				cout << "H";
				movecursor(9, 22);
				cout << "H";
				if (quest_completed == 2) {
					movecursor(3, 25);
					cout << "H";
				}
				movecursor(10, 2);
				cout << "_";
				movecursor(10, 3);
				cout << "_";
				movecursor(10, 5);
				cout << "_____";
				resetcolor();
				movecursor(2, 8);
				cout << YELLOW << "#";
				movecursor(3, 7);
				cout << YELLOW << "#";
				movecursor(4, 7);
				cout << YELLOW << "#";
				movecursor(3, 5);
				cout << YELLOW << "#";
				movecursor(2, 4);
				cout << YELLOW << "#";
				movecursor(3, 2);
				cout << YELLOW << "#";
				movecursor(5, 7);
				cout << YELLOW << "#";
				movecursor(6, 8);
				cout << YELLOW << "#";
				movecursor(7, 5);
				cout << YELLOW << "#";
				movecursor(6, 4);
				cout << YELLOW << "#";
				movecursor(5, 4);
				cout << YELLOW << "#";
				movecursor(5, 3);
				cout << YELLOW << "#";
				movecursor(8, 7);
				cout << YELLOW << "#";
				movecursor(9, 6);
				cout << YELLOW << "#";
				movecursor(10, 4);
				cout << YELLOW << "#";
				movecursor(9, 2);
				cout << YELLOW << "#";
				movecursor(8, 3);
				cout << YELLOW << "#";
				movecursor(2, 24);
				cout << YELLOW << "#";
				movecursor(3, 23);
				cout << YELLOW << "#";
				movecursor(4, 24);
				cout << YELLOW << "#";
				movecursor(3, 26);
				cout << YELLOW << "#";
				movecursor(2, 28);
				cout << YELLOW << "#";
				movecursor(3, 29);
				cout << YELLOW << "#";
				movecursor(5, 28);
				cout << YELLOW << "#";
				movecursor(6, 26);
				cout << YELLOW << "#";
				movecursor(7, 25);
				cout << YELLOW << "#";
				movecursor(6, 23);
				cout << YELLOW << "#";
				movecursor(5, 24);
				cout << YELLOW << "#";
				movecursor(5, 22);
				cout << YELLOW << "#";
				movecursor(8, 29);
				cout << YELLOW << "#";
				movecursor(8, 26);
				cout << YELLOW << "#";
				movecursor(8, 23);
				cout << YELLOW << "#";
				movecursor(9, 23);
				cout << YELLOW << "#";
				movecursor(9, 27);
				cout << YELLOW << "#";
				movecursor(10, 27);
				cout << YELLOW << "#";
				movecursor(9, 24);
				cout << YELLOW << "#";
				if (quest_accepted == 2 and inv.at(0) == "empty") {
					movecursor(2, 11);
					cout << BOLDYELLOW << "^^^^^^^^^^";
				}
				movecursor(2, COLS + 5);
				cout << BLUE << "ROW: " << row << RED << " COL: " << col << RESET;
				movecursor(5, COLS + 5);
				cout << RED  << "HP: " << WHITE << Health << endl; //FIXME: add color indictors to the HP
				movecursor(8, COLS + 5);
				cout << "Quest Tracker: " << quest_tracker;
				movecursor(11, COLS + 5);
				cout << "Current Task: ";
				if (quest_accepted == 2 and inv.at(0) == "horse") {
					movecursor(12, COLS + 5);
					cout << YELLOW << "Return the horse to the stable hand(S).                                                                    \n";
				}
			}
			if (quest_completed == 1) {
				movecursor(14, COLS + 5);
				cout << "Quest Completed: " << GREEN << quest_completed;
			}
			if (quest_completed == 2) {
				movecursor(14, COLS + 5);
				cout << "Quest Completed: " << GREEN << quest_completed;
			}
			movecursor(ROWS + 2, 0);
			setcolor(255, 0, 0);
			cout << "You have entered the stable!\n";
			resetcolor();
			if (inv.at(0) == "horse") {
				movecursor(ROWS + 4, 0);
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel (1/5)\n";
			}
			if (inv.at(0) == "empty") {
				movecursor(ROWS + 4, 0);
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel (2/5)\n";
			}
			if (quest_completed == 1) {
				movecursor(ROWS + 5, 0);
				cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (1/5)\n";
			}
			if (quest_completed == 2) {
				cout.flush();
				movecursor(ROWS + 5, 0);
				cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (2/5) \n";
			}
			movecursor(ROWS + 6, 0);
			cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
			resetcolor();
			cout.flush();
			if (get_stable_location(row, col) == '^' and quest_completed == 2 and inv.at(0) == "empty") {
				movecursor(ROWS + 8, 0);
				cout << "Do you want to exit the stables? (Y/N)\n";
				if (c == 'Y') break;
			}
			if (get_stable_location(row, col) == '^' and inv.at(0) == "horse") {
				movecursor(ROWS + 8, 0);
				cout << "DO NOT LEAVE WITH THE EVIL KINGS HORSE! Give it to the stable hand before you leave.\n";
			}
			if (get_stable_location(row, col) == 'S' and inv.at(0) == "horse" and quest_completed == 1) {
				movecursor(ROWS + 8, 0);
				cout << "            You found the evil kings horse thank you so much!\n";
				inv.at(0) = "empty";
				quest_completed++;
				quest_tracker--;
				continue;
			}
			if (get_stable_location(row, col) == 'S' and inv.at(0) == "empty" and quest_accepted == 2) {
				movecursor(ROWS + 9, 0);
				cout << "                   Thank you for all of your help!\n";
				movecursor(ROWS + 10, 0);
				cout << "             You have saved me from the Evil Kings wraith!\n";
				movecursor(ROWS + 12, 0);
				cout << "The blacksmith told me he was working on armor powerful enough to defend\n";
				movecursor(ROWS + 13, 0);
				cout << "       aginst the Evil King. He's over at the smith go talk to him!\n";
			}
			if (quest_tracker == 0 and inv.at(0) == "empty") {
				movecursor(12, COLS + 5);
				cout << YELLOW << "Go speak with the blacksmith.                                                                     \n";
				movecursor(13, COLS + 5);
				cout << "                                                                                                             \n";
				resetcolor();
			}
		}
		location_completed++;
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
	if (location_completed == 2) { //FORUTH MAP INSTANCE (COMPLETE)
		print_world(row, col);
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
					cout << YELLOW << "Go to the Smith, and talk to the blacksmith.\n";
					movecursor(13, COLS + 5);
					cout << YELLOW << "    Keep his wife's name out your mouth.\n";
					resetcolor();
				}
				movecursor(15, COLS + 5);
				cout << "Quest Completed: " << GREEN << quest_completed;
				if (quest_completed == 2) {
					cout.flush();
					movecursor(ROWS + 5, 0);
					cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (2/5) \n";
					resetcolor();
				}
				movecursor(ROWS + 2, 0);
				setcolor(255, 0, 0);
				cout << "Welcome to the EVIL KING RECURSION'S DOMAIN\n";
				resetcolor();
				movecursor(ROWS + 4, 0);
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel. (2/5)\n";
				movecursor(ROWS + 6, 0);
				cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
				movecursor(17, 39);
				cout << BOLDBLACK << "=";
				movecursor(24, 9);
				cout << WHITE << "TAVERN";
				movecursor(8, 10);
				cout << BOLDYELLOW << "SMITH";
				movecursor(11, 37);
				cout << GREEN << "WELL";
				movecursor(12, 68);
				cout << GREEN << "STABLE";
				movecursor(19, 69);
				cout << WHITE << "EVIL";
				movecursor(19, 74);
				cout << WHITE << "KING";
				movecursor(20, 71);
				cout << WHITE << "CASTLE";
				movecursor(17, 9);
				cout << WHITE << "______";
				movecursor(5, 17);
				cout << BOLDYELLOW << "|";
				movecursor(6, 17);
				cout << BOLDYELLOW << "|";
				movecursor(9, 42);
				cout << BOLDBLACK << "|";
				movecursor(8, 68);
				cout << BOLDBLACK << "______";
				movecursor(18, 65);
				cout << WHITE << "|";
				movecursor(19, 65);
				cout << WHITE << "|";
				movecursor(20, 65);
				cout << WHITE << "|";
				movecursor(21, 65);
				cout << WHITE << "|";
				if (location_completed == 2) {
					set_world_location(16, 38, '=');
					resetcolor();
				}
				resetcolor();
				cout.flush();
			}
			if (get_world_location(row, col) == '#' and location_completed == 2) {
				movecursor(ROWS + 8, 0);
				cout << "You can't enter the stables again, you just left. Go check out the smith and see if he knows any information about the Evil King.\n";
			}
			if (get_world_location(row, col) == '<' and location_completed == 2) {
				movecursor(ROWS + 8, 0);
				cout << "You can't go into the well. There is nothing else that needs to be done in there.\n";
			}
			if (get_world_location(row, col) == 'T' and location_completed == 2) {
				movecursor(ROWS + 8, 0);
				cout << "You should probably visit the smith before going to the tavern. The stable hand said the blacksmith might know something!\n";
			}
			if (get_world_location(row, col) == 'E' and location_completed == 2) {
				movecursor(ROWS + 8, 0);
				cout << "You seriously want to face the Evil King while you are so unprepared?\n";
			}
			if (get_world_location(row, col) == '=' and location_completed == 2) {
				movecursor(ROWS + 8, 0);
				cout << "You have already completed the requests on the town board come back another time to check for more!\n";
			}
			if (get_world_location(row, col) == 'S') {
				movecursor(ROWS + 8, 0);
				cout << "Do you want to enter the smith? (Y/N)\n";
				if (c == 'Y') {
					smith_entrance++;
					break;
				}
			}
		}
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
	if (smith_entrance == 1) { //FIRST SMITH INSTANCE (COMPLETE)
		set_raw_mode(true);
		show_cursor(false);
		const int ROWS = smith_map.size();
		const int COLS = smith_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES
		const int FPS = 60;
		int row = ROWS / 2, col = COLS / 2;
		int last_row = -1, last_col = -1;//Save our last position so we only redraw on update
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
				print_smith(row, col); //...redraw the map
				last_row = row;
				last_col = col;
				if (quest_completed == 2) {
					movecursor(10, 16);
					cout << BOLDYELLOW << "S";
				}
				movecursor(6, 3);
				cout << RED << "[";
				movecursor(6, 5);
				cout << RED << "]";
				movecursor(7, 3);
				cout << RED << "[";
				movecursor(7, 5);
				cout << RED << "]";
				movecursor(8, 3);
				cout << RED << "[";
				movecursor(8, 5);
				cout << RED << "]";
				movecursor(9, 3);
				cout << RED << "[";
				movecursor(9, 5);
				cout << RED << "]";
				movecursor(10, 3);
				cout << RED << "[";
				movecursor(10, 5);
				cout << RED << "]";
				movecursor(6, 26);
				cout << RED << "[";
				movecursor(6, 28);
				cout << RED << "]";
				movecursor(7, 26);
				cout << RED << "[";
				movecursor(7, 28);
				cout << RED << "]";
				movecursor(8, 26);
				cout << RED << "[";
				movecursor(8, 28);
				cout << RED << "]";
				movecursor(9, 26);
				cout << RED << "[";
				movecursor(9, 28);
				cout << RED << "]";
				movecursor(10, 26);
				cout << RED << "[";
				movecursor(10, 28);
				cout << RED << "]";
				movecursor(6, 4);
				cout << BOLDRED << "F";
				movecursor(7, 4);
				cout << BOLDRED << "F";
				movecursor(8, 4);
				cout << BOLDRED << "F";
				movecursor(9, 4);
				cout << BOLDRED << "F";
				movecursor(10, 4);
				cout << BOLDRED << "F";
				movecursor(6, 27);
				cout << BOLDRED << "F";
				movecursor(7, 27);
				cout << BOLDRED << "F";
				movecursor(8, 27);
				cout << BOLDRED << "F";
				movecursor(9, 27);
				cout << BOLDRED << "F";
				movecursor(10, 27);
				cout << BOLDRED << "F";
				movecursor(11, 13);
				cout << BOLDBLACK << "_______";
				movecursor(8, 8);
				cout << BOLDBLACK << "|";
				movecursor(9, 8);
				cout << BOLDBLACK << "|";
				movecursor(9, 24);
				cout << BOLDBLACK << "|";
				movecursor(8, 24);
				cout << BOLDBLACK << "|";
				movecursor(12, 20);
				cout << BOLDBLACK << "|";
				movecursor(12, 12);
				cout << BOLDBLACK << "|";
				movecursor(8, 23);
				cout << BOLDBLACK << "=";
				movecursor(9, 23);
				cout << BOLDBLACK << "=";
				movecursor(9, 9);
				cout << BOLDBLACK << "=";
				movecursor(8, 9);
				cout << BOLDBLACK << "=";
				movecursor(12, 13);
				cout << BOLDRED << "=======";
				setcolor(144, 106, 42);
				movecursor(3, 7);
				cout << "o";
				movecursor(4, 10);
				cout << "o";
				movecursor(5, 7);
				cout << "o";
				movecursor(4, 4);
				cout << "o";
				movecursor(3, 6);
				cout << "_";
				movecursor(3, 8);
				cout << "_";
				movecursor(4, 9);
				cout << "|";
				movecursor(4, 5);
				cout << "|";
				movecursor(4, 6);
				cout << "___";
				movecursor(6, 8);
				cout << "|";
				movecursor(6, 10);
				cout << "|";
				movecursor(6, 22);
				cout << "|";
				movecursor(6, 24);
				cout << "|";
				movecursor(5, 23);
				cout << "_";
				movecursor(5, 9);
				cout << "_";
				setbgcolor(0, 204, 204);
				movecursor(6, 23);
				cout << "_";
				movecursor(6, 9);
				cout << "_";
				resetcolor();

				movecursor(2, COLS + 5);
				cout << BLUE << "ROW: " << row << RED << " COL: " << col << RESET;
				movecursor(5, COLS + 5);
				cout << RED  << "HP: " << WHITE << Health << endl; //FIXME: add color indictors to the HP
				movecursor(8, COLS + 5);
				cout << "Quest Tracker: " << quest_tracker;
				movecursor(11, COLS + 5);
				cout << "Current Task: ";
			}
			if (quest_completed > 0) {
				movecursor(14, COLS + 5);
				cout << "Quest Completed: " << GREEN << quest_completed;
			}
			movecursor(ROWS + 2, 0);
			setcolor(255, 0, 0);
			cout << "You have entered the smith!\n";
			resetcolor();
			if (quest_completed == 2) {
				movecursor(ROWS + 4, 0);
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel. (2/5)\n";
			}
			if (quest_completed == 3) {
				movecursor(ROWS + 4, 0);
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel. (3/5)\n";
			}
			if (quest_completed == 2) {
				cout.flush();
				movecursor(ROWS + 5, 0);
				cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (2/5) \n";
			}
			if (quest_completed == 3) {
				cout.flush();
				movecursor(ROWS + 5, 0);
				cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (3/5) \n";
			}
			movecursor(ROWS + 6, 0);
			cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
			if (quest_completed == 3) {
				movecursor(6, COLS + 5);
				cout << "Inventory: " << inv.at(0) << endl;
			}
			if (quest_completed == 4) {
				movecursor(6, COLS + 5);
				cout << "Inventory: " << inv.at(0) << " " << inv.at(1) << endl;
			}

			resetcolor();
			cout.flush();
			if (get_smith_location(row, col) == '^' and quest_completed != 3) {
				movecursor(ROWS + 8, 0);
				cout << "You want to leave already you haven't even talked to the smith!\n";
			}
			if (get_smith_location(row, col) == '^' and quest_completed == 3) {
				movecursor(ROWS + 8, 0);
				cout << "Do you want to exit the smith? (Y/N)\n";
				if (c == 'Y') break;
			}
			if (quest_completed == 3) {
				movecursor(2, 11);
				cout << BOLDYELLOW << "^^^^^^^^^^";
			}
			if (get_smith_location(row, col) == 'S' and quest_completed == 2) {
				movecursor(ROWS + 9, 0);
				cout << "            Well Well Well if it isn't the new Hero saving the Evil Kings prized Horse!\n";
				movecursor(ROWS + 10, 0);
				cout << "                  I heard you fought with the nasty rat down in the WELL as well.\n";
				movecursor(ROWS + 11, 0);
				cout << "     That Rats name was Keith, worst rat we've ever had the misfortune of meeting in our little kingdom.\n";
				movecursor(ROWS + 12, 0);
				cout << "We appreciate you taking care of em. Now tell me, do you think you're up to the task of defeating our Cursed King?\n";
				movecursor(ROWS + 13, 0);
				cout << "If so you should speak with the Kings wizard. He knows a trick or two when it comes to getting after our King.\n";
				movecursor(ROWS + 14, 0);
				cout << "                          You see our King is some what... invincible...\n";
				movecursor(ROWS + 15, 0);
				cout << "           I will tell you the wizards name and where he is if you can answer this riddle: \n";
				movecursor(ROWS + 16, 0);
				cout << "               What animal turns about 200 times around it's axis after it dies?\n";
				movecursor(ROWS + 18, 0);
				cout << "                       (1) ALLIGATORS (2) SNAKES (3) A ROASTED CHICKEN \n";
				if (c == '1' or c == '2') {
					movecursor(ROWS + 20, 0);
					cout << "              NO NO NO you haven't even tried to think about it have you?\n";
				}
				if (c == '3') {
					movecursor(ROWS + 20, 0);
					cout << "                    The wizard resides in the tavern and his name is Bob Lob Law.\n";
					movecursor(ROWS + 21, 0);
					cout << 	"He's kind of odd so beware of old Bob Lob Law's odd Bob Lob Law job that he might want you to do,\n";
					movecursor(ROWS + 22, 0);
					cout << "    	                  before giving you all of his secrets.\n";
					quest_completed++;
					inv.at(0) = "amulet";
					set_smith_location(row, col, 's');
					continue;
				}
			}
			if (quest_tracker == 0 and quest_completed == 2) {
				movecursor(12, COLS + 5);
				cout << YELLOW << "Speak with the Blacksmith.\n";
				resetcolor();
			}
			if (quest_tracker == 0 and quest_completed == 3) {
				movecursor(12, COLS + 5);
				cout << YELLOW << "Go to the tavern. Speak with the tavern keeper to find Bob Lob Law.\n";
				resetcolor();
			}
		}
		location_completed++;
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
	if (quest_completed == 3) { //FIFTH WORLD MAP INSTANCE (COMPLETE)
		print_world(row, col);
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
				if (quest_completed == 3) {
					movecursor(12, COLS + 5);
					cout << BOLDYELLOW << "Go to the tavern and ask the tavern keeper if they've seen Bob Lob Law.\n";
					resetcolor();
				}
				movecursor(15, COLS + 5);
				cout << "Quest Completed: " << GREEN << quest_completed;
				if (quest_completed == 3) {
					cout.flush();
					movecursor(ROWS + 5, 0);
					cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (3/5) \n";
					resetcolor();
				}
				movecursor(ROWS + 2, 0);
				setcolor(255, 0, 0);
				cout << "Welcome to the EVIL KING RECURSION'S DOMAIN\n";
				resetcolor();
				movecursor(ROWS + 4, 0);
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel. (3/5)\n";
				movecursor(ROWS + 6, 0);
				cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
				if (quest_completed == 3) {
					movecursor(6, COLS + 5);
					cout << "Inventory: " << inv.at(0) << endl;
				}
				if (quest_completed == 4) {
					movecursor(6, COLS + 5);
					cout << "Inventory: " << inv.at(0) << " " << inv.at(1) << endl;
				}

				movecursor(17, 39);
				cout << WHITE << "?";
				movecursor(24, 9);
				cout << BOLDYELLOW << "TAVERN";
				movecursor(8, 10);
				cout << GREEN << "SMITH";
				movecursor(11, 37);
				cout << GREEN << "WELL";
				movecursor(12, 68);
				cout << GREEN << "STABLE";
				movecursor(19, 69);
				cout << WHITE << "EVIL";
				movecursor(19, 74);
				cout << WHITE << "KING";
				movecursor(20, 71);
				cout << WHITE << "CASTLE";
				movecursor(17, 9);
				cout << BOLDYELLOW << "______";
				movecursor(5, 17);
				cout << BOLDBLACK << "|";
				movecursor(6, 17);
				cout << BOLDBLACK << "|";
				movecursor(9, 42);
				cout << BOLDBLACK << "|";
				movecursor(8, 68);
				cout << BOLDBLACK << "______";
				movecursor(18, 65);
				cout << WHITE << "|";
				movecursor(19, 65);
				cout << WHITE << "|";
				movecursor(20, 65);
				cout << WHITE << "|";
				movecursor(21, 65);
				cout << WHITE << "|";
				if (quest_accepted > 0) {
					set_world_location(16, 38, '=');
					movecursor(17, 39);
					cout << BOLDBLACK << "=";
					resetcolor();
				}
				resetcolor();
				cout.flush();
			}
			if (get_world_location(row, col) == '#' and location_completed == 3) {
				movecursor(ROWS + 8, 0);
				cout << "You done everything that needs to be done in the stables.\n";
			}
			if (get_world_location(row, col) == '<' and location_completed == 3) {
				movecursor(ROWS + 8, 0);
				cout << "Why are you still trying to go into the well you already know there is nothing down there.\n";
			}
			if (get_world_location(row, col) == 'S' and location_completed == 3) {
				movecursor(ROWS + 8, 0);
				cout << "You just came out of the smith why do you want to go in there again?\n";
			}
			if (get_world_location(row, col) == 'E' and location_completed == 3) {
				movecursor(ROWS + 8, 0);
				cout << "You still are entirely unprepared to face this king. I dont know whats going on in your head????\n";
			}
			if (get_world_location(row, col) == '=' and location_completed == 3) {
				movecursor(ROWS + 8, 0);
				cout << "You have already completed the requests on the town board come back another time to check for more!\n";
			}
			if (get_world_location(row, col) == 'T') {
				movecursor(ROWS + 8, 0);
				cout << "Do you want to enter the tavern? (Y/N)\n";
				if (c == 'Y') {
					tavern_entrance++;
					break;
				}
			}
		}
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
	if (tavern_entrance == 1) { //FIRST TAVERN INSTANCE (COMPLETE - kinda)
		set_raw_mode(true);
		show_cursor(false);
		const int ROWS = tavern_map.size();
		const int COLS = tavern_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES
		const int FPS = 60;
		int row = ROWS / 2, col = COLS / 2;
		int last_row = -1, last_col = -1;//Save our last position so we only redraw on update
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
				print_tavern(row, col); //...redraw the map
				last_row = row;
				last_col = col;
				setcolor(255, 229, 204);
				movecursor(14, 9);
				cout << "o";
				movecursor(14, 5);
				cout << "o";
				movecursor(11, 5);
				cout << "o";
				movecursor(11, 9);
				cout << "o";
				movecursor(11, 16);
				cout << "o";
				movecursor(14, 17);
				cout << "o";
				movecursor(14, 20);
				cout << "o";
				movecursor(11, 20);
				cout << "o";
				movecursor(9, 20);
				cout << "o";
				movecursor(9, 16);
				cout << "o";
				movecursor(7, 14);
				cout << "o";
				movecursor(6, 18);
				cout << "o";
				movecursor(6, 8);
				cout << "o";
				movecursor(6, 6);
				cout << "o";
				movecursor(9, 5);
				cout << "o";
				movecursor(9, 9);
				cout << "o";
				movecursor(5, 8);
				cout << "o";
				movecursor(5, 11);
				cout << "o";
				movecursor(5, 14);
				cout << "o";
				movecursor(5, 17);
				cout << "o";
				resetcolor();
				setcolor(144, 106, 42);
				movecursor(4, 7);
				cout << "|";
				movecursor(4, 18);
				cout << "|";
				movecursor(2, 21);
				cout << "|";
				movecursor(2, 4);
				cout << "|";
				movecursor(7, 4);
				cout << "|";
				movecursor(8, 4);
				cout << "|";
				movecursor(8, 10);
				cout << "|";
				movecursor(7, 10);
				cout << "|";
				movecursor(7, 15);
				cout << "|";
				movecursor(8, 15);
				cout << "|";
				movecursor(8, 21);
				cout << "|";
				movecursor(7, 21);
				cout << "|";
				movecursor(12, 21);
				cout << "|";
				movecursor(13, 21);
				cout << "|";
				movecursor(13, 15);
				cout << "|";
				movecursor(12, 15);
				cout << "|";
				movecursor(12, 10);
				cout << "|";
				movecursor(13, 10);
				cout << "|";
				movecursor(13, 4);
				cout << "|";
				movecursor(12, 4);
				cout << "|";
				movecursor(6, 5);
				cout << "_";
				movecursor(6, 7);
				cout << "_";
				movecursor(6, 9);
				cout << "_";
				movecursor(8, 5);
				cout << "_____";
				movecursor(6, 16);
				cout << "__";
				movecursor(6, 19);
				cout << "__";
				movecursor(8, 16);
				cout << "_____";
				movecursor(11, 17);
				cout << "___";
				movecursor(13, 16);
				cout << "_____";
				movecursor(13, 5);
				cout << "_____";
				movecursor(11, 6);
				cout << "___";
				resetcolor();
				movecursor(3, 8);
				cout << RED << "____";
				movecursor(3, 14);
				cout << RED << "____";
				movecursor(4, 8);
				cout << RED << "__________";
				movecursor(2, 5);
				cout << RED << "_";
				movecursor(2, 8);
				cout << RED << "__";
				movecursor(2, 12);
				cout << RED << "__";
				movecursor(2, 16);
				cout << RED << "__";
				movecursor(2, 20);
				cout << RED << "_";

				movecursor(2, COLS + 5);
				cout << BLUE << "ROW: " << row << RED << " COL: " << col << RESET;
				movecursor(5, COLS + 5);
				cout << RED  << "HP: " << WHITE << Health << endl; //FIXME: add color indictors to the HP
				movecursor(8, COLS + 5);
				cout << "Quest Tracker: " << quest_tracker;
				movecursor(11, COLS + 5);
				cout << "Current Task: ";
			}
			if (quest_completed >= 0) {
				movecursor(14, COLS + 5);
				cout << "Quest Completed: " << GREEN << quest_completed;
			}
			movecursor(ROWS + 2, 0);
			setcolor(255, 0, 0);
			cout << "You have entered the tavern!\n";
			resetcolor();
			if (quest_completed == 3) {
				movecursor(3, 12);
				cout << BOLDYELLOW << "T";
				movecursor(ROWS + 4, 0);
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel. (3/5)\n";
				movecursor(ROWS + 5, 0);
				cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (3/5) \n";
			}
			if (location_completed  == 4) {
				movecursor(3, 12);
				cout << BOLDYELLOW << "W";
				movecursor(3, 13);
				cout << RED << "_";
				movecursor(15, 14);
				cout << BOLDYELLOW << "/";
				movecursor(ROWS + 4, 0);
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel. (4/5)\n";
				movecursor(ROWS + 5, 0);
				cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (4/5) \n";
			}
			movecursor(ROWS + 6, 0);
			cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
			if (quest_completed == 3) {
				movecursor(6, COLS + 5);
				cout << "Inventory: " << inv.at(0) << endl;
			}
			if (quest_completed == 4) {
				movecursor(6, COLS + 5);
				cout << "Inventory: " << inv.at(0) << " " << inv.at(1) << endl;
			}

			resetcolor();
			cout.flush();
			if (get_tavern_location(row, col) == '/' and location_completed != 4) {
				movecursor(ROWS + 8, 0);
				cout << "Better talk to the Tavern Keeper and solve his riddles.\n";
				if (c == 'Y') break;
			}
			if (get_tavern_location(row, col) == '/' and location_completed == 4) {
				movecursor(ROWS + 8, 0);
				cout << "Do you want to exit the tavern? (Y/N)\n";
				if (c == 'Y') break;
			}
			if (quest_completed == 4) {
				movecursor(12, COLS + 5);
				cout << BOLDYELLOW << "Go to the Evil Kings Castle and slay the King.\n";
			}
			resetcolor();
			if (quest_completed == 3) {
				movecursor(12, COLS + 5);
				cout << BOLDYELLOW << "Speak with the tavern keeper and ask about Bob Lob Law.\n";
				resetcolor();
			}
			if (get_tavern_location(row, col) == 'T' and quest_completed == 3) {
				movecursor(ROWS + 9, 0);
				cout << "                            Ah you look mighty fine my young adventurer, why don't you have a seat right over here and listen to me tell you a tale!\n";
				movecursor(ROWS + 10, 0);
				cout << "First I shall introduce myself I am Bob Lob law the Wizard. It all started a long time ago when my father Bob Law and my mother Ms.Lob law Law came into the serive of the once beloved King.\n";
				movecursor(ROWS + 11, 0);
				cout << "                         *Bob lob Law keeps talking in great detail about his families history and serice of the king until you almost fall asleep*.\n";
				movecursor(ROWS + 12, 0);
				cout << "                     So it was my father's Great Bob lob Law, Bob lob law lob law the third who ended up cursing the King and caused all this suffering.\n";
				movecursor(ROWS + 13, 0);
				cout << "                     However I know how to end the Cursed Kings reign, but first I must make sure you are worth of this task. Are you up to the challenge?\n";
				movecursor(ROWS + 14, 0);
				cout << "                                         Would you like Bob lob Law to test you and see if you are up to the challenge? (Y/N)\n";
				if (c == 'Y') {
					movecursor(ROWS + 16, 0);
					cout << "                                                   First riddle: What do you call a deer with no eyes \n";
					movecursor(ROWS + 17, 0);
					cout << "                                                                    Hint: NO IDEA\n";
					movecursor(ROWS + 18, 0);
					cout << "                                                     (1) NO EYE DEER. (2) SOME EYE DEER. (3) WHAT? \n";
				}
				if (c == '1') {
					movecursor(ROWS + 19, 0);
					cout << "                                                          Very well, on to the next riddle.\n";
					movecursor(ROWS + 20, 0);
					cout << "                                                                    What's 2+2?\n";
				}
				if (c == '4') {
					movecursor(ROWS + 21, 0);
					cout << "                                                   You're more clever then you seem. LAST RIDDLE!\n";
					movecursor(ROWS + 22, 0);
					cout << "                  When young, I am sweet in the sun. When middle-aged, I make you gay. When old, I am valued more than ever. What am i?\n";
					movecursor(ROWS + 23, 0);
					cout << "                                                       (a) WINE (b) WATER (c) AGAIN... WHAT??\n";
				}
			}
			if (c == 'A') {
				movecursor(ROWS + 16, 0);
				cout << "                                        Well done young hero, it seems you are worthy of the secrets I posses!\n";
				movecursor(ROWS + 17, 0);
				cout << "                                          Too defeat the King you must recite the incantation of recursion.\n";
				movecursor(ROWS + 18, 0);
				cout << "                    It starts with a Crumble, then a Tumble, then a Rumble, then a Lightbulb, and ends with a Clandestine exchange of power.\n";
				movecursor(ROWS + 19, 0);
				cout << "                           This Incantation and the amulet is what you need to defeat the evil King. Now go forth and end this curse!\n";
				quest_completed++;
				location_completed++;
				inv.at(1) = "Incantation";
			}
		}
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
	if (quest_completed == 4) { //SIXTH WORLD MAP INSTANCE (COMPLETE)
		print_world(row, col);
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
				if (quest_completed == 4) {
					movecursor(12, COLS + 5);
					cout << BOLDYELLOW << "Make way to the Evil King's Castle.\n";
					resetcolor();
				}
				movecursor(15, COLS + 5);
				cout << "Quest Completed: " << GREEN << quest_completed;
				if (quest_completed == 4) {
					cout.flush();
					movecursor(ROWS + 5, 0);
					cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (4/5) \n";
					resetcolor();
				}
				movecursor(ROWS + 2, 0);
				setcolor(255, 0, 0);
				cout << "Welcome to the EVIL KING RECURSION'S DOMAIN\n";
				resetcolor();
				movecursor(ROWS + 4, 0);
				cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel. (4/5)\n";
				movecursor(ROWS + 6, 0);
				cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
				if (quest_completed == 3) {
					movecursor(6, COLS + 5);
					cout << "Inventory: " << inv.at(0) << endl;
				}
				if (quest_completed == 4) {
					movecursor(6, COLS + 5);
					cout << "Inventory: " << inv.at(0) << " " << inv.at(1) << endl;
				}

				movecursor(17, 39);
				cout << WHITE << "?";
				movecursor(24, 9);
				cout << GREEN << "TAVERN";
				movecursor(8, 10);
				cout << GREEN << "SMITH";
				movecursor(11, 37);
				cout << GREEN << "WELL";
				movecursor(12, 68);
				cout << GREEN << "STABLE";
				movecursor(19, 69);
				cout << BOLDYELLOW << "EVIL";
				movecursor(19, 74);
				cout << BOLDYELLOW << "KING";
				movecursor(20, 71);
				cout << BOLDYELLOW << "CASTLE";
				movecursor(17, 9);
				cout << BOLDBLACK << "______";
				movecursor(5, 17);
				cout << BOLDBLACK << "|";
				movecursor(6, 17);
				cout << BOLDBLACK << "|";
				movecursor(9, 42);
				cout << BOLDBLACK << "|";
				movecursor(8, 68);
				cout << BOLDBLACK << "______";
				movecursor(18, 65);
				cout << BOLDYELLOW << "|";
				movecursor(19, 65);
				cout <<	BOLDYELLOW << "|";
				movecursor(20, 65);
				cout << BOLDYELLOW << "|";
				movecursor(21, 65);
				cout << BOLDYELLOW << "|";
				if (quest_accepted > 0) {
					set_world_location(16, 38, '=');
					movecursor(17, 39);
					cout << BOLDBLACK << "=";
					resetcolor();
				}
				resetcolor();
				cout.flush();
			}
			if (get_world_location(row, col) == '#' and location_completed == 4) {
				movecursor(ROWS + 8, 0);
				cout << "You done everything that needs to be done in the stables.\n";
			}
			if (get_world_location(row, col) == '<' and location_completed == 4) {
				movecursor(ROWS + 8, 0);
				cout << "Really you are still trying...\n";
			}
			if (get_world_location(row, col) == 'S' and location_completed == 4) {
				movecursor(ROWS + 8, 0);
				cout << "The smith's shop is closed must have known you were about to stir up some havoc in the kingdom.\n";
			}
			if (get_world_location(row, col) == 'T' and location_completed == 4) {
				movecursor(ROWS + 8, 0);
				cout << "You just came out of the tavern you seriously want to go talk to Bob Lob Law more?\n";
			}
			if (get_world_location(row, col) == '=' and location_completed == 4) {
				movecursor(ROWS + 8, 0);
				cout << "You have already completed the requests on the town board come back another time to check for more!\n";
			}
			if (get_world_location(row, col) == 'E') {
				movecursor(ROWS + 8, 0);
				cout << "The time has come are you read to face the Evil King? (Y/N)\n";
				if (c == 'Y') {
					castle_entrance++;
					break;
				}
			}
		}
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
	if (castle_entrance == 1) { //FINAL BOSS (NUTT COMPLETE)
		const int ROWS = castle_map.size();
		const int COLS = castle_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES
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
				print_castle(row, col); //...redraw the map
				last_row = row;
				last_col = col;
				setcolor(144, 106, 42);
				movecursor(2, 6);
				cout << "_______";
				movecursor(7, 6);
				cout << "_______";
				movecursor(2, 24);
				cout << "_______";
				movecursor(7, 24);
				cout << "_______";
				movecursor(2, 42);
				cout << "_______";
				movecursor(7, 42);
				cout << "_______";
				movecursor(3, 5);
				cout << "|";
				movecursor(4, 5);
				cout << "|";
				movecursor(5, 5);
				cout << "|";
				movecursor(6, 5);
				cout << "|";
				movecursor(7, 5);
				cout << "|";
				movecursor(3, 13);
				cout << "|";
				movecursor(4, 13);
				cout << "|";
				movecursor(5, 13);
				cout << "|";
				movecursor(6, 13);
				cout << "|";
				movecursor(7, 13);
				cout << "|";
				movecursor(3, 23);
				cout << "|";
				movecursor(4, 23);
				cout << "|";
				movecursor(5, 23);
				cout << "|";
				movecursor(6, 23);
				cout << "|";
				movecursor(7, 23);
				cout << "|";
				movecursor(3, 31);
				cout << "|";
				movecursor(4, 31);
				cout << "|";
				movecursor(5, 31);
				cout << "|";
				movecursor(6, 31);
				cout << "|";
				movecursor(7, 31);
				cout << "|";
				movecursor(3, 41);
				cout << "|";
				movecursor(4, 41);
				cout << "|";
				movecursor(5, 41);
				cout << "|";
				movecursor(6, 41);
				cout << "|";
				movecursor(7, 41);
				cout << "|";
				movecursor(3, 49);
				cout << "|";
				movecursor(4, 49);
				cout << "|";
				movecursor(5, 49);
				cout << "|";
				movecursor(6, 49);
				cout << "|";
				movecursor(7, 49);
				cout << "|";
				resetcolor();
				setcolor(255, 229, 204);
				movecursor(10, 18);
				cout << "||";
				movecursor(11, 18);
				cout << "||";
				movecursor(12, 18);
				cout << "||";
				movecursor(10, 35);
				cout << "||";
				movecursor(11, 35);
				cout << "||";
				movecursor(12, 35);
				cout << "||";
				resetcolor();
				setcolor(255, 128, 0);
				movecursor(5, 17);
				cout << "(";
				movecursor(5, 19);
				cout << ")";
				movecursor(5, 35);
				cout << "(";
				movecursor(5, 37);
				cout << ")";
				movecursor(10, 44);
				cout << "(";
				movecursor(10, 46);
				cout << ")";
				movecursor(10, 26);
				cout << "(";
				movecursor(10, 28);
				cout << ")";
				movecursor(10, 8);
				cout << "(";
				movecursor(10, 10);
				cout << ")";
				resetcolor();
				movecursor(5, 18);
				cout << RED << "F";
				movecursor(5, 36);
				cout << RED << "F";
				movecursor(10, 45);
				cout << RED << "F";
				movecursor(10, 27);
				cout << RED << "F";
				movecursor(10, 9);
				cout << RED << "F";
				movecursor(2, COLS + 5);
				cout << BLUE << "ROW: " << row << RED << " COL: " << col << RESET;
				movecursor(5, COLS + 5);
				cout << RED  << "HP: " << WHITE << Health << endl; //FIXME: add color indictors to the HP
				movecursor(8, COLS + 5);
				cout << "Quest Tracker: " << quest_tracker;
				movecursor(11, COLS + 5);
				cout << "Current Task: ";
				if (quest_completed == 4) {
					movecursor(9, 50);
					cout << BOLDYELLOW << "K";
					movecursor(12, COLS + 5);
					cout << BOLDYELLOW << "DEFEAT THE EVIL KING (0/1)";
					resetcolor();
				}
				movecursor(15, COLS + 5);
				cout << "Quest Completed: " << GREEN << quest_completed;
				resetcolor();
				if (quest_completed == 4) {
					cout.flush();
					movecursor(ROWS + 5, 0);
					cout << "             " << YELLOW << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (4/5) \n";
					movecursor(ROWS + 4, 0);
					cout << CYAN << "Objectives : " << YELLOW <<  "(1) Go to each of the marked locations to gather intel. (4/5)\n";
					resetcolor();
				}
				movecursor(ROWS + 2, 0);
				setcolor(255, 0, 0);
				cout << "You have entered the Throne Room!\n";
				resetcolor();
				movecursor(ROWS + 6, 0);
				cout << "             " << YELLOW << "(3) Slay the Evil King to restore peace in the domain\n";
				if (quest_completed == 3) {
					movecursor(6, COLS + 5);
					cout << "Inventory: " << inv.at(0) << endl;
				}
				if (quest_completed == 4) {
					movecursor(6, COLS + 5);
					cout << "Inventory: " << inv.at(0) << " " << inv.at(1) << endl;
				}

				resetcolor();
				cout.flush();
			}
			if (get_castle_location(row, col) == 'K') {
				movecursor(ROWS + 8, 0);
				cout << "             You have come into the Castle of Recursion, who dares challange the might of my never ending power?!!\n";
				movecursor(ROWS + 9, 0);
				cout << "Ahh the one who has been helping the poor oppressed villagers... pity that you are too weak to stop the might of the Recursion King!\n";
				movecursor(ROWS + 10, 0);
				cout << "                               Now witness my never ending Power! *extra credit please*\n";
				movecursor(ROWS + 12, 0);
				cout << "                                                 Would you like to: \n";
				movecursor(ROWS + 13, 0);
				cout << "                                     (1) Attack (2) Defend (3) Use the Amulet \n";
				if (c == '1') {
					kingHP -= 33;
					Health -= 10;
					movecursor(ROWS + 15, 0);
					cout << "You have: " << Health << " HP left                                                                             \n";
					movecursor(ROWS + 16, 0);
					cout << "The King has: " << kingHP << " HP Left                                                                             \n";
					movecursor(ROWS + 17, 0);
					cout << "                                                                                                                                               \n";
					continue;

				} else if (c == '2') {
					Health -= 10;
					movecursor(ROWS + 15, 0);
					cout << Health << " HP Left                                                                                                \n";
					movecursor(ROWS + 16, 0);
					cout << kingHP << " HP Left                                                                                                  \n";
					movecursor(ROWS + 17, 0);
					cout << "                                                                                                                                               \n";
					continue;
				} else if (c == '3') {
					movecursor(ROWS + 15, 0);
					cout << "                           You begin to chant the incantation to end the Recursive spell.\n";
					movecursor(ROWS + 16, 0);
					cout << "                   C, T, R, L... whats the last part again? Damnit Keith what was the incantation!\n";
					movecursor(ROWS + 17, 0);
					cout << "                                 Please enter the last part of the incantation.\n";
					continue;
				}

				if (c == 'C') {
					quest_completed++;
					movecursor(ROWS + 15, 0);
					cout << "                        No! You fool! How could you have known the most powerful spell to end my Reign!\n";
					movecursor(ROWS + 16, 0);
					cout << "                                    Curse you! CURSE YOOOOOOOOOOOOO....\n";
					movecursor(ROWS + 17, 0);
					cout << "                                        The Evil King has been stopped.. for now.\n";
					movecursor(ROWS + 18, 0);
					cout << "                              Well done Hero you have earned the title of 'Coding Crusader'.\n";
					if (quest_completed == 5) {
						cout.flush();
						movecursor(ROWS + 5, 0);
						cout << "             " << GREEN << "(2) Complete 5 tasks from the marked locations and the town board ->(?) (5/5) \n";
						movecursor(ROWS + 4, 0);
						cout << CYAN << "Objectives : " << GREEN <<  "(1) Go to each of the marked locations to gather intel. (5/5)\n";
						movecursor(ROWS + 6, 0);
						cout << "             " << GREEN << "(3) Slay the Evil King to restore peace in the domain\n";
						movecursor(12, COLS + 5);
						cout << GREEN << "DEFEAT THE EVIL KING (1/1)\n";
						movecursor(6, COLS + 5);
						cout << GREEN << "Inventory: empty                                                                              \n";
						movecursor(15, COLS + 5);
						cout << "Quest Completed: " << GREEN << "5" << "                                                                 \n";

					}

					resetcolor();
					usleep(10'000'000);
					break;
				}
				if (kingHP <= 0) {
					movecursor(ROWS + 15, 0);
					cout << "Fool you cannot defeat me! I AM... NEVER ENDING!                                                                                   \n";
					kingHP = 1000;
				}
				if (Health <= 0) {
					movecursor(ROWS + 15, 0);
					cout << "Wait, arent I suppose to be dead? What is happening?                                                                                       \n";
					movecursor(ROWS + 16, 0);
					cout << "The King laughs manically                                                                                                                   \n";
					movecursor(ROWS + 17, 0);
					cout << "Welcome to a never ending Hell, now FIGHT ME!                                                                                                  \n";
					Health += 50;
				}

			}
			resetcolor();
			cout.flush();
		}
		location_completed++;
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();
}

