#include <iostream>
using namespace std;

template <typename T>
class Array
{
    T* data;
    int size;
    int grow;
    int occupied;
public:
    Array() :data(nullptr), size(0), grow(1), occupied(0)
    {};
    Array(int s) :size(s), grow(1), occupied(0)
    {
        data = new T[size];
    };
    int GetSize() const;
    void SetSize(int size, int grow = 1);
    int GetUpperBound();
    bool IsEmpty();
    void FreeExtra();
    void RemoveAll();
    T GetAt(int index);
    void SetAt(int index, const T& value);
    T& operator[] (int index);
    void Add(const T& value);
    Array<T>& Append(Array<T>& obj);
    Array<T>& operator=(Array<T>& obj);
    T* GetData();
    void InsertAt(int index, const T& value);
    void RemoveAt(int index);
    ~Array();
};

template<typename T>
int Array<T>::GetSize() const
{
    return size;
}

template<typename T>
void Array<T>::SetSize(int size, int grow)
{
    if (size <= 0)
    {
        delete[] data;
        data = nullptr;
        size = 0;
        occupied = 0;
        return;
    }
    if (grow > 1)
    {
        this->grow = grow;
    }
    if (this->size < size)
    {
        this->size = size + grow - 1;
    }
    else {
        this->size = size;
    }
    T* temp = new T[this->size];
    if (size < occupied)
    {
        occupied = size;
    }
    for (int i = 0; i < occupied; i++)
    {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
}

template<typename T>
int Array<T>::GetUpperBound()
{
    return occupied - 1;
}

template<typename T>
bool Array<T>::IsEmpty()
{
    if (occupied == 0)
    {
        return true;
    }
    return false;
}

template<typename T>
void Array<T>::FreeExtra()
{
    if (occupied < size)
    {
        this->SetSize(occupied);
    }
}

template<typename T>
void Array<T>::RemoveAll()
{
    delete[] data;
    data = nullptr;
    size = 0;
    occupied = 0;
}

template<typename T>
T Array<T>::GetAt(int index)
{
    if (index >= 0 && index < occupied)
    {
        return data[index];
    }
    else {
        cout << "Invalid index" << endl;
        return T();
    }
}

template<typename T>
void Array<T>::SetAt(int index, const T& value)
{
    if (index >= 0 && index < size)
    {
        data[index] = value;
    }
    else {
        cout << "Invalid index" << endl;
    }
}

template<typename T>
T& Array<T>::operator[](int index)
{
    if (index >= 0 && index < occupied)
    {
        return data[index];
    }
    else
    {
        cout << "Invalid index" << endl;
    }
}
template<typename T>
void Array<T>::Add(const T& value)
{
    if (size == occupied)
    {
        this->SetSize(size + grow);
    }
    data[occupied] = value;
    occupied++;
}

template<typename T>
Array<T>& Array<T>::Append(Array<T>& obj)
{
    int oldSize = size;
    int tempSize = size + obj.size;
    this->SetSize(tempSize);
    for (int i = oldSize; i < tempSize; i++)
    {
        data[i] = obj.data[i - oldSize];
    }
    return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T>& obj)
{
    if (this == &obj)
    {
        return *this;
    }
    if (data != nullptr)
    {
        delete[] data;
    }
    size = obj.size;
    grow = obj.grow;
    occupied = obj.occupied;
    data = new T[size];
    for (int i = 0; i < occupied; i++)
    {
        data[i] = obj.data[i];
    }
    return *this;
}

template<typename T>
T* Array<T>::GetData()
{
    return data;
}

template<typename T>
void Array<T>::InsertAt(int index, const T& value)
{
    if (index < 0)
    {
        cout << "Invalid index" << endl;
        return;
    }
    if (index >= occupied)
    {
        if (index >= size)
        {
            this->SetSize(index + 1);
        }
        for (int i = occupied; i < index; i++)
        {
            data[i] = T();
        }
        occupied = index;
    }
    else
    {
        this->SetSize(size + 1);
        for (int i = occupied; i > index; i--)
        {
            data[i] = data[i - 1];
        }
        occupied++;
    }
    data[index] = value;
}

template<typename T>
void Array<T>::RemoveAt(int index)
{
    if (index >= 0 && index < occupied)
    {
        for (int i = index; i < occupied;i++)
        {
            data[i] = data[i + 1];
        }
        occupied--;
    }
    else
    {
        cout << "Invalid index" << endl;
    }
}

template<typename T>
Array<T>::~Array()
{
    delete[] data;
    size = 0;
    occupied = 0;
}

int main()
{
    Array<int> arr;
    arr.SetSize(5);
    arr.Add(0);
    arr.Add(1);
    arr.Add(2);
    arr.Add(3);
    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << endl;
    cout << "Upper Bound = [" << arr.GetUpperBound() << "]" << endl;
    cout << "Is empty? " << arr.IsEmpty() << endl;
    arr.RemoveAll();
    cout << "Remove All" << endl << "Is empty? " << arr.IsEmpty() << endl;
}
