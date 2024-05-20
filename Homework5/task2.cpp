#include <iostream>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int factorialNumber =1;
    for (int i = 2; i <= n; ++i) {
        factorialNumber *= i;
    }
    return factorialNumber;
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "The factorial of " << number << " is: " << factorial(number) << std::endl;
    return 0;
}
