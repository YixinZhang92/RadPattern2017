CC = g++

CFLAGS = -Wall

all: myprogram

prototypes.o: prototypes.cpp
	${CC} ${CFLAGS} -c prototypes.cpp 

read_in.o: read_in.cpp
	${CC} ${CFLAGS} -c read_in.cpp 

mesh_gen_o.o: mesh_gen_o.cpp
	${CC} ${CFLAGS} -c mesh_gen_o.cpp

myprogram: prototypes.o read_in.o mesh_gen_o.o
	${CC} ${CFLAGS} main.cpp mesh_gen_o.o read_in.o prototypes.o -o myprogram

clean:
	rm myprogram *.o

cleanall:
	rm myprogram *.o login.txt outputfilename.txt
	rm -r html/ latex/ 
