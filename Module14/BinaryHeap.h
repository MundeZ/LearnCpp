#pragma once
#include <vector>

/*
1. �������� � ����� ������� �� ������ (���� ���� ��� ��������), ��� �������� �� ��������.
2. �� i-�� ���� 2i ������, ����� ����������. ���� ���������� � ����.
3. ��������� ���� �������� ����� ������� (��� �������� �� �������)
*/

using namespace std;

class BinaryHeap {
	int* harr; // ��������� �� ������ ���������
	int capacity; // ������������ ������ ���� 
	int heap_size; // ������� ����� ��������� ���� 
private:
	int parrent(int i) { return (i - 1) / 2; };
	int left(int i) { return (2 * i - 1); }
	int right(int i) { return (2 * i + 2); }

public:
	BinaryHeap(int capacity);
	// �������������� �������� ���� ��� ��������� � ������ �� �������
	void MinHeapify(int);
	// �������� ����� �� ������
	int extractMin();
	// ��������� ������������ �������� - �����
	int getMin() { return harr[0]; }
	// ������� ������ �����
	void insertKey(int k);
};

