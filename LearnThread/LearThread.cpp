#include <vector>
#include <thread>
#include <iostream>
#include <cstdlib>

int sumRange(const std::vector<int>& array, size_t start, size_t end) {
	int sum = 0;
	for (size_t i = start; i < end; ++i) {
		sum += array[i];
	}
	return sum;
}


int main()
{
	const int n = 20;
	const int m = 4;
	std::vector<int> numbers; // ������ �����
	std::vector<std::thread> threads; // ������ �������
	int sum = 0;

	for (size_t i = 0; i < n; i++) // ������� ������ ��������� �����
	{
		numbers.push_back(rand());
	}
	

	size_t partSize = n / m;
	for (int i = 0; i < m; i++)
	{
		size_t start = i * partSize;
		size_t end = (i == m - 1) ? n : (i + 1) * partSize;

		threads.push_back(std::thread([&, start, end]() {
			int partialSum = sumRange(numbers, start, end); // ������� ����� ��� ����� �������
			sum += partialSum; // ��������� � � ����� �����
			}));
	}


	for (std::thread& t : threads) // ������� ���������� ���� �������
	{
		t.join();
	}

	std::cout << sum << "\n";

}