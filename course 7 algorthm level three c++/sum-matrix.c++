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

    int matrix[3][3];

    readmatrix(matrix);

    cout << " the following matrix 3*3 is : " << endl;
    printmatrix(matrix);

    cout << "\n sum of all matrix = " <<sum_matrix(matrix);

    return 0;
}