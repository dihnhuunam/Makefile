#include "stringlib.h"
#include <algorithm>

string StringLib::reverseString(const string &str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    return temp;
}

string StringLib::toUpperCase(const string &str)
{
    string temp = str;
    for (char &ch : temp)
    {
        ch = toupper(ch);
    }
    return temp;
}