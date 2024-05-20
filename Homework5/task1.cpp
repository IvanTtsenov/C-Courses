#include <iostream>
#include <cmath>

double circleArea(double radius) {
    return M_PI * pow(radius,2);
}

int main() {
    double radius;
    std::cout << "Enter circle radius: ";
    std::cin >> radius;
    std::cout << "The area of the circle is: " << circleArea(radius) << std::endl;
    return 0;
}
