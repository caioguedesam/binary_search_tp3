#include "headers/arvore.h"
#include <fstream>

int main() {

	std::ifstream input;
	input.open("morse.txt", std::fstream::in);
	std::string line;
	Tree t;
	t.EmptyTree();

	while(std::getline(input, line)) {
		char digit = line[0];
		std::string morse = line.substr(2);
		t.InsertNode(digit, morse);
	}

	input.close();

	t.PrintPreOrder();
	return 0;
}
