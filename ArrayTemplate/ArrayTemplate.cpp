#include <iostream>
using namespace std;

template <typename T>
class Array
{
    T* data;
    int size;
    int grow;
    /*int occupied;*/
public:
    Array() :data(nullptr), size(0), grow(0)
    {};
    Array(int s);
    int GetSize();
    void SetSize(int size, int grow = 1);
    int GetUpperBound();
    bool IsEmpty();
    void FreeExtra();
    void RemoveAll();
    T GetAt(int index);
    void SetAt(int index);
    T& operator[] (int index);
    void Add(const T& value);
    Array<T>& Append(Array<T>& obj);
    Array<T>& operator=(Array<T>& obj);
    T* GetData();
    void InsertAt(int index);
    void RemoveAt(int index);
    ~Array();
};

template<typename T>
int Array<T>::GetSize()
{
    return size;
}

template<typename T>
T* Array<T>::GetData()
{
    return data;
}

template<typename T>
Array<T>::~Array()
{
    delete[] data;
}

template<typename T>
T& Array<T>::operator[](int index)
{
    if (index > 0 && index <= size)
    {
        return data[index];
    }
    else
    {
        cout << "Invalid index";
    }
}

int main()
{
}
