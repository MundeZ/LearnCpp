#pragma once
#include <iostream>
#include <queue>

class Avl
{
public:
	struct Node
	{
		int key;
		Node* left;
		Node* right;
		size_t height;
		Node(int& k) { key = k; left = right = nullptr; height = 0; }
		Node(int&& k) { key = k; left = right = nullptr; height = 0; }
	};

	size_t height(Node* node);
	int bfactor(Node* node);
	void fix_height(Node* node);
	void insert(int&& key);
	Node* insert(Node* root, Node* const node);
	Node* rotateRight(Node* node);
	Node* rotateLeft(Node* node);
	Node* balance(Node* const node);
	Node* removemin(Node* node);
	Node* findmin(Node* node);
	void delete_node(const int& key);
	Node* delete_node(Node* node, const int& key);
	const Node* bfs(const int& key) const;
	const Node* dfs(const Node* node, const int& key);
private:
	Node* _root;
};

