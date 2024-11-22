#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
 
 int RandomNumber(int From, int To)
{
 //Function to generate a random number

 int randNum = rand() % (To - From + 1) + From;
 return randNum;
}
void FillArray(int arr[100], int& arrLength) 
{  
 cout << "please enter nummber of elemnts? " << endl;
 cin >> arrLength; 
 


 arr[0] = RandomNumber(-100 , 100); 
 arr[1] = RandomNumber(-100 , 100); 
 arr[2] = RandomNumber(-100 , 100); 
 arr[3] = RandomNumber(-100 , 100); 
 arr[4] = RandomNumber(-100 , 100); 
 arr[5] = RandomNumber(-100 , 100); 
 arr[6] = RandomNumber(-100 , 100); 
 arr[7] = RandomNumber(-100 , 100); 

 
 
} 


void PrintArray(int arr[100], int arrLength)  
// main استدعاء  القيمة المخزنة في   arrLength 
{ 
 for (int i = 0; i < arrLength; i++) 
  cout << arr[i] << " "; 
 
 cout << "\n"; 
} 



int checkpositivenumbersarray(int arr[100] , int arrLength){


    int positive = 0;

    for (int i = 0; i < arrLength; i++)
    {
       if (arr[i] > 0)
       {
        positive++;
       }
       
    }

    return positive;

}


int main(){
     srand((unsigned)time(NULL));


    int arr[100] ;
    int arrLength;

    FillArray(arr , arrLength);

    cout << "elements of array is : " << endl;
    PrintArray(arr , arrLength);

    cout << "positive numbers count is: " << checkpositivenumbersarray(arr , arrLength);


}