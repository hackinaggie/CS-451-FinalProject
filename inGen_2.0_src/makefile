CC = g++
INCLUDE = Alarm.h Asset.h Camera.h ElectricalSystem.h Entry.h  helpers.h Inventory.h ParkSections.h
FLAGS = -std=c++11
OBJ = Alarm.o Asset.o Camera.o ElectricalSystem.o Entry.o Inventory.o main.o

%.o: %.c $(INCLUDE)
	$(CC) -c -o $@ %< $(FLAGS)

inGen_2.0: $(OBJ)
	$(CC) *.o -o $@ $(FLAGS)

all: inGen_2.0

run: inGen_2.0
	./inGen_2.0

clean:
	rm *.o inGen_2.0
