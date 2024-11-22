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

int max_number(int matrix[3][3]){
    int max = 0;
    
    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
            {
              if (matrix[i][j] > max)
              {
                max = matrix[i][j];
              }
              
            }
    }
    return max;

}

int min_number(int matrix[3][3]){
    int min = max_number(matrix);
    
    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
            {
              if (matrix[i][j] < min)
              {
                min = matrix[i][j];
              }
            }
    }

    return min;

}

int main(){
    int matrix[3][3] = {{10 ,49 ,22} , {23,1,7} , {56,70,3}};

    cout << "matrix : " << endl;
    printmatrix(matrix);

    cout << "max : " << max_number(matrix) << endl;
    cout << "min : " << min_number(matrix) << endl;

    return 0;


}