#pragma once

template <typename T>
class VectorPtr
{
public:
    VectorPtr(unsigned int size = 0);
    ~VectorPtr();

public:
    void push(const T &object);
    void insert(const T &object, unsigned int index);
    void remove(unsigned int index);
    unsigned int size() const;
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;

private:
    void _Reallocate(unsigned int capacity);

private:
    T **_array = nullptr;
    unsigned int _capacity;
    unsigned int _size;
};

template <typename T>
VectorPtr<T>::VectorPtr(unsigned int size)
    : _capacity(0), _size(0)
{
    _array = new T *[size];
    for (int i = 0; i < size; i++)
        _array[i] = new T();

    _size = size;
    _capacity = size;
}

template <typename T>
VectorPtr<T>::~VectorPtr()
{
    for (int i = 0; i < _capacity; i++)
        delete _array[i];
    delete[] _array;
}

template <typename T>
void VectorPtr<T>::push(const T &object)
{
    if (_size == _capacity)
        _Reallocate(_capacity + _capacity / 2 + 1);

    delete _array[_size];
    _array[_size] = new T(object);
    _size++;
}

template <typename T>
void VectorPtr<T>::insert(const T &object, unsigned int index)
{
    if (_size == _capacity)
        _Reallocate(_capacity + _capacity / 2 + 1);

    delete _array[_size];

    for (int i = _size; i > index; i--)
        _array[i] = _array[i - 1];

    _array[index] = new T(object);
    _size++;
}

template <typename T>
void VectorPtr<T>::remove(unsigned int index)
{
    delete _array[index];

    for (int i = index; i < _size - 1; i++)
        _array[i] = _array[i + 1];

    _size--;
    _array[_size] = new T();
}

template <typename T>
unsigned int VectorPtr<T>::size() const
{
    return _size;
}

template <typename T>
T &VectorPtr<T>::operator[](unsigned int index)
{
    return *(_array[index]);
}

template <typename T>
const T &VectorPtr<T>::operator[](unsigned int index) const
{
    return *(_array[index]);
}

template <typename T>
void VectorPtr<T>::_Reallocate(unsigned int capacity)
{
    T **temp = new T *[capacity];

    for (int i = 0; i < capacity; i++)
    {
        if (i < _size)
            temp[i] = _array[i];
        else
            temp[i] = new T();
    }

    delete[] _array;
    _array = temp;
    _capacity = capacity;
}
