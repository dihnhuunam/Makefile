#include <iostream>
#include <cstdint>
#include <algorithm>
#include <limits>

int main()
{
    uint16_t size;

    while (true)
    {
        std::cout << "Nhập vào số lượng phần tử: ";
        std::cin >> size;
        if (std::cin.fail() || size <= 0 || size >= 255)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Kích thước không hợp lệ! Vui lòng nhập từ 1 đến 254\n";
        }
        else
        {
            break;
        }
    }

    uint16_t *aptr = new uint16_t[size];

    std::cout << "Nhập phần tử\n";
    for (uint16_t i = 0; i < size; i++)
    {
        std::cout << "Phần tử thứ " << i + 1 << " :";
        while (true)
        {
            int temp;
            std::cin >> temp;
            if (std::cin.fail() || temp < 0 || temp > 65535)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Giá trị phần tử không hợp lê! Vui lòng nhập lại\n";
                std::cout << "Phần tử thứ " << i + 1 << " :";
            }
            else
            {
                aptr[i] = static_cast<uint16_t>(temp);
                break;
            }
        }
    }

    std::cout << "Mảng nguyên dương theo thứ tự ngược:   ";
    for (int16_t i = size - 1; i >= 0; i--)
    {
        std::cout << static_cast<void *>(aptr + i) << ": " << aptr[i] << "   ";
    }
    std::cout << std::endl;

    uint16_t *bptr = std::max_element(aptr, aptr + size);
    std::cout << "Phần tử có giá trị lớn nhất:           " << static_cast<void *>(bptr) << ": " << *bptr << std::endl;

    delete[] aptr;
    aptr = nullptr;
    bptr = nullptr;

    return 0;
}