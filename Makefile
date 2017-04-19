CC = g++

CPPFLAGS = -Wall

CPPFLAGS = -Wall

all: myprogram

error_check.o: error_check.cpp
	${CC} ${CPPFLAGS} -c error_check.cpp

read_in.o: read_in.cpp
	${CC} ${CPPFLAGS} -c read_in.cpp 

compute_displ.o: compute_displ.cpp
	${CC} ${CPPFLAGS} -c compute_displ.cpp

write2file.o: write2file.cpp
	${CC} ${CPPFLAGS} -c write2file.cpp

radiation.o: radiation.cpp
	${CC} ${CPPFLAGS} -c radiation.cpp

cart2sph.o: cart2sph.cpp
	${CC} ${CPPFLAGS} -c cart2sph.cpp

gaussian.o: gaussian.cpp
	${CC} ${CPPFLAGS} -c gaussian.cpp

myprogram: read_in.o compute_displ.o write2file.o error_check.o radiation.o gaussian.o cart2sph.o 
	${CC} ${CPPFLAGS} main.cpp read_in.o compute_displ.o write2file.o error_check.o radiation.o gaussian.o cart2sph.o -o myprogram

clean:
	rm -f myprogram *.o

cleanall:
	rm -f myprogram *.o login.txt outputfilename.txt output.txt parameter_outfile.txt
	rm -rf html/ latex/ data/*
