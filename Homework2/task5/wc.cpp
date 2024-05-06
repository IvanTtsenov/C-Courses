#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

void wc(const std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }

    int lines = 0, words = 0, bytes = 0;
    std::string line;
    while (std::getline(file, line)) {
        ++lines;
        bytes += line.size();
        bool isWord = false;

        for (char c : line) {

            if (std::isspace(c)) {
                isWord = false;
            } else if (!isWord) {
                isWord = true;
                ++words;
            }

        }
    }

    std::cout << lines << " " << words << " " << bytes << " " << filename << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Filename required!: ./wc filename.ext" << std::endl;
        return 1;
    }

    if(2 >= argc){
        wc(argv[1]);
    }
    return 0;
}
