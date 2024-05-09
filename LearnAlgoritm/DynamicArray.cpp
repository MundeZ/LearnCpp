#include "DynamicArray.h"

int DynamicArray::get(int index)
{
	return array[index];
}

void DynamicArray::insert(int newval)
{
	if (size == allocedSize)
	{
		int* newMem = new int[allocedSize * 2];
		for (size_t i = 0; i < size; i++)
		{
			newMem[i] = array[i];
		}
		allocedSize *= 2;
		delete array;
		array = newMem;
	}
	array[size++] = newval;
}