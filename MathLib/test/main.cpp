#include "math_ultis.h"
#include <cassert>
#include <iostream>

void test_add() {
    MathUltis math;
    
    std::cout << "\n=== Testing Addition ===\n";
    
    // Test case 1: Basic addition
    std::cout << "Test 1: 2 + 3 = " << math.add(2, 3) << "\n";
    assert(math.add(2, 3) == 5);
    
    // Test case 2: Adding zero
    std::cout << "Test 2: 5 + 0 = " << math.add(5, 0) << "\n";
    assert(math.add(5, 0) == 5);
    
    // Test case 3: Adding negative numbers
    std::cout << "Test 3: -2 + (-3) = " << math.add(-2, -3) << "\n";
    assert(math.add(-2, -3) == -5);
    
    // Test case 4: Adding positive and negative
    std::cout << "Test 4: -2 + 3 = " << math.add(-2, 3) << "\n";
    assert(math.add(-2, 3) == 1);
}

void test_multiply() {
    MathUltis math;
    
    std::cout << "\n=== Testing Multiplication ===\n";
    
    // Test case 1: Basic multiplication
    std::cout << "Test 1: 2 * 3 = " << math.multiply(2, 3) << "\n";
    assert(math.multiply(2, 3) == 6);
    
    // Test case 2: Multiplying by zero
    std::cout << "Test 2: 5 * 0 = " << math.multiply(5, 0) << "\n";
    assert(math.multiply(5, 0) == 0);
    
    // Test case 3: Multiplying negative numbers
    std::cout << "Test 3: -2 * (-3) = " << math.multiply(-2, -3) << "\n";
    assert(math.multiply(-2, -3) == 6);
    
    // Test case 4: Multiplying positive and negative
    std::cout << "Test 4: -2 * 3 = " << math.multiply(-2, 3) << "\n";
    assert(math.multiply(-2, 3) == -6);
}

int main() {
    std::cout << "Starting Tests...\n";
    
    test_add();
    test_multiply();
    
    std::cout << "\nAll tests passed successfully!\n";
    return 0;
}