#include <iostream>

void multiplyMatrices(int mat1[][2], int mat2[][2], int result[][2], int rows1, int cols1, int rows2, int cols2);

int main() {
    int mat1[2][2] = {
        {1, 2},
        {4, 5}
    };
    
    int mat2[2][2] = {
        {7, 8},
        {9, 10}
    };
    
    int rows1 = sizeof(mat1) / sizeof(mat1[0]);
    int cols1 = sizeof(mat1[0]) / sizeof(int);
    int rows2 = sizeof(mat2) / sizeof(mat2[0]);
    int cols2 = sizeof(mat2[0]) / sizeof(int);

    if (cols1 != rows2) {
        std::cout << "Matrices cannot be multiplied due to incompatible dimensions." << std::endl;
        return 1;
    }

    int result[2][2] = {0};

    multiplyMatrices(mat1, mat2, result, rows1, cols1, rows2, cols2);

    std::cout << "Result matrix: " << std::endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

void multiplyMatrices(int mat1[][2], int mat2[][2], int result[][2], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
