tp3: main.o arvore.o
	g++ main.o arvore.o -o tp3
	make clean

main.o: main.cpp
	g++ -c main.cpp

arvore.o: arvore.cpp headers/arvore.h
	g++ -c arvore.cpp

clean:
	rm *.o
