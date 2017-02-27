all: myprogram

myprogram: prototypes.o main.o
	g++ -o myprogram prototypes.o main.o

prototypes.o: prototypes.cpp
	g++ -c prototypes.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm myprogram *.o
