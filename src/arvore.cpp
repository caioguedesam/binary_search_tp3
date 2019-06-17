#include "headers/arvore.h"

Node::Node() {
	_digit = "";
	_left = nullptr;
	_right = nullptr;	
}

Node::Node(const std::string &digit) {
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

void Node::SetChar(const std::string &digit) {_digit = digit;}
void Node::SetLeft(Node* left) {_left = left;}
void Node::SetRight(Node* right) {_right = right;}

std::string Node::GetDigit() {return _digit;}
Node* Node::GetLeft() {return _left;}
Node* Node::GetRight() {return _right;}

Tree::Tree() {
	_head = new Node();
}

Tree::~Tree() {
	if(_head != nullptr)
		delete _head;
}

Node* Tree::GetHead() {return _head;}



