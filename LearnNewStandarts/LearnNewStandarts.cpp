#include <iostream>

using namespace std;


class IntArray {
public:
    // �����������
    IntArray(int size) :
        m_arr(new int[size]),
        m_size(size) {
        cout << "constructor with " << size << " size" << endl;

    }
    // ����������
    ~IntArray() {
        cout << "destructor" << endl;
        // ������ �� �����
        if (m_size)
            delete[] m_arr;
    }
    // ���������� �����������
    IntArray(const IntArray& other) {
        cout << "copy constructor" << endl;
        // �������� ������
        m_size = other.m_size;
        // �������� ������
        m_arr = new int[m_size];
        for (int i = 0; i < m_size; i++) {
            m_arr[i] = other.m_arr[i];
        }
    }
    // �������� ������������
    IntArray& operator= (const IntArray& other) {
        cout << "copy assignment" << endl;
        if (&other == this)
            return *this;
        if (m_size)
            delete[] m_arr;
        //�������� ������
        m_size = other.m_size;
        //�������� ������
        m_arr = new int[m_size];
        for (int i = 0; i < m_size; i++) {
            m_arr[i] = other.m_arr[i];
        }
        return *this;
    }
    // ����������� �����������
    IntArray(IntArray&& other) {
        cout << "move constructor" << endl;
        // ������ ������� ������ � ��������� �� ������
        // �������� new � ����� for
        swap(m_size, other.m_size);
        swap(m_arr, other.m_arr);
    }
    // �������� �����������
    IntArray& operator= (IntArray&& other) {
        cout << "move assignment" << endl;
        if (this == &other)
            return *this;
        m_size = 0;
        // ������ ������� ������ � ��������� �� ������
        // �������� new � ����� for            
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

