CC = g++
INCLUDE = Alarm.h Asset.h Camera.h ElectricalSystem.h Entry.h Hash.h helpers.h Inventory.h ParkSections.h
FLAGS = -std=c++11
OBJ = Alarm.o Asset.o Camera.o ElectricalSystem.o Entry.o Hash.o Inventory.o main.o

%.o: %.c $(INCLUDE)
	$(CC) -c -o $@ %< $(FLAGS)

inGen_1.0: $(OBJ)
	$(CC) *.o -o $@ $(FLAGS)

all: inGen_1.0

run: inGen_1.0
	./inGen_1.0

clean:
	rm *.o inGen_1.0
