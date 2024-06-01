#include <iostream>

int majorityElement(int arr[], int size) {
    int counter = 0;
    int temp = -1;
    
    for (int i = 0; i < size; i++) {
        if (counter == 0) {
            temp = arr[i];
            counter = 1;
        } else if (arr[i] == temp) {
            counter++;
        } else {
            counter--;
        }
    }
    
    counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == temp) {
            counter++;
        }
    }
    
    if (counter > size / 2) {
        return temp;
    } else {
        return -1;
    }
}

int main() {
    int arr[] = {5,4,1,2,3,5,5,8,5,5,5,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int findElement = majorityElement(arr, size);

    if (findElement != -1) {
        std::cout << "Majority Element: " << findElement << std::endl;
    } else {
        std::cout << "No Majority Element" << std::endl;
    }
    return 0;
}
