#include "test.h"
#include "math_ultis.h"

void test_add() {
    MathUltis math;
    
    cout << "\n=== Testing Addition ===\n";
    
    // Test case 1: Basic addition
    cout << "Test 1: 2 + 3 = " << math.add(2, 3) << "\n";
    assert(math.add(2, 3) == 5);
    
    // Test case 2: Adding zero
    cout << "Test 2: 5 + 0 = " << math.add(5, 0) << "\n";
    assert(math.add(5, 0) == 5);
    
    // Test case 3: Adding negative numbers
    cout << "Test 3: -2 + (-3) = " << math.add(-2, -3) << "\n";
    assert(math.add(-2, -3) == -5);
    
    // Test case 4: Adding positive and negative
    cout << "Test 4: -2 + 3 = " << math.add(-2, 3) << "\n";
    assert(math.add(-2, 3) == 1);
}

void test_multiply() {
    MathUltis math;
    
    cout << "\n=== Testing Multiplication ===\n";
    
    // Test case 1: Basic multiplication
    cout << "Test 1: 2 * 3 = " << math.multiply(2, 3) << "\n";
    assert(math.multiply(2, 3) == 6);
    
    // Test case 2: Multiplying by zero
    cout << "Test 2: 5 * 0 = " << math.multiply(5, 0) << "\n";
    assert(math.multiply(5, 0) == 0);
    
    // Test case 3: Multiplying negative numbers
    cout << "Test 3: -2 * (-3) = " << math.multiply(-2, -3) << "\n";
    assert(math.multiply(-2, -3) == 6);
    
    // Test case 4: Multiplying positive and negative
    cout << "Test 4: -2 * 3 = " << math.multiply(-2, 3) << "\n";
    assert(math.multiply(-2, 3) == -6);
}