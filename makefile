out: main.o insertionsort.o mergesort.o
	g++ main.o insertionsort.o mergesort.o -o out
	./out

mergesort.o: src/mergesort.cpp src/mergesort.h
	g++ -c src/mergesort.cpp

insertionsort.o: src/insertionsort.cpp src/insertionsort.h
	g++ -c src/insertionsort.cpp

main.o: main.cpp
	g++ -c main.cpp