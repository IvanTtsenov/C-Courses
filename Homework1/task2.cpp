#include <iostream>
#include <cmath>

double calculateBMI(double mass,double height,bool isNewFormula){
    if(isNewFormula){
        return 1.3 * mass/ pow(height,2.5);
    }else {
        return mass/ pow(height,2);
    }
}

int main() {
    double mass,height;
    bool isNewFormula;
    char answer;
    std::cout << "Enter your mass in kg: ";
    std::cin >> mass;
    std::cout << "Enter your height in m: ";
    std::cin >> height;
    std::cout << "Do you want to use the new formula? (y/n): ";
    std::cin >> answer;
    if( answer ==  'y' || answer == 'Y'){
        isNewFormula = true;
    }else if( answer ==  'n' || answer == 'N'){
        isNewFormula = false;
    }else{
        std::cerr << "Invalid input" << std::endl;
        return 1;
    }
    std::cout << "Your BMI is: " << calculateBMI(mass,height,isNewFormula) << std::endl;
    return 0;
}