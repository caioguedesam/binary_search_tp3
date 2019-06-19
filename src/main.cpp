#include "headers/arvore.h"
#include <fstream>

int main(int argc, char *argv[]) {

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

	while(std::getline(std::cin, line)) {
		int index;
		std::string line_message = "";
		std::string current_morse = "";
		for(index = 0; index < line.size(); index++) {
			if(line[index] == '.' || line[index] == '-') {
				current_morse += line[index];
				if(line[index+1] == *line.end())
					line_message += t.SearchFor(current_morse);
			}
			else if(line[index] == '/') 
				line_message += ' ';
			else if(line[index] == ' ' && current_morse != "") {
				line_message += t.SearchFor(current_morse);	
				current_morse = "";
			}
			
		}

		std::cout << line_message << std::endl;
	}

	if(argc == 2 && std::string(argv[1]) == "-a") {
		t.PrintPreOrder();
	}
	return 0;
}
