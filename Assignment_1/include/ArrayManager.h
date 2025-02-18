#ifndef ARRAY_MANAGER_H
#define ARRAY_MANAGER_H

#include <vector>
#include <iostream>

class ArrayManager
{
private:
    std::vector<int> data;

public:
    ArrayManager();
    ~ArrayManager();
    void create(int size);
    void clear();
    void print() const;
    void insert(int value, int index);
    void remove(int index);
    void sortAscending();
    void sortDescending();
    bool search(int value) const;
    int size() const;
};

#endif /* ARRAY_MANAGER_H */