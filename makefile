out: main.o quicksort.o insertionsort.o
	g++ main.o quicksort.o insertionsort.o -o out
	./out

insertionsort.o: src/insertionsort.cpp src/insertionsort.h
	g++ -c src/insertionsort.cpp

quicksort.o: src/quicksort.cpp src/quicksort.h
	g++ -c src/quicksort.cpp

main.o: main.cpp
	g++ -c main.cpp 
