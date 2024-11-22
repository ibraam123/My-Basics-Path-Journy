#include <iostream>
#include "mylibs.h"
using namespace std;




void readmatrix(int matrix[3][3])
{

    int array[10] = {1,2,3,4,5,6,7,8,9};
    int counter = 0;

    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = array[counter] ;
                counter ++;
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
int main(){
    srand((unsigned)time(NULL));

    int matrix[3][3];
    cout << "the following 3*3 matrix : " << endl;
    readmatrix(matrix);
    printmatrix(matrix);




}      
