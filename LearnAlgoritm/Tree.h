#pragma once
#define SIZE 10
#include <iostream>

class Tree
{
public:
	Tree();
	~Tree();
	void setRoot(int number);
	void addNode(int newNodeNumber, int parentNodeNumber);
	void delNode(int number);
	void print();


private:
	struct Node
	{
		int number;
		int child_count;
		Node* children[SIZE];
		Node* parent;

		Node(int _number, Node* _parent = 0) :
			number(_number),
			parent(_parent),
			child_count(0) {}

		~Node()
		{
			for (size_t i = 0; i < child_count; i++)
			{
				delete children[i];
			}
		}

		void addChild(Node* newChild)
		{
			children[child_count++] = newChild;
		}
		void delChild(Node* child)
		{
			children[child_count--] = child;

		}
	

	};
	Node* getNodeByNumber(int number, Node* current);
	void printInner(Node* current);
	Node* root;
};