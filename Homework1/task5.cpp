#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::vector<int> numbers;
    int num;
    int i = 1;
    do{
        std::cin >> num;
        numbers.push_back(num);
        i++;
    }
    while(i <= 3);
    std::cout <<"MAX: " << *max_element(numbers.begin(), numbers.end()) << std::endl;    
    std::cout <<"MIN: " << *min_element(numbers.begin(), numbers.end()) << std::endl;
    // Using pipe to numbers.txt : cat numbers.txt | ./task5      
    return 0;
}