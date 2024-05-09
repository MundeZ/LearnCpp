#pragma once
class DynamicArray
{
public:
	DynamicArray()
	{
		allocedSize = 1;
		size = 0;
		array = new int[allocedSize];
	}
	~DynamicArray()
	{
		delete[] array;
	}
	void insert(int newval);
	int get(int index);

private:
	int allocedSize;
	int size; 
	int* array;
};

