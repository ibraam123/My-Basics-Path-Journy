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

void intersiction(int matrix_one[3][3] , int matrix_two[3][3])
{

    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
            {
                if (matrix_one[i][j] == matrix_two[i][j])
                {
                    cout << matrix_one[i][j] << "\t";
                }
                
            }
        
        
    }


}


int main(){

    srand((unsigned)time(NULL));

    int matrix_one[3][3] = {{10,55,70} , {23,48,98} , {1,2,3}},  matrix_two[3][3] = {
         {10 ,49 ,22} , {23,1,7} , {56,70,3} } ;



    cout << "matrix 1 : " << endl;
    printmatrix(matrix_one);

    cout << "matrix 2 : " << endl;
    printmatrix(matrix_two);


    cout << "intersected numbers are : " << endl;
    intersiction(matrix_one , matrix_two) ;


    return 0;

} 




