#pragma once
#include <iostream>

class BinaryTree
{
public:
	struct Node
	{
		Node(int d, Node* p = nullptr) :
			data(d), parent(p)
		{
			leftChild = nullptr;
			rightChild = nullptr;
		};
		~Node()
		{
			// Перед удалением потомков обнуляем указатели, чтобы избежать двойного удаления
			//leftChild = nullptr;
			//rightChild = nullptr;
			if (rightChild != nullptr)
				delete rightChild;
			if (leftChild != nullptr)
				delete leftChild;
		};

		Node* parent;
		Node* leftChild;
		Node* rightChild;

		int data;

	};

	BinaryTree()
	{
		root = nullptr;
	}
	~BinaryTree()
	{
		if (root != nullptr)
		{
			delete root;
		}
	}
	void print();
	void addInt(int newData);
	void delInt(int deldata);
	
	Node* findNodeByData(int finddata);
	
private:
	void printHelper(BinaryTree::Node* node);
	Node* Delete(Node* root, int data);
	Node* findMin(Node* node);
	Node* root;
};

