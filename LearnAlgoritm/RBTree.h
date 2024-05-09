#pragma once

enum Color {Black, Red};

class RBTree
{
public:
	struct Node
	{
		int key;
		Color color;
		Node* left;
		Node* right;
		Node* parent;
		Node(int k) :
			key(k), color(Red), parent(nullptr),
			left(nullptr), right(nullptr) {};
	};
	void insert(int key);
private:
	void insert(Node* root, Node* node);
	Node* root;
};

