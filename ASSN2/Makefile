all: assn2 clean

assn2 : main.o member.o feed.o
	g++ -o assn2 main.o member.o feed.o

main.o : main.cpp
	g++ -c -o main.o main.cpp

member.o : member.cpp
	g++ -c -o member.o member.cpp

feed.o : feed.cpp
	g++ -c -o feed.o feed.cpp

.PHONY : clean

clean : 
	rm *.o
