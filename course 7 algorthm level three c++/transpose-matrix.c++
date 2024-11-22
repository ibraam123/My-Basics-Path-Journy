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

void transpose(int matrix[3][3])
{

    /** [0][0]1  [0][1]  2  [0][2]  3
     *  [1][0]4  [1][1] 5   [1][2]  6
     *  [2][0]7  [2][1] 8   [2][2] 9
     * 
     * 00 1  10 4  20 7
     * 01 2  11 5  21 8
     * 02 3  12 6  22 9
     * 
     * 
     */
    int transpose[3][3];

    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
            {
               transpose[i][j] = matrix[j][i] ;
               cout << transpose[i][j] << "\t"; 
                
            }
            cout << endl;
        
        
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
    

    cout << "\n\nthe following transpose 3*3 matrix : " << endl;
    transpose(matrix);





}      
