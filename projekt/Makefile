PROG_NAME = milosz
OBJ = Game.o Map.o 2_Field.o 2_RoadField.o 2_RockField.o 2_HillField.o 2_GrassField.o 2_SwampField.o 2_RiverField.o 2_CaveField.o 2_TreasureField.o 1_Character.o 1_BardCharacter.o 1_QuackDoctorCharacter.o 1_InnkeeperCharacter.o 1_NeutralCharacter.o 1_CowardCharacter.o 1_FussyCharacter.o 1_AgressiveCharacter.o  1_MiloszCharacter.o 1_SearcherCharacter.o

all: $(PROG_NAME)
	
$(PROG_NAME): $(PROG_NAME).cpp $(OBJ)
	g++ $^ -o $(PROG_NAME)

%.o: %.cpp %.h
	g++ -c $^

clean:
	rm *~ *.o *.gch
