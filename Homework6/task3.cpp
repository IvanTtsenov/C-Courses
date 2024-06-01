#include <iostream>

int main() {
    std::string str1 = "bool";
    std::string str2 = "loob";
    std::string temp;
    if(str1.length() != str2.length()){
        std::cout << "Strings can not be anagrams!" << std::endl;
    }

    for (int i = str1.length() -1; i >= 0; i--){
        temp += str1[i];
    }
    if(temp == str2){
        std::cout << "The strings are anagrams!" << std::endl;
    }else {
        std::cout << "The strings are not anagrams!" << std::endl;
    }
    
    return 0;
}
