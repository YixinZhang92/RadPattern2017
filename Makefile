CC = g++

CFLAGS = -Wall

all: mainfile_test

mainfile_test:mainfile_test.o
	${CC} ${CFLAGS} mainfile_test.o -o mainfile_test
	
mainfile_test.o: mainfile_test.cpp
	${CC} ${CFLAGS} -c mainfile_test.cpp

cleanall:
	rm -rf mainfile_test *.o
