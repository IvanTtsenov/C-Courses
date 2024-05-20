#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if(n >= 1 && n % 2 == 0) {
        return false;
    }else if(n >= 1 && n % 3 == 0) {
        return false;
    }else {
        return true;
    }
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    if (isPrime(number)) {
        std::cout << number << " is a prime number." << std::endl;
    } else {
        std::cout << number << " is not a prime number." << std::endl;
    }
    return 0;
}
