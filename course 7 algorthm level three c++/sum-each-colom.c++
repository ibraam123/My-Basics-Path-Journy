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



int colsum(int matrix[3][3], short RowNumber, short Cols)
{
    int Sum = 0;

    for (short j = 0; j <= RowNumber -1 ; j++)
    {
         Sum += matrix[j][Cols];
    }


    return Sum;
}   




void sum_on_array(int matrix[3][3] , int sum_array[3]){



    for (int i = 0; i < 3; i++)
    {
        sum_array[i] = colsum(matrix , 3 , i );
    }
    

}

void print_array(int matrix[3][3] , int sum_array[3]){

    for (int i = 0; i <= 2; i++)
    {
        cout << "col " << i + 1  << " sum = " << sum_array[i] << endl;
    }
    

}




int main(){
    srand((unsigned)time(NULL));

    int matrix[3][3];
    int sum_array[3];
    cout << "the following 3*3 matrix : " << endl;
    readmatrix(matrix);
    printmatrix(matrix);

    sum_on_array(matrix,sum_array);


    cout << endl << "the following sum of each row : " << endl;
    print_array(matrix , sum_array);


    


    return 0;
}      
