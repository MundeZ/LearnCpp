#include "List.h"
#include <iostream>

void List::push_back(int data)
{
	Node* node = new Node(data);
	if (m_head == nullptr)
	{
		m_head = node;
		return;
	}
	Node* last = m_head;
	while (last->m_next !=  nullptr)
	{
		last = last->m_next;
	}
	last->m_next = node;
	return;
}

void List::push_front(int data)
{
	Node* node = new Node(data);
	node->m_next = m_head;
	m_head = node;
}

void List::insert(int pos,int data)
{
	Node* node = new Node(data);

	if (m_head == nullptr)
	{
		// ���� ������ ����, ����� ���� � ����� ������� ������
		m_head = node;
		return;
	}

	if (pos == 0)
	{
		// ������� ������ - �������  � ������ ������
		node->m_next = m_head;
		m_head = node;
		return;
	}
	int currPos = 0;

	Node* current = m_head;
	// � ����� ���� �� ������, ���� ������ �� ��������, ��� ���� �� ������ �� �������
	while (currPos < pos - 1 && current->m_next != nullptr)
	{
		current = current->m_next;
		currPos++;
	}
	// ������ ��������� �� ��������� ���� �� ��������� �� ����� ����
	Node* next = current->m_next;
	current->m_next = node;
	// ��������� ������ �������, ������ ��������� �� ����, ��������� ����� ������ ����, �� ��������� �� ����, ��������� �� current
	node->m_next = next;

}

void List::deleteNode(int data)
{
	Node* temp = m_head;
	Node* prev = nullptr;

	// ������� ������ �������� ������ ������
	if (temp && temp->m_data == data)
	{
		m_head = temp->m_next;
		delete temp;
		return;
	}
	// ���� �� ������, ���� �� ������ ���� �� ��������� ������, ������ �����
	while (temp && temp->m_data != data)
	{
		prev = temp;
		temp = temp->m_next;
	}
	// ���� ���� �� ������, ����������
	if (!temp)
		return;
	// ������ ��������� ���������� ���� ��� ����������� ���� �� ����, ��������� �� ��������� �����, � ������� ���� � �������
	prev->m_next = temp->m_next;
	delete temp;
}
void List::deleteNodeByPos(int pos)
{
	if (m_head == nullptr) {
		std::cout << "������ ����, �������� ����������." << std::endl;
		return;
	}

	if (pos == 0) {
		Node* temp = m_head;
		m_head = m_head->m_next;
		delete temp;
		return;
	}

	int currPos = 0;
	Node* current = m_head;
	Node* prev = nullptr;

	while (current != nullptr && currPos != pos) {
		prev = current;
		current = current->m_next;
		currPos++;
	}

	if (current == nullptr) {
		std::cout << "������� ������������ ������� ��� ��������." << std::endl;
		return;
	}

	prev->m_next = current->m_next;
	delete current;
}

void List::show()
{
	Node* current = m_head;
	std::cout << "���������� ������: ";
	while (current != nullptr)
	{
		std::cout << current->m_data << " ";
		current = current->m_next;
	}
	std::cout << std::endl;
}