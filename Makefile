all: myprogram

myprogram: main.o displacement.o radiation.o writing.o \
	   gaussian.o mesh_gen.o read_wave.o
	g++ -o myprogram -lstdc++ main.o displacement.o radiation.o \
	       writing.o gaussian.o mesh_gen.o read_wave.o

displacement.o: displacement.cpp
	g++ -c displacement.cpp -lstdc++

radiation.o: radiation.cpp
	g++ -c radiation.cpp -lstdc++

writing.o: writing.cpp
	g++ -c writing.cpp -lstdc++

gaussian.o: gaussian.cpp
	g++ -c gaussian.cpp -lstdc++

mesh_gen.o: mesh_gen.cpp
	g++ -c mesh_gen.cpp -lstdc++

read_wave.o: read_wave.cpp
	g++ -c read_wave.cpp -lstdc++

main.o: main.cpp
	g++ -c main.cpp -lstdc++

cleanall:
	rm myprogram *.o login.txt outputfilename.txt 
	rm -r html/ latex/
