#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
 //Function to generate a random number

 int randNum = rand() % (To - From + 1) + From;
 return randNum;
}
void ReadArray(int arr[100], int& arrLength)   
// & main لترجع ( تخزن ) القيمة المدخلة في  
{ 
 cout << "Enter number of elements : \n"; 
 cin >> arrLength; 
 cout << "\n"; 
 
 for (int i = 0 ; i < arrLength; i++) {
 arr[i] = RandomNumber(1 , 100);  
 }

}
void PrintArray(int arr[100], int arrLength)  
// main استدعاء  القيمة المخزنة في   arrLength 
{ 
 for (int i = 0; i < arrLength; i++) {
  cout << arr[i] << " "; 
 }
 cout << "\n"; 
} 
void second_array( int copyarr[100] , int arr[100],int arrLength){
    
    for (int i = 0; i < arrLength; i++)
    {
         copyarr[i] = RandomNumber(1 , 100);
    }

    for (int i = 0; i < arrLength; i++)
    {
      cout << copyarr[i] << " ";

    }
    cout << endl;
    
    
   
}

void sum_of_two_array( int copyarr[100] , int arr[100] ,int arrLength){


    int sum_array[100];

    for (int i = 0; i < arrLength; i++)
    {
        sum_array[i] = copyarr[i] + arr[i];
    }

    for (int i = 0; i < arrLength; i++)
    {
        cout << sum_array[i] << " ";
    }

    cout << endl;
    
    


}

int main (){
    srand((unsigned)time(NULL));

    int arr[100] , arrLength;
    int copyarr[100];

    ReadArray(arr , arrLength);

    cout << "\n elements of array 1 : \n" ;
    PrintArray(arr , arrLength);

    cout << "\n elements of array 2 after copy: \n " ;
    second_array(copyarr , arr , arrLength);

    cout << "\nSum of array 1 and array 2  elements : \n";
    sum_of_two_array(copyarr , arr , arrLength);


}

