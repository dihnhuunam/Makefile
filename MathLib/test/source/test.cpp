#include "test.h"
#include "mathlib.h"
#include <iostream>

using namespace std;

void test_add()
{
    MathLib math;

    cout << "\n=== Testing Addition ===\n";

    // Test case 1: Basic addition
    int result = math.add(2, 3);
    cout << "Test 1: 2 + 3 = " << result << "\n";
    if (result != 5)
        cout << "Error: Expected 5, got " << result << "\n";

    // Test case 2: Adding zero
    result = math.add(5, 0);
    cout << "Test 2: 5 + 0 = " << result << "\n";
    if (result != 5)
        cout << "Error: Expected 5, got " << result << "\n";

    // Test case 3: Adding negative numbers
    result = math.add(-2, -3);
    cout << "Test 3: -2 + (-3) = " << result << "\n";
    if (result != -5)
        cout << "Error: Expected -5, got " << result << "\n";

    // Test case 4: Adding positive and negative
    result = math.add(-2, 3);
    cout << "Test 4: -2 + 3 = " << result << "\n";
    if (result != 1)
        cout << "Error: Expected 1, got " << result << "\n";
}

void test_multiply()
{
    MathLib math;

    cout << "\n=== Testing Multiplication ===\n";

    // Test case 1: Basic multiplication
    int result = math.multiply(2, 3);
    cout << "Test 1: 2 * 3 = " << result << "\n";
    if (result != 6)
        cout << "Error: Expected 6, got " << result << "\n";

    // Test case 2: Multiplying by zero
    result = math.multiply(5, 0);
    cout << "Test 2: 5 * 0 = " << result << "\n";
    if (result != 0)
        cout << "Error: Expected 0, got " << result << "\n";

    // Test case 3: Multiplying negative numbers
    result = math.multiply(-2, -3);
    cout << "Test 3: -2 * (-3) = " << result << "\n";
    if (result != 6)
        cout << "Error: Expected 6, got " << result << "\n";

    // Test case 4: Multiplying positive and negative
    result = math.multiply(-2, 3);
    cout << "Test 4: -2 * 3 = " << result << "\n";
    if (result != -6)
        cout << "Error: Expected -6, got " << result << "\n";
}
