#include <iostream>

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
 for (int i = 0; i < arrLength; i++) 
  cout << arr[i] << " "; 
 
 cout << "\n"; 
} 


int print_sum(int arr[100], int arrLength){

    int sum = 0 ;

    for (int i = 0; i < arrLength; i++)
    {
        sum += arr[i];
    }
    
   
    return sum / arrLength;


}

int main(){
    srand((unsigned)time(NULL));

    int arr[100] , arrLength;

    ReadArray(arr , arrLength);
    cout << "elements of array: " << endl;
    PrintArray(arr , arrLength);

    cout << "sum of all elements : " << print_sum( arr , arrLength) ;
}