#ifndef ARVORE_TP3
#define ARVORE_TP3
#include <string>

class Node
{
private:
	std::string _digit;
	Node *_left, *_right;
public:
	Node();	
	Node(const std::string &digit);
	~Node();
	
	void SetChar(const std::string &digit);
	void SetLeft(Node *left);
	void SetRight(Node *right);

	std::string GetDigit();
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
};

#endif
