PROG_NAME = milosz
OBJ = Game.o Map.o Field.o VariousFields.o Character.o FightingCharacter.o WildCharacters.o IntelligentCharacters.o MiloszCharacter.o SearcherCharacter.o Display.o

all: $(PROG_NAME)
	
$(PROG_NAME): $(PROG_NAME).cpp $(OBJ)
	g++ $^ -o $(PROG_NAME) -lncurses 

%.o: %.cpp %.h
	g++ -c $^ 

clean:
	rm *~ *.o *.gch 
