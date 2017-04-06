all: myprogram

myprogram: prototypes.o main.o
	g++ -o myprogram -lstdc++ prototypes.o main.o

prototypes.o: prototypes.cpp
	g++ -c prototypes.cpp -lstdc++

main.o: main.cpp
	g++ -c main.cpp -lstdc++

clean:
	rm myprogram *.o

cleanall:
	rm myprogram *.o login.txt outputfilename.txt
	rm -r html/ latex/ 
