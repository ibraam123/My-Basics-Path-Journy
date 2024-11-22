#include <iostream>
#include "mylibs.h"
using namespace std;

void readmatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = mylib::RandomNumber(1, 10);
        }
    }
}

void printmatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void multiplyMatrices(int resultMatrix[3][3], int matrixA[3][3], int matrixB[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultMatrix[i][j] = matrixA[i][j] * matrixB[i][j];
        }
    }
}

int main() {
    int matrixA[3][3];
    int matrixB[3][3];
    int resultMatrix[3][3];

    cout << "Matrix 1:" << endl;
    readmatrix(matrixA);
    printmatrix(matrixA);

    cout << "Matrix 2:" << endl;
    readmatrix(matrixB);
    printmatrix(matrixB);

    cout << "Resultant Matrix (Element-wise Multiplication):" << endl;
    multiplyMatrices(resultMatrix, matrixA, matrixB);
    printmatrix(resultMatrix);

    return 0;
}
