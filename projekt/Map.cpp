// TODO Czy mapa jest prawidłowa (rozmiary i znaczki)
#include "Map.h"
#include "RoadField.h"
#include "RockField.h"
#include "HillField.h"
#include "GrassField.h"
#include "SwampField.h"
#include "RiverField.h"
#include "CaveField.h"
#include "TreasureField.h"

Map::Map(vector<string> lines, int N, int M) : N(N), M(M){

	for(int i=0; i<N; i++){
		vector<Field*> row;
		for(int j=0; j<M; j++){
			switch(lines[i][j]){
				case '=': row.push_back(new RoadField()); break;
				case '#': row.push_back(new RockField()); break;
				case '^': row.push_back(new HillField()); break;
				case '.': row.push_back(new GrassField()); break;
				case '&': row.push_back(new SwampField()); break;
				case '~': row.push_back(new RiverField()); break;
				case '*': row.push_back(new CaveField()); break;
				case '$': row.push_back(new TreasureField()); break;
		//		default: std::cerr << "Niepoprawna mapa." << std::endl; TODO Dodaj wyjątek
			}
		}
		fields.push_back(row);
	}
}

void Map::putCharacter(Character* character){
	pair<int, int> position = character->getPosition();
	getField(position.first, position.second)->putCharacter(character);
}
