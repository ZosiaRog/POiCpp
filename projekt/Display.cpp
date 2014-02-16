#include "Display.h"
#include "Map.h"
#include <string>
using namespace std;

#include "MiloszCharacter.h"

void Display::init(){
	initscr();			/* Start curses mode 		  */
	raw(); 
	noecho();
	keypad(stdscr, TRUE);
	start_color();
}
void Display::stop(){
	endwin();			/* End curses mode		  */
}
void Display::refreshView(Map* map, MiloszCharacter* milosz){
	move(0,0);
	printw("Poruszaj sie strzalkami.");
	move(1,0);
	printw("Wybierz 'n', aby zrezygnowac z ruchu i 'q', aby skonczyc gre.");
	move(3,0);
	printw("Zdrowie ");
	printw("%d", milosz->getHealth());
	printw("  Bron ");
	if (milosz->getWeapon()) { 
		printw("%.2lf", milosz->getWeapon()->getStrength());
	} else {
		printw(" --- ");
	}
	printw("  Zbroja ");
	if (milosz->getArmor()) { 
		printw("%.2lf", milosz->getArmor()->getStrength());
	} else {
		printw(" --- ");
	}
	if(milosz->getGift()) {
		printw("  Prezent ");
	} else {
		printw("          ");
	}
	printw("Punkty akcji ");
	printw("%d    ", milosz->getActionPoints());

	initColors();
	int N = map->getN();
	int M = map->getM();
	for (int i = 0; i < N+2; i++){
		for (int j = 0; j < M+2; j++){
			char symb = (map->getField(i, j)->getSymbolToShow());
			drawField(i, j, symb);
		}
	}
	refresh();			/* Print it on to the real screen */
}

void Display::initColors(){
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_CYAN, COLOR_BLACK);
		init_pair(10, COLOR_RED, COLOR_BLACK);
		init_pair(11, COLOR_CYAN, COLOR_BLACK);
		init_pair(20, COLOR_GREEN, COLOR_BLACK);
		init_pair(21, COLOR_MAGENTA, COLOR_BLACK);

		symbColors['$'] = 10;
		symbColors['S'] = 20;
		symbColors['Z'] = 20;
		symbColors['B'] = 20;
		symbColors['M'] = 10;
		symbColors['P'] = 21;
		symbColors['N'] = 21;
		symbColors['W'] = 21;
		symbColors['T'] = 21;
		symbColors['A'] = 21;
}

void print_in_middle(WINDOW* win, int starty, int startx, int width, string str)
{	int length, x, y;
	float temp;

	win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = str.length();
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", str.c_str());
	refresh();
}

void Display::congratulations() {
	attron(COLOR_PAIR(1));
	print_in_middle(stdscr, LINES / 2, 0, 0, "Viola !!! Treasure :D ");
	getch();
}
void Display::gameOver(){
	attron(COLOR_PAIR(2));
	print_in_middle(stdscr, LINES / 2, 0, 0, "Game over :( :( ");
	getch();
}

void Display::treasureFound(){
	attron(COLOR_PAIR(2));
	print_in_middle(stdscr, LINES / 2, 0, 0, "Treasure found. Game over.");
	getch();
}
void Display::youDied(){
	attron(COLOR_PAIR(2));
	print_in_middle(stdscr, LINES / 2, 0, 0, "You died.");
	getch();
} 

void Display::drawField(int i, int j, char c){
	int col = 0;
	if(symbColors.count(c)){
		col = symbColors[c];
	}
	
	attron(COLOR_PAIR(col));
	mvaddch(i + 5, j, c);
	attroff(COLOR_PAIR(col));
}

int Display::getCommand(){
	int command = getch();
	if(command == 'q'){
		end_game = true;
	}
	return command;
}
