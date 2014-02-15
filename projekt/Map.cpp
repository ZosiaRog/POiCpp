// TODO Czy mapa jest prawidłowa (rozmiary i znaczki)
#include "Map.h"
#include "VariousFields.h"

Map::Map(vector<string> lines, int N, int M) : N(N), M(M){
	pair<int, int> position;
	vector<Field*> rocks_row_upper, rocks_row_lower;
	for(int j=0; j<M+2; j++){
		position = make_pair(0, j);
		rocks_row_upper.push_back(new RockField(position));
		position = make_pair(M+1, j);
		rocks_row_lower.push_back(new RockField(position));
	}
	fields.push_back(rocks_row_upper);

	for(int i=1; i<=N; i++){
		vector<Field*> row;
		position = make_pair(i, 0);
		row.push_back(new RockField(position));
		for(int j=1; j<=M; j++){
			pair<int, int> position = make_pair(i, j);
			switch(lines[i][j]){
				case '=': row.push_back(new RoadField(position)); break;
				case '#': row.push_back(new RockField(position)); break;
				case '^': row.push_back(new HillField(position)); break;
				case '.': row.push_back(new GrassField(position)); break;
				case '&': row.push_back(new SwampField(position)); break;
				case '~': row.push_back(new RiverField(position)); break;
				case '*': row.push_back(new CaveField(position)); break;
				case '$': row.push_back(new TreasureField(position)); break;
		//		default: std::cerr << "Niepoprawna mapa." << std::endl; TODO Dodaj wyjątek
			}
		}
		pair<int, int> position = make_pair(i, M+1);
		row.push_back(new RockField(position));
		fields.push_back(row);
	}

	fields.push_back(rocks_row_lower);
}

void Map::putCharacter(Character* character){
	pair<int, int> position = character->getPosition();
	getField(position.first, position.second)->putCharacter(character);
}

void Map::grabCharacter(Character* character){
	pair<int, int> position = character->getPosition();
	getField(position.first, position.second)->grabCharacter();

}

void Map::buryDead(Character* character){
	pair<int, int> position = character->getPosition();
	Field* field = getField(position.first, position.second);
	field->buryDead();
}

void Map::moveCharacter(Character* character, Field* wanted_field) { 
	grabCharacter(character);
	character->setPosition(wanted_field->getPosition());
	putCharacter(character);
}
