#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include <string>

void Register();
bool Login();
void DeleteRegistration();

int main() {
    while (true) {
        int choice;
        std::string username, password;
        char answer;
        std::cout << "1. Register" << std::endl;
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Delete registration" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cin >> choice;

        if (1 == choice) {
            Register();
            std::cout << "Would you like to return to the main menu or close the program?(y/n): ";
            std::cin >> answer;
            if (answer == 'y') {
                std::cout << "----------------------------------------------" << std::endl;
                continue;
            } else if (answer == 'n') {
                return 0;
            }
        } else if (2 == choice) {
            bool isLoggedIn = Login();
            if (isLoggedIn) {
                std::cout << "Login successful." << std::endl;
                std::cout << "----------------------------------------------" << std::endl;
            } else {
                std::cout << "Login failed, please try again." << std::endl;
                std::cout << "----------------------------------------------" << std::endl;
                continue;
            }
        } else if (3 == choice) {
            DeleteRegistration();
            std::cout << "Would you like to return to the main menu or close the program?(y/n): ";
            std::cin >> answer;
            if (answer == 'y') {
                std::cout << "----------------------------------------------" << std::endl;
                continue;
            } else if (answer == 'n') {
                return 0;
            }
        } else if (4 == choice) {
            return 0;
        } else {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input, please enter a number between 1 and 4." << std::endl;
                std::cout << "----------------------------------------------" << std::endl;
                continue;
            }
                std::cout << "Invalid input, please enter a number between 1 and 4." << std::endl;
                std::cout << "----------------------------------------------" << std::endl;
        }
    }
    return 0;
}

void Register() {
    std::string username, password;
    std::ifstream fileIn("Register.txt");
    std::ofstream fileOut("Register.txt", std::ios::app);

    std::cout << "Please enter a username: " << std::endl;
    std::cin >> username;

    std::string line;
    bool usernameExists = false;
    while (std::getline(fileIn, line)) {
        if (line == username) {
            usernameExists = true;
            break;
        }
        // Skip the password lines
        std::getline(fileIn, line);  
    }
    fileIn.close();

    if (usernameExists) {
        std::cout << "Username already exists. Please try again!." << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
        Register();
        return;
    } else {
        std::cout << "Please enter a password: " << std::endl;
        std::cin >> password;
        
        // Validate password
        bool hasUpper = false;
        bool hasLower = false;
        bool hasDigit = false;
        for (char ch : password) {
            if (std::isupper(ch)) {
                hasUpper = true;
            }
            if (std::islower(ch)) {
                hasLower = true;
            }
            if (std::isdigit(ch)) {
                hasDigit = true;
            }
        }

        if(password.length() < 4){
            std::cout << "Password must be at least 4 characters long. Please try again!" << std::endl;
            Register();
            return;
        }else if (!hasUpper){
            std::cout << "Password must have at least one uppercase letter. Please try again!" << std::endl;
            Register();
            return;
        }else if(!hasLower){
            std::cout << "Password must have at least one lowercase letter. Please try again!" << std::endl;
            Register();
            return;
        }else if (!hasDigit) {
            std::cout << "Password must have at least one digit. Please try again!" << std::endl;
            Register();
            return;
        }

        fileOut << username << std::endl;
        fileOut << password << std::endl;
        fileOut.close();
        std::cout << "Registered successfully." << std::endl;
    }
}


bool Login() {
    std::string username, password;
    std::cout << "Please enter your username: " << std::endl;
    std::cin >> username;
    std::cout << "Please enter your password: " << std::endl;
    std::cin >> password;
    std::ifstream MyFile("Register.txt");
    std::string line;

    while (std::getline(MyFile, line)) {
        std::string fileUsername = line;
        std::string filePassword;
        if (std::getline(MyFile, filePassword)) {
            if (username == fileUsername && password == filePassword) {
                MyFile.close();
                return true;
            }
        }
    }
    MyFile.close();
    return false;
}

void DeleteRegistration() {
    std::string username, password;
    std::cout << "Please enter the username to delete: " << std::endl;
    std::cin >> username;
    std::cout << "Please enter the password: " << std::endl;
    std::cin >> password;

    std::ifstream fileIn("Register.txt");
    if (!fileIn.is_open()) {
        std::cerr << "Unable to open file for reading." << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    bool found = false;

    while (std::getline(fileIn, line)) {
        std::string fileUsername = line;
        std::string filePassword;
        if (std::getline(fileIn, filePassword)) {
            if (username == fileUsername && password == filePassword) {
                found = true;
                continue;
            }
            lines.push_back(fileUsername);
            lines.push_back(filePassword);
        }
    }
    fileIn.close();

    if (!found) {
        std::cout << "Registration not found." << std::endl;
        return;
    }

    std::ofstream fileOut("Register.txt", std::ios::trunc);
    if (!fileOut.is_open()) {
        std::cerr << "Unable to open file for writing." << std::endl;
        return;
    }

    for (const auto& l : lines) {
        fileOut << l << std::endl;
    }
    fileOut.close();

    std::cout << "Registration deleted successfully." << std::endl;
}
