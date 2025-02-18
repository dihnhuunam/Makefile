#ifndef UTILS_H
#define UTILS_H

#include <functional>
#include <map>
#include <vector>
#include "ArrayManager.h"

typedef std::function<void(ArrayManager &)> MenuFunction;

class Utils
{
private:
    static std::map<char, MenuFunction> mapActions;

private:
    static void handleCreate(ArrayManager &arr);
    static void handlePrint(ArrayManager &arr);
    static void handleInsert(ArrayManager &arr);
    static void handleRemove(ArrayManager &arr);
    static void handleSortAscending(ArrayManager &arr);
    static void handleSortDescending(ArrayManager &arr);
    static void handleSearch(ArrayManager &arr);

public:
    static void initMapActions();
    static int getValidInt(const std::string &prompt);
    static void clearScreen();
    static void waitForEnter();
    static void display();
    static void run(ArrayManager &arr);
};

#endif /* UTILS_H */