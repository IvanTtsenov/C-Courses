#include <iostream>
//cat numbers.txt | ./task1
int main(){
    int num1,num2;
    int i = 1;
    do{
        if(i == 1){
            std::cin >> num1;
        }else if(i == 2){
            std::cin >> num2;
        }
        i++;
    }
    while(i <= 2);
    std::cout << (num1 ^ num2)<< std::endl;    
    return 0;
}