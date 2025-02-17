#include "DynamicArray.h"
#include <iostream>
#include <algorithm>

// Constructor
template <typename T>
DynamicArray<T>::DynamicArray() : data(nullptr), mSize(0), mBuffer(0) {}

// Destructor
template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] data;
}

// Resize with newBuffer
template <typename T>
void DynamicArray<T>::resize(size_t newBuffer)
{
    T *newData = new T[newBuffer];

    for (size_t i = 0; i < mSize; i++)
    {
        newData[i] = std::move(data[i]);
    }

    delete[] data;
    data = newData;
    mBuffer = newBuffer;
}

// Push new element at the end of the array
template <typename T>
void DynamicArray<T>::push_back(T value)
{
    if (mSize == mBuffer)
    {
        if (mBuffer != 0)
        {
            resize(mBuffer * 2);
        }
        else
        {
            resize(1);
        }
    }
    data[mSize++] = std::move(value);
}

// Insert new element at index 'position'
template <typename T>
void DynamicArray<T>::insert(T value, size_t position)
{
    if (position > mSize)
    {
        std::cout << "Vị trí không hợp lệ\n";
        return;
    }

    if (mSize == mBuffer)
    {
        if (mBuffer != 0)
        {
            resize(mBuffer * 2);
        }
        else
        {
            resize(1);
        }
    }

    // Move element at index 'position + 1'
    for (size_t i = mSize; i > position; --i)
    {
        data[i] = std::move(data[i - 1]);
    }

    data[position] = std::move(value);
    mSize++;
}

// Remove element at index 'position'
template <typename T>
void DynamicArray<T>::remove(size_t position)
{
    if (position >= mSize)
    {
        std::cout << "Vị trí không hợp lệ\n";
        return;
    }

    for (size_t i = position; i < mSize - 1; i++)
    {
        data[i] = std::move(data[i + 1]);
    }
    mSize--;
}

template <typename T>
void DynamicArray<T>::clear()
{
    delete[] data;
    data = nullptr;
    mSize = 0;
    mBuffer = 0;
}

// Sort in ascending order
template <typename T>
void DynamicArray<T>::sortAscending()
{
    std::sort(data, data + mSize);
}

// Sort in descending order
template <typename T>
void DynamicArray<T>::sortDescending()
{
    std::sort(data, data + mSize, std::greater<T>());
}

// Search by value
template <typename T>
bool DynamicArray<T>::search(T value) const
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (data[i] == value)
        {
            return true;
        }
    }
    return false;
}

// Print the array
template <typename T>
void DynamicArray<T>::print() const
{
    if (mSize == 0)
    {
        std::cout << "Mảng rỗng\n";
        return;
    }

    std::cout << "Mảng: ";
    for (size_t i = 0; i < mSize; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
size_t DynamicArray<T>::getSize() const
{
    return mSize;
}

template <typename T>
size_t DynamicArray<T>::getBuffer() const
{
    return mBuffer;
}

// Explicit template instantiation
template class DynamicArray<int>;
template class DynamicArray<double>;
template class DynamicArray<char>;
