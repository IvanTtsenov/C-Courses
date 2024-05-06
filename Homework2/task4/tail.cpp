#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void tail(const std::string filename) {
    int numLines = 10;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    int start = lines.size() - 10;

    for(int i = start; i < lines.size(); i++) {
        std::cout << lines[i] << std::endl;
    }
}

int main(int argc, char **argv) {

     if (argc < 2) {
        std::cerr << "Filename required!: ./tail filename.ext" << std::endl;
        return 1;
    }

    if(2 >= argc){
        tail(argv[1]);
    }
    return 0;
}
