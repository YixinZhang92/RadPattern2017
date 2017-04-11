CC = g++

CFLAGS = -Wall

all: myprogram

prototypes.o: prototypes.cpp
	${CC} ${CFLAGS} -c prototypes.cpp 

error_check.o: error_check.cpp
	${CC} ${CFLAGS} -c error_check.cpp

read_in.o: read_in.cpp
	${CC} ${CFLAGS} -c read_in.cpp 

mesh_gen_o.o: mesh_gen_o.cpp
	${CC} ${CFLAGS} -c mesh_gen_o.cpp

myprogram: prototypes.o read_in.o mesh_gen_o.o error_check.o
	${CC} ${CFLAGS} main.cpp mesh_gen_o.o read_in.o error_check.o prototypes.o -o myprogram

clean:
	rm myprogram *.o

cleanall:
	rm myprogram *.o login.txt outputfilename.txt
	rm -r html/ latex/ 
