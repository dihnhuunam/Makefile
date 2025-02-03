#include <iostream>
#include "calculate.h"
#include "display.h"

using namespace std;

int main()
{
    Calculate test;
    cout << test.add(10, 20) << endl;

    Display demo;
    demo.show("Dinh Huu Nam");
    return 0;
}