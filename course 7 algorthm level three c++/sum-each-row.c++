#include <iostream>
#include "mylibs.h"
using namespace std;




void readmatrix(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = mylib::RandomNumber(1 , 100);
        }
        
    }

    
}

void printmatrix(int matrix[3][3])
{
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           cout << matrix[i][j] << "\t";
        }
        cout << endl;
        
    }

}


void sum_row(int matrix[3][3]){

    int sum = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += matrix[i][j];
        }

        cout << "Row " << i + 1  << " sum = " << sum;
        cout << endl;
        sum = 0;

    }
    
}




int main(){
    srand((unsigned)time(NULL));

    int matrix[3][3];
    cout << "the following 3*3 matrix : " << endl;
    readmatrix(matrix);
    printmatrix(matrix);


    cout << endl << "the following sum of each row : " << endl; 
    sum_row(matrix);  


}      
