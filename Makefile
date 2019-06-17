tp3: main.o arvore.o
	g++ main.o arvore.o -o tp3
	make clean

main.o: src/main.cpp
	g++ -c src/main.cpp

arvore.o: src/arvore.cpp src/headers/arvore.h
	g++ -c src/arvore.cpp

clean:
	rm *.o
