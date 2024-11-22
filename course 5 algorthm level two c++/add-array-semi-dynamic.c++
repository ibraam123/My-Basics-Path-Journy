#include<iostream>
using namespace std;

void ReadArray(int arr[100] , int& count)   
{ 

 bool yes_or_no = true ;
count = 0;
while(yes_or_no != 0){
    
  cout << "please enter your number?  ";  
  cin >> arr[count]; 
  cout << "Do you want add more elements? [0]:No  [1]:Yes? "  ;
  cin >> yes_or_no;

  count++;


 cout << endl; 

 }

} 


void PrintArray(int arr[100] , int count)  
{ 
 for (int i = 0; i < count; i++) 
  cout << arr[i] << " "; 
 
 cout << "\n"; 
} 

int main(){
    int arr[100]; 
    int count;
    ReadArray(arr , count);


    cout << "Array of elements:  " ;
    PrintArray(arr , count);
    cout << count;

    return 0;
}
