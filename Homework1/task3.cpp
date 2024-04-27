#include <iostream>
#include <cmath>

double verticalBarrel();
double horizontalBarrel();

double area(int radius) {
    return M_PI * (radius * radius);
}

double area(int r, int h) {
    return acos((1 - h/r)) * pow(r, 2) - (r - h) * sqrt(2*r*h - pow(h, 2));
}

int main () {
    char answer;
    std::cout << "Is the barrel vertical? (y/n): " << std::endl;
    std::cin >> answer;
    if( answer ==  'y' || answer == 'Y'){
        std::cout << verticalBarrel();
        return 0;
    }else if( answer ==  'n' || answer == 'N'){
        std::cout << horizontalBarrel();
        return 0;
    }else{
        std::cerr << "Invalid input" << std::endl;
        return 1;
    }

   return 0;
}

double verticalBarrel (){
    int r;
    int h;

    std::cout << "Please enter barrel radius in m: ";
    std::cin >> r;
    std::cout << "Please enter water height in m: ";
    std::cin >> h;
    std::cout << "Volume of the water is: " << area(r) * h;
    return 0;
}

double horizontalBarrel(){
    int r;
    int h;
    int l;

    std::cout << "Please enter barrel radius: ";
    std::cin >> r;
    std::cout << "Please enter water height: ";
    std::cin >> h;
    std::cout << "Please enter barrel length: ";
    std::cin >> l;
    std::cout << "Volume of the water is: " << area(r,h) * l;
    return 0;
}
