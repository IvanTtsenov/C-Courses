#include <iostream>
#include <cmath>
#include <limits>

bool areEqualAbs(float a, float b, float epsilon) {
    return std::abs(a - b) <= epsilon;
}

bool areEqualRel(float a, float b, float epsilon) {
    return std::abs(a - b) <= epsilon * std::max(std::abs(a), std::abs(b));
}

bool areEqualComb(float a, float b, float absEpsilon, float relEpsilon) {
    float diff = std::abs(a - b);
    if (diff <= absEpsilon)
        return true;
    return diff <= std::max(std::abs(a), std::abs(b)) * relEpsilon;
}

int main() {
    float num1 = 0.15 * 7;  // 1.05
    float num2 = 0.1 + 0.95;  // 1.05

    std::cout << "Absolute comparison: " << areEqualAbs(num1, num2, std::numeric_limits<float>::epsilon()) << std::endl;
    std::cout << "Relative comparison: " << areEqualRel(num1, num2, std::numeric_limits<float>::epsilon()) << std::endl;
    std::cout << "Combined comparison: " << areEqualComb(num1, num2, std::numeric_limits<float>::epsilon(), std::numeric_limits<float>::epsilon()) << std::endl;

    return 0;
}
