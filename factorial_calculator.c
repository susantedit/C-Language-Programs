#include <stdio.h>
#include <limits.h>

/**
 * @brief Calculates the factorial of a non-negative integer iteratively.
 *
 * Factorial of n (n!) is the product of all positive integers less than or
 * equal to n. (e.g., 5! = 5 * 4 * 3 * 2 * 1 = 120).
 *
 * @param n The non-negative integer for which to calculate the factorial.
 * @return long long The factorial result, or -1 for invalid input or overflow.
 */
long long calculate_factorial(int n) {
    // 1. Input Validation
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return -1;
    }
    
    // 2. Base Cases
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // 3. Iterative Calculation
    long long result = 1;
    
    for (int i = 2; i <= n; i++) {
        // Check for potential overflow before multiplication
        // The maximum value for a long long is LLONG_MAX (from limits.h)
        if (result > LLONG_MAX / i) {
            printf("Warning: Overflow occurred! Factorial of %d is too large.\n", n);
            return -1; 
        }
        result *= i;
    }
    
    return result;
}

// --- Main Function for Demonstration ---

int main() {
    int num1 = 5;
    int num2 = 10;
    int num3 = 21; // This number causes an overflow for standard 64-bit 'long long'
    int num4 = -3;

    printf("--- C Factorial Calculator ---\n\n");

    // Test Case 1: 5!
    long long fact1 = calculate_factorial(num1);
    if (fact1 != -1) {
        printf("Factorial of %d (%d!) is: %lld\n", num1, num1, fact1);
    }

    // Test Case 2: 10!
    long long fact2 = calculate_factorial(num2);
    if (fact2 != -1) {
        printf("Factorial of %d (%d!) is: %lld\n", num2, num2, fact2);
    }

    // Test Case 3: Overflow (Demonstrates the error handling)
    long long fact3 = calculate_factorial(num3);
    if (fact3 != -1) {
        printf("Factorial of %d (%d!) is: %lld\n", num3, num3, fact3);
    }
    
    // Test Case 4: Negative number
    calculate_factorial(num4);

    return 0;
}
