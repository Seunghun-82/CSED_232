all: assn3 clean

assn3 : main.o Block.o tetrimino.o
	g++ -o assn3 main.o Block.o tetrimino.o

main.o : main.cpp
	g++ -c -o main.o main.cpp

Block.o : Block.cpp
	g++ -c -o Block.o Block.cpp

tetrimino.o : tetrimino.cpp
	g++ -c -o tetrimino.o tetrimino.cpp

clean :
	rm *.o
