#include "libstring.h"
#include <algorithm>

string LibString::reverseString(const string &str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    return temp;
}

string LibString::toUpperCase(const string &str)
{
    string temp = str;
    for (char &ch : temp)
    {
        ch = toupper(ch);
    }
    return temp;
}