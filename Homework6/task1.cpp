#include <iostream>

void arraysMerged(int arr1[], int arr2[], int size1, int size2);

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[] = {11, 4, 77, 22};
    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);
    arraysMerged(arr1, arr2, size1, size2);
    return 0;
}

void arraysMerged(int arr1[], int arr2[], int size1, int size2)
{
    int size = size1 + size2;
    int arr3[size];

    for (int i = 0; i < size1; i++){
        arr3[i] = arr1[i];
    }

    for (int i = 0; i < size2; i++){
        arr3[size1 + i] = arr2[i];
    }

    for (int i = 0; i < size; i++){
          for (int j = 0; j < size - i - 1; j++){

            if (arr3[j] > arr3[j + 1]){
                
                int temp = arr3[j];
                arr3[j] = arr3[j + 1];
                arr3[j + 1] = temp;
            }
        }
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;
}
