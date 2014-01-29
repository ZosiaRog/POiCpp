PROG_NAME = milosz
OBJ = Game.o Map.o Field.o RoadField.o RockField.o HillField.o GrassField.o SwampField.o RiverField.o CaveField.o TreasureField.o Character.o BardCharacter.o

# QuackDoctorCharacter.o InnkeeperCharacter.o NeutralCharacter.o CowardCharacter.o FussyCharacter.o AgressiveCharacter.o  MiloszCharacter.o SearcherCharacter.o

all: $(PROG_NAME)
	
$(PROG_NAME): $(PROG_NAME).cpp $(OBJ)
	g++ $^ -o $(PROG_NAME)

%.o: %.cpp %.h
	g++ -c $^

clean:
	rm *~ *.o *.gch
