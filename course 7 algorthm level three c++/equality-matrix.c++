#include <iostream>
#include "mylibs.h"
using namespace std;

void readmatrix(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = mylib::RandomNumber(1,10);
            }
        
        
    }
    
}

void printmatrix(int matrix[3][3]){

    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
            {
               cout << matrix[i][j] << "\t" ;
            }
        cout << endl;
        
    }

}

int sum_matrix(int matrix[3][3])
{
    int sum = 0;

    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
            {
               sum += matrix[i][j];
            }
       
        
    }

    return sum;

}


int main(){


    srand((unsigned)time(NULL));

    int matrix_one[3][3];
    int matrix_two[3][3];

    readmatrix(matrix_one);


    
    cout << " the following matrix one : " << endl;
    printmatrix(matrix_one);

    readmatrix(matrix_two);

    cout << " the following matrix two : " << endl;
    printmatrix(matrix_two);

    if (sum_matrix(matrix_one) == sum_matrix(matrix_two))
    {
        cout << "Yes, the matrises is equal " << endl;
    }
    else
    {
        cout << "NO, the matrises not equal" << endl;
    }
    
    

    return 0;
}