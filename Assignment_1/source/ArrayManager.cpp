#include "ArrayManager.h"
#include <algorithm>

ArrayManager::ArrayManager() {}

ArrayManager::~ArrayManager()
{
    data.clear();
}

void ArrayManager::clear()
{
    data.clear();
    std::cout << "Mảng đã được xóa\n";
}

void ArrayManager::create(int size)
{
    if (size <= 0)
    {
        std::cout << "Kích thước không hợp lệ\n";
        return;
    }
    data.resize(size);
    std::cout << "Nhập " << size << " phần tử: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> data[i];
    }
}

void ArrayManager::print() const
{
    if (data.empty())
    {
        std::cout << "Mảng rỗng\n";
        return;
    }

    for (int num : data)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void ArrayManager::insert(int value, int index)
{
    if (index < 0 || index > data.size())
    {
        std::cout << "Vị trí không hợp lệ\n";
    }

    data.insert(data.begin() + index, value);
}

void ArrayManager::remove(int index)
{
    if (index < 0 || index >= data.size())
    {
        std::cout << "Vị trí không hợp lệ\n";
    }

    data.erase(data.begin() + index);
}

void ArrayManager::sortAscending()
{
    sort(data.begin(), data.end());
}

void ArrayManager::sortDescending()
{
    sort(data.begin(), data.end(), std::greater<int>());
}

bool ArrayManager::search(int value) const
{
    auto temp = std::find(data.begin(), data.end(), value);
    if (temp != data.end())
    {
        return true;
    }
    return false;
}

int ArrayManager::size() const
{
    return data.size();
}