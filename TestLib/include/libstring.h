#ifndef LIBSTRING_H
#define LIBSTRING_H

#include <iostream>
#include <string>

using namespace std;

class LibString
{
public:
    string reverseString(const string &str);
    string toUpperCase(const string &str);
};

#endif /* LIBSTRING_H */