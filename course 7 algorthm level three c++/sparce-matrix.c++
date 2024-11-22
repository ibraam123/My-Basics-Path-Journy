#include <iostream>
#include "mylibs.h"
using namespace std;


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

bool sparce(int matrix[3][3])
{
    int zero_count = 0;
    int not_zero_count = 0; 
    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
            {
                   if (matrix[i][j] == 0)
                   {
                    zero_count ++;
                   }
                   else
                   {
                    not_zero_count ++;
                   }
                   
                   
            }
        
        
    }

    return (zero_count > not_zero_count);

}


int main(){

    int matrix[3][3] = {
        {1,0,0}, {0,1,0}, {0,0,1}
    };
    int matrix2[3][3] = {{1,2,0},{1,0,2},{0,2,3}};


    cout << "the following 3*3 matrix : " << endl;
    printmatrix(matrix2);

    if (sparce(matrix2))
    {
        cout << "is sparce " << endl;
    }
    else
    {
        cout << "not sparce " << endl;
    }
    
    return 0;

}   