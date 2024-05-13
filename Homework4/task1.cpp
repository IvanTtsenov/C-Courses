#include <iostream>
#include <cstdint>

void setBit(uint64_t& attendance, int n){
    //Учениците трябва да са -1, защото индекса на битовете  започва от 0
    attendance |= (1ULL << (n -1));
}

void clearBit(uint64_t& attendance, int n){
    attendance &= ~(1ULL << (n -1));
}

void flipBit(uint64_t& attendance, int n){
    attendance ^= (1ULL << (n - 1));
}

int main(void) {
	    uint64_t attendance = 0;
	    int option;
	    while (1)
	    {
	        std::cout << "1. Set attendance" << std::endl;
	        std::cout << "2. Clear attendance" << std::endl;
	        std::cout << "3. Attendance info" << std::endl;
	        std::cout << "4. Change attendance" << std::endl;
	        std::cout << "5. Exit" << std::endl;
	        std::cin >> option;
	        if (option == 1)
	        {
	            int student;
                std::cout << "Enter student number (1-64): ";
                std::cin >> student;
                if (student < 1 || student > 64) {
                    std::cerr << "Invalid student number\n";
                    return 1;
                }else if((student & attendance) == 1){
                    std::cerr << "Student is already present, please try again\n";
                    continue;
                }
                setBit(attendance, student);
                std::cout << "Attendance set for student " << student << "\n";
                std::cout << "----------------------------------------------" << "\n";
	        }
	        else if (option == 2)
	        {
	            int student;
                std::cout << "Enter student number (1-64): ";
                std::cin >> student;
                if (student < 1 || student > 64) {
                    std::cerr << "Invalid student number\n";
                    return 1;
                }else if((student & attendance) == 0){
                    std::cerr << "Student is already missing, please clear attending students only\n";
                    continue;
                }
                clearBit(attendance, student);
                std::cout << "Attendance cleared for student " << student << "\n";
                std::cout << "----------------------------------------------" << "\n";
	        }
	        else if (option == 3)
	        {
               int studentsIn = 0;
               int studentsOut = 64;
                for (int i = 0; i < 64; ++i) {
                    if (attendance & (1ULL << i)) {
                        studentsIn++;
                    }
                
                }
	                std::cout << "Students present: ";
                    std::cout << studentsIn << "\n";
                    std::cout << "Students not present: ";
                    std::cout << studentsOut - studentsIn << "\n";
                    std::cout << "----------------------------------------------" << "\n";
	        }
	        else if(option == 4){
                int student;
                std::cout << "Enter student number (1-64): ";
                std::cin >> student;
                if (student < 1 || student > 64) {
                    std::cerr << "Invalid student number\n";
                    return 1;
                }
                flipBit(attendance, student);
                std::cout << "Attendance changed for student " << student << "\n";
                std::cout << "----------------------------------------------" << "\n";
            }
            else if(option == 5){
                std::cout << "Exiting program\n";
                return 0;
            }else {
                std::cerr << "Invalid option\n";
                return 1;
            }
	    }
	    return 0;
}
