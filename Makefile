CC = g++

CFLAGS = -Wall

CPPFLAGS = -Wall

all: myprogram

error_check.o: error_check.cpp
	${CC} ${CPPFLAGS} -c error_check.cpp

read_in.o: read_in.cpp
	${CC} ${CPPFLAGS} -c read_in.cpp 

mesh_gen_o.o: mesh_gen_o.cpp
	${CC} ${CPPFLAGS} -c mesh_gen_o.cpp

displ_calc.o: displ_calc.cpp
	${CC} ${CPPFLAGS} -c displ_calc.cpp

write2file.o: write2file.cpp
	${CC} ${CPPFLAGS} -c write2file.cpp

radiation.o: radiation.cpp
	${CC} ${CPPFLAGS} -c radiation.cpp

cart2sph.o: cart2sph.cpp
	${CC} ${CPPFLAGS} -c cart2sph.cpp

gaussian.o: gaussian.cpp
	${CC} ${CPPFLAGS} -c gaussian.cpp

myprogram: read_in.o mesh_gen_o.o displ_calc.o write2file.o error_check.o radiation.o gaussian.o cart2sph.o
	${CC} ${CPPFLAGS} main.cpp mesh_gen_o.o read_in.o displ_calc.o write2file.o error_check.o radiation.o gaussian.o cart2sph.o -o myprogram

clean:
	rm -f myprogram *.o

cleanall:
	rm -f myprogram *.o login.txt outputfilename.txt output.txt
	rm -rf html/ latex/
