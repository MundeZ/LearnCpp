#pragma once
#include <vector>

/*
1. Значение в любой вершине не больше (если куча для минимума), чем значения ее потомков.
2. На i-ом слое 2i вершин, кроме последнего. Слои нумеруются с нуля.
3. Последний слой заполнен слева направо (как показано на рисунке)
*/

using namespace std;

class BinaryHeap {
	int* harr; // указатель на массив элементов
	int capacity; // максимальный размер кучи 
	int heap_size; // текущее число элементов кучи 
private:
	int parrent(int i) { return (i - 1) / 2; };
	int left(int i) { return (2 * i - 1); }
	int right(int i) { return (2 * i + 2); }

public:
	BinaryHeap(int capacity);
	// Восстановление свойства кучи для поддерева с корнем по индексу
	void MinHeapify(int);
	// Удаление корня из дерева
	int extractMin();
	// Получение минимального элемента - корня
	int getMin() { return harr[0]; }
	// Вставка нового ключа
	void insertKey(int k);
};

