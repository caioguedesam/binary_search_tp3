#include "headers/arvore.h"

Node::Node() {
	_morse = "";
	_digit = 0;
	_left = nullptr;
	_right = nullptr;	
}

Node::Node(const char &digit, const std::string &morse) {
	_morse = morse;
	_digit = digit;
	_left = nullptr;
	_right = nullptr;
}

Node::~Node() {
	if(_left != nullptr)
		delete _left;
	if(_right != nullptr)
		delete _right;
}

void Node::SetMorse(const std::string &morse) {_morse = morse;}
void Node::SetDigit(const char &digit) {_digit = digit;}
void Node::SetLeft(Node* left) {_left = left;}
void Node::SetRight(Node* right) {_right = right;}

std::string Node::GetMorse() {return _morse;}
char Node::GetDigit() {return _digit;}
Node* Node::GetLeft() {return _left;}
Node* Node::GetRight() {return _right;}

Tree::Tree() {
	_head = new Node();
}

Tree::~Tree() {
	if(_head != nullptr)
		delete _head;
}

void Tree::EmptyTree(Node *aux, const int &level) {
	// Ao criar a árvore vazia, apenas insere nós vazios
	// até o sexto nível (para cabeça como nível 1,
	// level = nível - 1) 
	if(level <= 5) {
		if(aux->GetLeft() == nullptr) {
			aux->SetLeft(new Node());
			// Chamada recursiva para criar os nós vazios do próximo nível
			EmptyTree(aux->GetLeft(), level+1);
		}
		if(aux->GetRight() == nullptr) {
			aux->SetRight(new Node());
			// Chamada recursiva para criar os nós vazios do próximo nível
			EmptyTree(aux->GetRight(), level+1);
		}
	}
}

void Tree::EmptyTree() {EmptyTree(this->GetHead(), 0);}

void Tree::InsertNode(const char &digit, const std::string &morse) {
	// Caminha a árvore, iniciando pela cabeça
	Node *aux = this->GetHead();
	int i;
	for(i = 0; i < morse.size(); i++) {
		// Caso o caractere seja . move para a esquerda
		if(morse[i] == '.') {
			aux = aux->GetLeft();
		}
		// Caso seja - move para a direita
		else if(morse[i] == '-') {
			aux = aux->GetRight();
		}
	}

	// Insere os dados no nó final obtido pelo caminhamento
	aux->SetMorse(morse);
	aux->SetDigit(digit);
}

Node* Tree::GetHead() {return _head;}

char Tree::SearchFor(const std::string &morse) {
	// Inicia o caminho pelo nó cabeça
	Node *aux = this->GetHead();
	int i;
	// Itera sobre todos os caracteres presentes no código morse desejado
	for(i = 0; i < morse.size(); i++) {
		// Caso o caractere do índice i seja . vai para esquerda
		if(morse[i] == '.')
			aux = aux->GetLeft();
		// Caso seja - vai para direita
		else if(morse[i] == '-')
			aux = aux->GetRight();
	}
	// Retorna o digito correspondente
	return aux->GetDigit();
}

void Tree::PrintPreOrder(Node *aux) {
	if(aux != this->GetHead() && aux->GetMorse() != "")
		std::cout << aux->GetDigit() << " " << aux->GetMorse() << std::endl;
	if(aux->GetLeft() != nullptr)
		PrintPreOrder(aux->GetLeft());
	if(aux->GetRight() != nullptr)
		PrintPreOrder(aux->GetRight());
}

void Tree::PrintPreOrder() {PrintPreOrder(this->GetHead());}
