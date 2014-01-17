PROG_NAME = milosz
OBJ = Game.o Map.o Field.o RoadField.o Character.o

all: $(PROG_NAME)
	
$(PROG_NAME): $(PROG_NAME).cpp $(OBJ)
	g++ $^ -o $(PROG_NAME)

%.o: %.cpp %.h
	g++ -c $^

clean:
	rm *~ *.o *.gch
