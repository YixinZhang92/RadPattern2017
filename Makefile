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

displ_calc.o: displ_calc.cpp
	${CC} ${CFLAGS} -c displ_calc.cpp

write2file.o: write2file.cpp
	${CC} ${CFLAGS} -c write2file.cpp

myprogram: prototypes.o read_in.o mesh_gen_o.o displ_calc.o write2file.o error_check.o
	${CC} ${CFLAGS} main.cpp mesh_gen_o.o read_in.o prototypes.o displ_calc.o write2file.o error_check.o -o myprogram

clean:
	rm myprogram *.o

cleanall:
	rm myprogram *.o login.txt outputfilename.txt output.txt
	rm -r html/ latex/ 
