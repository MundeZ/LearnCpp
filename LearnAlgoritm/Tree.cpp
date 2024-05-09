#include "Tree.h"

Tree::Tree() 
{ 
	root = 0; 
}
Tree::~Tree() 
{ 
	if (root != 0) delete root; 
}

void Tree::setRoot(int number)
{
	root = new Node(number);
}
void Tree::addNode(int newNodeNumber, int parentNodeNumber)
{
	Node* parentNode = getNodeByNumber(parentNodeNumber, root);
	Node* newNode = new Node(newNodeNumber, parentNode);
	parentNode->addChild(newNode);
}
void Tree::delNode(int number)
{
	Node* nodeToDelete = getNodeByNumber(number, root);
	if (nodeToDelete == nullptr)
	{
		std::cout << "Node not found" << std::endl;
		return;
	}

	Node* parentNode = nodeToDelete->parent;
	if (parentNode != nullptr)
	{
		for (size_t i = 0; i < parentNode->child_count; i++)
		{
			if (parentNode->children[i]->number == number)
			{
				parentNode->delChild(parentNode->children[i]);
				delete nodeToDelete;
				return;
			}
		}
	}
	for (size_t i = 0; i < nodeToDelete->child_count; i++)
	{
		Node* child = nodeToDelete->children[i];
		child->parent = parentNode;
		parentNode->addChild(child);
	}

	//delete nodeToDelete;
}

void Tree::print()
{
	printInner(root);
}
void Tree::printInner(Node* current)
{
	std::cout << "N" << current->number << ": ";
	for (size_t i = 0; i < current->child_count; i++)
	{
		std::cout << current->children[i]->number << ", ";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < current->child_count; i++)
	{
		printInner(current->children[i]);
	}
}

Tree::Node* Tree::getNodeByNumber(int number, Node* current)
{
	if (current->number == number)
	{
		return current;
	}
	for (size_t i = 0; i < current->child_count; i++)
	{
		Node* found = getNodeByNumber(number, current->children[i]);
		if (found != 0)
		{
			return found;
		}
	}
	return 0;
}