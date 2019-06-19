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

	// Loop principal para ler as linhas da mensagem entrada
	while(std::getline(std::cin, line)) {
		int index;
		// Variáveis para armazenar a mensagem de uma dada linha
		std::string line_message = "";
		// E o morse atual (enquanto percorre os caracteres da linha)
		std::string current_morse = "";

		// Percorre todos os caracteres da linha lida
		for(index = 0; index < line.size(); index++) {
			// Caso o caractere no índice seja . ou -, armazena-o no morse atual
			if(line[index] == '.' || line[index] == '-') {
				current_morse += line[index];
				// Caso seja o final da linha, termina de definir morse atual
				// e adiciona sua tradução na mensagem da linha
				if(line[index+1] == *line.end())
					line_message += t.SearchFor(current_morse);
			}
			// Caso o caractere no índice seja /, adiciona um espaço em branco
			// na mensagem da linha
			else if(line[index] == '/') 
				line_message += ' ';
			// Caso seja outro caractere, termina de definir morse atual
			// e adiciona sua tradução na mensagem da linha
			else if(current_morse != "") {
				line_message += t.SearchFor(current_morse);	
				// reinicia morse atual para passar pela próxima letra da mensagem
				current_morse = "";
			}
			
		}

		// Termina imprimindo a mensagem da linha a cada linha lida
		std::cout << line_message << std::endl;
	}

	if(argc == 2 && std::string(argv[1]) == "-a") {
		t.PrintPreOrder();
	}
	return 0;
}
