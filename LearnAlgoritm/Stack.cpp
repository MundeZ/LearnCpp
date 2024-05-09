#include "Stack.h"

bool Stack::IsEmpty()
{
	Node* current = m_root;
	if (current == nullptr)
	{
		return true; // Если стек пуст, возвращаем true
	}
	else
	{
		return false; // Если стек не пуст, возвращаем false
	}
}

void Stack::Show()
{
    Node* current = m_root;
    while (current != nullptr)
    {
		std::cout << current->m_data;
		std::cout << " ";
        current = current->m_next;
    }
}

bool Stack::Push(int x)
{
	Node* node = new Node(x);
	node->m_next = m_root;
	m_root = node;
	return true;
}

int Stack::Pop()
{
    Node* node = m_root;

    if (IsEmpty())
    {
        std::cout << "Stack is empty" << "\n";
        return -1;
    }
    else
    { 
        int x = node->m_data;
        m_root = m_root->m_next; 
        delete node;
        return x; 
    }
}

int Stack::Peek()
{
    Node* node = m_root;

    if (IsEmpty())
    {
        std::cout << "Stack is empty" << "\n";
        return -1;
    }
	else
	{
        int x = node->m_data;
        return x;
	}
}