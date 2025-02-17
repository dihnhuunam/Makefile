#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>

enum class Command
{
    CREATE = 'c',
    PRINT = 'p',
    INSERT = 'i',
    DELETE = 'd',
    SORT_ASC = 's',
    SORT_DESC = 'x',
    SEARCH = 't',
    EXIT = 'e',
    INVALID = -1
};

Command getCommand()
{
    char input;
    std::cout << "\nNhập lệnh: ";
    std::cin >> input;
    return static_cast<Command>(input);
}

int getValidatedInt(const std::string &prompt, int min, int max)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        if (!(std::cin >> value))
        {
            std::cout << "Lỗi nhập! Hãy nhập số nguyên.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (value < min || value > max)
        {
            std::cout << "Giá trị ngoài phạm vi [" << min << ", " << max << "]!\n";
        }
        else
        {
            return value;
        }
    }
}

#endif /* UTILS_H */
