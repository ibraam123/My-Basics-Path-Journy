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

bool identity(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
            {
                if (((matrix[0][0]) && (matrix[1][1]) && (matrix[2][2]) == 1))
                {
                    return true;
                }
                
                
            }
        
        
    }

    return false;

}


int main(){


    srand((unsigned)time(NULL));

    int matrix[3][3] = {
        {1,0,0}, {0,1,0}, {0,0,1}
    };
    cout << "the following 3*3 matrix : " << endl;
    printmatrix(matrix);

    if (identity(matrix))
    {
        cout << "is idintity " << endl;
    }
    else
    {
        cout << "not idintity " << endl;
    }
    
    return 0;

}   