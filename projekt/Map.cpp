// TODO Czy mapa jest prawidłowa (rozmiary i znaczki)
#include "Map.h"
#include "RoadField.h"

Map::Map(vector<string> lines, int N, int M) : N(N), M(M){

	for(int i=0; i<N; i++){
		vector<Field*> row;
		for(int j=0; j<M; j++){
			switch(lines[i][j]){
				case '=': row.push_back(new RoadField()); break;
				// TODO pozostałe znaki
				//default: //TODO: zły znak - wyrzuć błąd, że zła mapa
			}
		}
		fields.push_back(row);
	}
}
