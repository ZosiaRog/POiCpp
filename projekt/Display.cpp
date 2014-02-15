#include "Display.h"
#include "Map.h"


void Display::init(){
	initscr();			/* Start curses mode 		  */
	//raw(); 
	noecho();
	keypad(stdscr, TRUE);
}
void Display::stop(){
	endwin();			/* End curses mode		  */
}
void Display::refreshView(Map* map, MiloszCharacter* milosz){
	move(0,0);
	printw("Zdrowie ");
	printw("%d", milosz->getHealth());
	printw("  Bron ");
	printw("%.2lf", milosz->getWeapon());
	printw("  Zbroja ");
	printw("%.2lf", milosz->getArmor());
	if(milosz->getGift()) printw("  Prezent ");

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
