#include "Display.h"
#include "Map.h"

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

	int N = map->getN();
	int M = map->getM();
	for (int i = 0; i < N+2; i++){
		for (int j = 0; j < M+2; j++){
			char symb = (map->getField(i, j)->getSymbolToShow());
			mvaddch(i + 2, j, symb);
		}
	}
	refresh();			/* Print it on to the real screen */
}

int Display::getCommand(){
	int command = getch();
	if(command == 'q'){
		end_game = true;
	}
	return command;
}
