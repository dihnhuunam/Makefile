#include "Utils.h"
#include <limits>

std::map<char, MenuFunction> Utils::mapActions;
std::vector<char> Utils::choices;

void Utils::initMapActions()
{
    Utils::mapActions = {
        {'c', handleCreate},
        {'p', handlePrint},
        {'i', handleInsert},
        {'d', handleRemove},
        {'s', handleSortAscending},
        {'x', handleSortDescending},
        {'t', handleSearch}};

    for (const auto &pair : Utils::mapActions)
    {
        Utils::choices.push_back(pair.first);
    }
}

int Utils::getValidInt(const std::string &prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Xóa bộ đệm
            return value;
        }
        else
        {
            std::cout << "Dữ liệu nhập không hợp lệ, vui lòng nhập lại!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Utils::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Utils::waitForEnter()
{
    std::cout << "\nNhấn Enter để tiếp tục ...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Chờ người dùng nhấn Enter
}

void Utils::display()
{
    clearScreen();
    std::cout << "================= QUẢN LÝ DÃY SỐ =================\n";
    std::cout << "Nhập 'c' để tạo mảng số nguyên\n";
    std::cout << "Nhập 'p' để in dãy số\n";
    std::cout << "Nhập 'i' để thêm 1 phần tử vào dãy\n";
    std::cout << "Nhập 'd' để xóa 1 phần tử tại vị trí k\n";
    std::cout << "Nhập 's' để sắp xếp tăng dần\n";
    std::cout << "Nhập 'x' để sắp xếp giảm dần\n";
    std::cout << "Nhập 't' để tìm kiếm số x trong dãy\n";
    std::cout << "Nhập 'e' để thoát chương trình\n";
    std::cout << "=================================================\n";
    std::cout << "Nhập lựa chọn của bạn: ";
}

void Utils::handleCreate(ArrayManager &arr)
{
    int size = getValidInt("Nhập kích thước của mảng: ");
    arr.create(size);
}

void Utils::handlePrint(ArrayManager &arr)
{
    std::cout << "Mảng: ";
    arr.print();
}

void Utils::handleInsert(ArrayManager &arr)
{
    int value = getValidInt("Nhập giá trị cần chèn: ");
    int index = getValidInt("Nhập vị trí cần chèn: ");
    if (index > arr.size() || index < 0)
    {
        std::cout << "Vị trí không hợp lệ\n";
        return;
    }
    arr.insert(value, index);
    std::cout << "Đã chèn " << value << " tại " << index << std::endl;
}

void Utils::handleRemove(ArrayManager &arr)
{
    int index = getValidInt("Nhập vị trí cần xóa: ");
    if (index > arr.size() - 1 || index < 0)
    {
        std::cout << "Vị trí không hợp lệ\n";
        return;
    }
    arr.remove(index);
    std::cout << "Đã xóa phần tử tại vị trí " << index << std::endl;
}

void Utils::handleSortAscending(ArrayManager &arr)
{
    arr.sortAscending();
    std::cout << "Mảng đã được sắp xếp tăng dần.\n";
}

void Utils::handleSortDescending(ArrayManager &arr)
{
    arr.sortDescending();
    std::cout << "Mảng đã được sắp xếp giảm dần.\n";
}

void Utils::handleSearch(ArrayManager &arr)
{
    int value = getValidInt("Nhập số cần tìm kiếm: ");
    if (arr.search(value))
    {
        std::cout << "Giá trị " << value << " có trong mảng.\n";
    }
    else
    {
        std::cout << "Giá trị " << value << " không có trong mảng.\n";
    }
}

void Utils::run(ArrayManager &arr)
{
    initMapActions();

    while (true)
    {
        display();
        char choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Xóa bộ đệm sau khi nhập ký tự

        if (choice == 'e')
        {
            std::cout << "Thoát chương trình...\n";
            return;
        }

        auto it = mapActions.find(choice);
        if (it != mapActions.end())
        {
            it->second(arr);
        }
        else
        {
            std::cout << "Lựa chọn không hợp lệ!\n";
        }

        waitForEnter();
    }
}
