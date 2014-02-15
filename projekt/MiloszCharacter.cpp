#include "MiloszCharacter.h"

Field* MiloszCharacter::move(vector <Field*> neighbourhood){ 
	while(true){
		char x;
		cout << "ACTION PTS: " << actual_action_points << " HPTS: " << health << endl;
		cout << "Podaj kierunek (g, d, l, p): " << endl;
		cin >> x;
		switch (x) {
			case 'g': return neighbourhood[1]; break;
			case 'd': return neighbourhood[3]; break;
			case 'l': return neighbourhood[0]; break;
			case 'p': return neighbourhood[2]; break;
			default: cout << "Nieprawidłowy znak." << endl;
		}
	}
}

