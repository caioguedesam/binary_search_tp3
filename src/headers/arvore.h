#ifndef ARVORE_TP3
#define ARVORE_TP3
#include <string>
#include <iostream>

class Node
{
private:
	std::string _morse;
	char _digit;
	Node *_left, *_right;
public:
	Node();	
	Node(const char &digit, const std::string &morse);
	~Node();
	
	void SetMorse(const std::string &morse);
	void SetDigit(const char &digit);
	void SetLeft(Node *left);
	void SetRight(Node *right);

	std::string GetMorse();
	char GetDigit();
	Node *GetLeft();
	Node *GetRight();
	
};

class Tree
{
private:
	Node *_head;
public:
	Tree();
	~Tree();

	Node *GetHead();

	void EmptyTree(Node *aux, const int &level);
	void EmptyTree();
	void InsertNode(const char &digit, const std::string &morse);
	char SearchFor(const std::string &morse);
	void PrintPreOrder(Node *aux);
	void PrintPreOrder();
};

#endif
