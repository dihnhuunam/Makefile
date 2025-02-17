#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <algorithm>

template <typename T>
class DynamicArray
{
private:
    T *data;
    size_t mSize;
    size_t mBuffer;

private:
    void resize(size_t newBuffer);

public:
    DynamicArray();
    ~DynamicArray();

    void push_back(T value);
    void insert(T value, size_t position);
    void remove(size_t position);
    void clear();

    void sortAscending();
    void sortDescending();
    bool search(T value) const;

    void print() const;
    size_t getSize() const;
    size_t getBuffer() const;
};

#endif /* DYNAMIC_ARRAY_H */