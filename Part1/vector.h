#pragma once

template <typename T>
class Vector
{
public:
    Vector(unsigned int size = 0);
    ~Vector();

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
    T *_array = nullptr;
    unsigned int _capacity;
    unsigned int _size;
};

template <typename T>
Vector<T>::Vector(unsigned int size)
    : _size(0), _capacity(0)
{
    _array = new T[size];
    for (int i = 0; i < size; i++)
        _array[i] = T();

    _size = size;
    _capacity = size;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] _array;
}

template <typename T>
void Vector<T>::push(const T &object)
{
    if (_size == _capacity)
        _Reallocate(_capacity + _capacity / 2 + 1);

    _array[_size] = object;
    _size++;
}

template <typename T>
void Vector<T>::insert(const T &object, unsigned int index)
{
    if (_size == _capacity)
        _Reallocate(_capacity + _capacity / 2 + 1);

    for (int i = _size; i > index; i--)
        _array[i] = _array[i - 1];

    _array[index] = object;
    _size++;
}

template <typename T>
void Vector<T>::remove(unsigned int index)
{
    for (int i = index; i < _size - 1; i++)
        _array[i] = _array[i + 1];
    _size--;
}

template <typename T>
unsigned int Vector<T>::size() const
{
    return _size;
}

template <typename T>
T &Vector<T>::operator[](unsigned int index)
{
    return _array[index];
}

template <typename T>
const T &Vector<T>::operator[](unsigned int index) const
{
    return _array[index];
}

template <typename T>
void Vector<T>::_Reallocate(unsigned int capacity)
{
    T *temp = new T[capacity];
    for (int i = 0; i < capacity; i++)
    {
        if (i < _size)
            temp[i] = _array[i];

        else
            temp[i] = T();
    }

    delete[] _array;
    _array = temp;
    _capacity = capacity;
}
