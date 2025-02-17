#include "DynamicArray.h"

int main()
{
    DynamicArray<int> arr;
    arr.print();
    arr.push_back(10);
    arr.push_back(11);
    arr.push_back(12);
    arr.push_back(13);
    arr.push_back(14);
    arr.print();

    return 0;
}