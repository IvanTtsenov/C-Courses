#include <iostream>
#include <limits>

int main() {
    while (true) {
        std::string mathOperatorion;
        long double number1;
        long double number2;
        long double result;

        std::cout << "Enter first number" << std::endl;
        std::cin >> number1;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid number!" << std::endl;
            continue;
        }

        std::cout << "Enter operation (+ , -, *, /)" << std::endl;
        std::cin >> mathOperatorion;

        if (mathOperatorion != "+" && mathOperatorion != "-" && mathOperatorion != "*" && mathOperatorion != "/") {
            std::cout << "Invalid operation!" << std::endl;
            continue;
        }

        std::cout << "Enter second number" << std::endl;
        std::cin >> number2;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid number!" << std::endl;
            continue;
        }

        if (mathOperatorion == "+") {
            result = number1 + number2;
        } else if (mathOperatorion == "-") {
            result = number1 - number2;
        } else if (mathOperatorion == "/") {
            if (number2 == 0) {
                std::cout << "Cannot divide by zero!" << std::endl;
                continue;
            }
            result = number1 / number2;
        } else if (mathOperatorion == "*") {
            result = number1 * number2;
        }

        std::cout << "Result: " << result << std::endl;
        std::cout << "---------------------------------" << std::endl;
    }
    return 0;
}
