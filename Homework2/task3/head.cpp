#include <iostream>
#include <fstream>
#include <cstring>

void head(const std::string filename) {
    int numLines = 10;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }

    std::string line;
    for (int i = 0; i < numLines; ++i) {
        if (!std::getline(file, line)) {
            break;
        }
        std::cout << line << std::endl;
    }
}

int main(int argc, char **argv) {

     if (argc < 2) {
        std::cerr << "Filename required!: ./head filename.ext" << std::endl;
        return 1;
    }

    if(2 >= argc){
        head(argv[1]);
    }
    return 0;
}