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
	if(level <= 5) {
		if(aux->GetLeft() == nullptr) {
			aux->SetLeft(new Node());
			EmptyTree(aux->GetLeft(), level+1);
		}
		if(aux->GetRight() == nullptr) {
			aux->SetRight(new Node());
			EmptyTree(aux->GetRight(), level+1);
		}
	}
}

void Tree::EmptyTree() {EmptyTree(this->GetHead(), 0);}

Node* Tree::GetHead() {return _head;}

void Tree::InsertNode(const char &digit, const std::string &morse) {
	Node *aux = this->GetHead();
	int i;
	for(i = 0; i < morse.size(); i++) {
		if(morse[i] == '.') {
			aux = aux->GetLeft();
		}
		else if(morse[i] == '-') {
			aux = aux->GetRight();
		}
	}

	aux->SetMorse(morse);
	aux->SetDigit(digit);
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
