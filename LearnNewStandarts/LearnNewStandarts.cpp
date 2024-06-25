#include <iostream>

using namespace std;


class IntArray {
public:
    // конструктор
    IntArray(int size) :
        m_arr(new int[size]),
        m_size(size) {
        cout << "constructor with " << size << " size" << endl;

    }
    // деструктор
    ~IntArray() {
        cout << "destructor" << endl;
        // чистим за собой
        if (m_size)
            delete[] m_arr;
    }
    // копирующий конструктор
    IntArray(const IntArray& other) {
        cout << "copy constructor" << endl;
        // копируем размер
        m_size = other.m_size;
        // копируем память
        m_arr = new int[m_size];
        for (int i = 0; i < m_size; i++) {
            m_arr[i] = other.m_arr[i];
        }
    }
    // оператор присваивания
    IntArray& operator= (const IntArray& other) {
        cout << "copy assignment" << endl;
        if (&other == this)
            return *this;
        if (m_size)
            delete[] m_arr;
        //копируем размер
        m_size = other.m_size;
        //копируем память
        m_arr = new int[m_size];
        for (int i = 0; i < m_size; i++) {
            m_arr[i] = other.m_arr[i];
        }
        return *this;
    }
    // конструктор перемещения
    IntArray(IntArray&& other) {
        cout << "move constructor" << endl;
        // меняем местами размер и указатель на память
        // избегаем new и цикла for
        swap(m_size, other.m_size);
        swap(m_arr, other.m_arr);
    }
    // оператор перемещения
    IntArray& operator= (IntArray&& other) {
        cout << "move assignment" << endl;
        if (this == &other)
            return *this;
        m_size = 0;
        // меняем местами размер и указатель на память
        // избегаем new и цикла for            
        swap(m_size, other.m_size);
        swap(m_arr, other.m_arr);
        return *this;
    }
private:
    int* m_arr;
    int m_size;
};



int main()
{   
    IntArray my_int_1(20);



    return 0;
}

