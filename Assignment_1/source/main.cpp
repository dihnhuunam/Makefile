#include "DynamicArray.h"
#include "Utils.h"

int main()
{
    DynamicArray<int> arr;
    Command cmd;

    std::cout << "CT Quản Lý dãy số bằng mảng động\n";

    while ((cmd = getCommand()) != Command::EXIT)
    {
        switch (cmd)
        {
        case Command::CREATE:
            arr.clear();
            int size;
            size = getValidatedInt("Nhập số phần tử: ", 1, 100);
            for (int i = 0; i < size; ++i)
            {
                int value = getValidatedInt("Nhập phần tử: ", -1000000, 1000000);
                arr.push_back(value);
            }
            break;
        case Command::PRINT:
            arr.print();
            break;
        case Command::INSERT:
            arr.insert(
                getValidatedInt("Nhập số cần chèn: ", -1000000, 1000000),
                getValidatedInt("Nhập vị trí: ", 0, 100));
            break;
        case Command::DELETE:
            arr.remove(getValidatedInt("Nhập vị trí cần xóa: ", 0, 100));
            break;
        case Command::SORT_ASC:
            arr.sortAscending();
            std::cout << "Đã sắp xếp tăng dần.\n";
            break;
        case Command::SORT_DESC:
            arr.sortDescending();
            std::cout << "Đã sắp xếp giảm dần.\n";
            break;
        case Command::SEARCH:
            std::cout << (arr.search(getValidatedInt("Nhập số cần tìm: ", -1000000, 1000000))
                              ? "Tìm thấy!\n"
                              : "Không tìm thấy!\n");
            break;
        default:
            std::cout << "Lệnh không hợp lệ!\n";
        }
    }

    return 0;
}
