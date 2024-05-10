#include <iostream>

bool synthByOne(int a, int b, int c) {
    return (!a && !b && !c) || (!a && b && !c) || (!a && b && c) || (a && b && c);
}

bool synthByZero(int a, int b, int c) {
    return (a && !b && c) || (a && !b && !c) || (!a && b && !c);
}

bool minimized(int a, int b, int c) {
    return (!a && b) || (a && c);
}

int main(){
    int a,b,c;
    std::cout <<"Type first number: " << std::endl;
    std::cin >> a;
    std::cout <<"Type second number: " << std::endl;
    std::cin >> b;
    std::cout <<"Type third number: " << std::endl;
    std::cin >> c;
    
    std::cout << "Function \"synthByOne\" for synthesis by '1': " << synthByOne(a,b,c) << std::endl;
    std::cout << "Function \"synthByZero\" for synthesis by '0': " << synthByZero(a,b,c) << std::endl;
    std::cout << "Minimized function: " << minimized(a,b,c) << std::endl;
    return 0;
}