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

void middlerow(int matrix[3][3] , int row)
{
    for (int i = 0; i < 3; i++)
    {
        cout << matrix[row][i] << "\t";
    }
    cout << endl;
    
}

void middlecol(int matrix[3][3] , int col)
{
    for (int i = 0; i < 3; i++)
    {
        cout << matrix[i][col] << "\t";
    }
    cout << endl;
    
}

int main()
{

    srand((unsigned)time(NULL));

    int matrix[3][3] ;


    readmatrix(matrix);

    cout << " the following matrix 3*3 is : " << endl;
    printmatrix(matrix);

    cout << "\n middile row of matrix is : " << endl;
    middlerow(matrix , 1);

    cout << "\n middile col of matrix is : " << endl;
    middlecol(matrix , 1);

    return 0;

}