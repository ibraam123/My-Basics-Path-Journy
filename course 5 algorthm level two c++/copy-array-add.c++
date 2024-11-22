#include <iostream>
#include <cstdlib>
using namespace std;
int addarrayelement(int arr[100] , int &arrLength){
    int number;
    cout << "enter number ? " << endl;
    cin >> number;
    return number;
}

void ReadArray(int arr[100], int& arrLength)   
// & main لترجع ( تخزن ) القيمة المدخلة في  
{ 
 cout << "Enter number of elements : \n"; 
 cin >> arrLength; 
 cout << "\n"; 
 
 for (int i = 0 ; i < arrLength; i++) {
 arr[i] = addarrayelement(arr , arrLength);
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
void copy_array(int arr[100],int arrLength){
     int copyarr[100];
    for (int i = 0; i < arrLength; i++)
    {
         copyarr[i] = arr[i];
    }

    for (int i = 0; i < arrLength; i++)
    {
        if (copyarr[i] % 2 != 0){
      cout << copyarr[i] << " ";
    }

    }
    cout << endl;
    
    
   
}

int main (){
     srand((unsigned)time(NULL));

    int arr[100] , arrLength;

    ReadArray(arr , arrLength);

    cout << "\n elements of array 1 : " ;
    PrintArray(arr , arrLength);

    cout << "\n elements of array 2 after copy: " ;
    copy_array(arr , arrLength);

}

