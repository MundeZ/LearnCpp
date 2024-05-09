#include <iostream>
#include "DynamicArray.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include "List.h"
#include "Stack.h"
//#include "Graph.h"
//#include "Tree.h"
//#include "BinaryTree.h"
#include <vector>
#include "homework1.h"
#include "Avl.h"

int max_number(int* array, int size) {
    int max = array[0]; // max 4 bite
    for (int i = 1; i < size; ++i)  //i 4 bite 
    {
        if (array[i] > max) 
        {
            max = array[i];
        }
    }
    return max;
};

int sum(int* array, int size)
{
    int sum = 0; // 4 bite
    for (int i = 0; i < size; i++) // 4 bite
        sum += array[i]; 
    return sum;
}

int sum2(int* array, int size)
{
    return array[0] + array[1];
}

bool findDubles(int* array, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (i != j && array[i] == array[j])
                return true;

    return false;
}

int uniq(int * array)
{
    const int arr_size = sizeof(array) / sizeof(int);
    int uniq_counts[arr_size]; // количества каждого элемента
    int uniq_elements[arr_size]; // массив уникальных элементов
    int uniq_counter = 0; // счётчик уникальных элементов
    // первая часть алгоритма, ищем количества повторений для каждого
    // уникального элемента
    for (int i = 0; i < arr_size; i++)
    {
        int existing_index = -1; // переменная для запоминания
        // индекса найденного элемента
        for (int j = 0; j < uniq_counter; j++)
        {
            // поиск i-ого элемента среди уже обработанных элементов
            if (uniq_elements[j] == array[i])
            {
                existing_index = j;
                uniq_counts[j]++; // увеличили количество повторений на 1
                break;
            }
        }
        if (existing_index == -1)
        {
            // если элемент ещё не встречался, запомним его
            uniq_elements[uniq_counter] = array[i];
            uniq_counts[uniq_counter] = 1;
            uniq_counter++;
        }
    }
    int max_uniq_count_index = 0;
    int max_uniq_count = uniq_counts[0];
    // вторая часть алгоритма ,среди посчитанных повторений ищем максимальное
    for (int i = 0; i < uniq_counter; i++)
    {
        if (max_uniq_count < uniq_counts[i])
            max_uniq_count_index = i;
    }
    return uniq_elements[max_uniq_count_index];
}

int get_max(int* arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void counting_sort(int* array, int size)
{
    int max = get_max(array, size);
    int* count = new int[max + 1];
    int* output = new int[size];

    for (size_t i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (size_t i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    for (size_t i = 1; i < max + 1; i++)
    {
        count[i] += count[i - 1];
    }

    for (size_t i = 0; i < size; i++)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    delete[] count;
    delete[] output;

}

void radix_sort(int* array, int size) // цифровая сортировка.
{
    //Шаг 1: Подразумевая, что у нас нет никакой информации о массиве, в первую очередь нам необходимо вычислить самое больше число, 
    // для того чтобы определить число с наибольшим количеством разрядов.
    
    //Шаг 2: Рассмотрев работу алгоритма на рисунке выше, вы наверное уже догадались, что сначала мы берем крайний правый разряд(младший разряд) 
    // всех элементов массива и сортируем массив, сравнивая только выбранный разряд.Повторяем процедуру,
    // пока не дойдем до самого левого разряда(старшего разряда) наибольшего числа.

    int max = get_max(array,size);
    for (size_t i = 1; max / i < 0; i*=10)
    {
        counting_sort(array, size);
    }

}

void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) { // Внешний цикл проходит по массиву от 0 до n-1
        bool swapped = false; // Флаг, который указывает, были ли сделаны обмены элементов во время прохода

        // Внутренний цикл для прохода по элементам и сравнения их попарно
        // Последние i элементов уже отсортированы, поэтому их можно игнорировать
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) { // Если текущий элемент больше следующего, меняем их местами
                std::swap(array[j], array[j + 1]); // Меняем местами элементы при помощи функции swap
                swapped = true; // Устанавливаем флаг, что был сделан обмен
            }
        }

        // Если на данной итерации внутреннего цикла не было сделано ни одного обмена,
        // то массив уже отсортирован, и процесс сортировки можно завершить
        if (!swapped) {
            break;
        }
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int* arr, int left, int right)
{
    if (left > right) return;

    int p = arr[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (arr[i] < p) i++;
        while (arr[j] > p) j--;
        if (i <= j)
        {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

void write_arr(const std::string& filename, const int* arr, const int n)
{
    std::fstream fs;

    fs.open(filename, std::fstream::out);
    if (fs.is_open()) // проверяем, что файл успешно открыт
    {
        fs << n << '\n';  // записываем размер массива
        for (int i = 0; i < n; i++)
            fs << arr[i] << ' '; // записываем значения через пробел
        fs << '\n';

        fs.close(); // закрываем файл
    }
}

void read_arr(const std::string& filename, int*& arr, int& n)
{
    std::fstream fs;

    fs.open(filename, std::fstream::in);
    if (fs.is_open()) // проверяем, что файл успешно открыт
    {
        fs >> n;  // читаем размер массива
        arr = new int[n];
        for (int i = 0; i < n; i++)
            fs >> arr[i]; // читаем из файла разделительные символы - пробел и перенос строки

        fs.close(); // закрываем файл
    }
}

int binarySearch(int arr[],int l,int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - 1) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid - 1, x);
        }
        else
        {
            return binarySearch(arr, mid + 1, r, x);
        }
        return -1;
    }
}

int author_realise(char str[10])
{
    int sum = 0;
    for (size_t i = 0; i < 10; i++)
    {
        sum += str[i];
    }
    return sum % 33;
}

typedef unsigned int uint;
#define one_block_size_bytes 64 
#define one_block_size_uints 16 
#define block_expend_size_uints 80 

typedef uint* Block;
typedef uint ExpendBlock[block_expend_size_uints];

const uint H[5] = {
    0x67452301,
    0xEFCDAB89,
    0x98BADCFE,
    0x10325476,
    0xC3D2E1F0
}; 

uint cycle_shift_left(uint val, int bit_count) 
{
    return (val << bit_count | val >> (32 - bit_count));
};

uint bring_to_human_view(uint val) {
    return  ((val & 0x000000FF) << 24) |
        ((val & 0x0000FF00) << 8) |
        ((val & 0x00FF0000) >> 8) |
        ((val & 0xFF000000) >> 24);
};


struct Person
{
    string name;
    int age;
    Person(const string& name_, int age_) : name(name_), age(age_){}
};

ostream& operator<<(ostream& os, const Person& person)
{
    os << "Name: " << person.name << ", Age: " << person.age;
    return os;
}


#include <map>

int main()
{
    map <string, int> myMap = { { "John", 27 },
                              { "Bob", 20 },
                              { "Alice", 19 },
                              { "Tony", 23 } };


    for (map<string, int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }

    vector<string> Cities{ "Moscow", "Madrid", "London", "New York", "Helsinki" };
    map <int, string> CitiesGrade;
    for (int i = 0; i < 5; ++i)
    {
        CitiesGrade.insert(pair<int, string>(i, Cities[i]));
    }

    for (map<int, string>::iterator it = CitiesGrade.begin(); it != CitiesGrade.end(); ++it)
    {
        cout << (*it).first << " : " << (*it).second << endl;
    }
    return 0;
}
