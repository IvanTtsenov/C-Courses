#include <iostream>

long long fibonacci(int n) {
    if (n <= 1){
        return n;
    } 
    long long firstN = 0;
    long long nextN = 1;
    long long sumN;
    for (int i = 2; i <= n; ++i) {
        sumN = firstN + nextN;
        firstN = nextN;
        nextN = sumN;
    }
    return sumN;
}

int main() {
    int n;
    std::cout << "Enter the position of the Fibonacci number: ";
    std::cin >> n;
    std::cout << "The Fibonacci number is: " << fibonacci(n) << std::endl;
    return 0;
}
