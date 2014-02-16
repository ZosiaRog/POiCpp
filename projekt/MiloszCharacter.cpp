#include "MiloszCharacter.h"

#include <ncurses.h>


Field* MiloszCharacter::move(vector <Field*> neighbourhood){ 
	while(true){
		int c = display->getCommand();
		switch (c) {
			case KEY_UP: return neighbourhood[1]; break;
			case KEY_DOWN: return neighbourhood[3]; break;
			case KEY_LEFT: return neighbourhood[0]; break;
			case KEY_RIGHT: return neighbourhood[2]; break;
			case 'n': return NULL; break;
			case 'q': return NULL; break;
		}
	}
}

