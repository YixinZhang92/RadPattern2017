all: myprogram

myprogram: prototypes.o main.o prototypes.o displacement.o \
	   radiation.o writing.o
	g++ -o myprogram -lstdc++ prototypes.o main.o \
	       displacement.o radiation.o writing.o

prototypes.o: prototypes.cpp
	g++ -c prototypes.cpp -lstdc++

displacement.o: displacement.cpp
	g++ -c displacement.cpp -lstdc++

radiation.o: radiation.cpp
	g++ -c radiation.cpp -lstdc++

writing.o: writing.cpp
	g++ -c writing.cpp -lstdc++

main.o: main.cpp
	g++ -c main.cpp -lstdc++

cleanall:
	rm myprogram *.o login.txt outputfilename.txt 
	rm -r html/ latex/
