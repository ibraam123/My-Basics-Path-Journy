#include <iostream> 
 
using namespace std; 
 
void FillArray(int arr[100], int& arrLength) 
{  
 cout << "please enter nummber of elemnts? " << endl;
 cin >> arrLength; 
 


 arr[0] = 10; 
 arr[1] = 20; 
 arr[2] = 30; 
 arr[3] = 40; 
 arr[4] = 50; 
 arr[5] = 60; 
 arr[6] = 70; 
 arr[7] = 80; 
 arr[8] = 70; 
 arr[9] = 60; 
 arr[10] = 50; 
 arr[11] = 40; 
 arr[12] = 30; 
 arr[13] = 20; 
 arr[14] = 10; 

 
 
} 

void checkarray(int arr[100] , int arrLength){

    int checknumber = 0;
    int j = (arrLength - 1);


    for (int i = 0; i < arrLength; i++)
    {
        
        
            if (arr[i] == arr[j])
            {
                checknumber++;
            }

            j --;

            /**
             * 0 and 6 = same
             * 1 and 5 = same 
             * 2 and 4 = same
             * 3 and 3 = same
             * 4 and 2 = same
             * 5 and 1 = same
             * 6 and 0 = same
             *  i and j 
             * increase and decrease in same time 
             */
            
    
        
    }

    if (checknumber == arrLength)
    {
        cout << "\nyes array is plaindrome" ;
    }
    else
    {
        cout << "\nno array is not plaindrome " ;
    }
    
    
    

}
/**if first array equal last array 
 * till go to center of array 
 * if all condions is true then print is plaindrome nummber
 */


int main(){

    int arr[100] ;
    int arrLength;


    FillArray(arr,arrLength)    ;
    cout << "elements of array: " << endl;

    for (int i = 0; i < arrLength; i++)
    {
        cout <<  arr[i] << " " ;
    }


    checkarray(arr , arrLength);
    

}