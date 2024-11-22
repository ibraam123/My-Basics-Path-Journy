#include <iostream> 
 
using namespace std; 
 
void FillArray(int arr[100], int& arrLength) 
{  
 arrLength = 10; 
 
 arr[0] = 10; 
 arr[1] = 10; 
 arr[2] = 10; 
 arr[3] = 50; 
 arr[4] = 50; 
 arr[5] = 70; 
 arr[6] = 70; 
 arr[7] = 70; 
 arr[8] = 70; 
 arr[9] = 90; 
 
} 
 
void PrintArray(int arr[100], int arrLength) 
{ 
 for (int i = 0; i < arrLength; i++) 
  cout << arr[i] << " "; 
 
 cout << "\n"; 
} 
 
short FindNumberPositionInArray(int Number, int arr[100], int arrLength) 
{ 
 // هذا الفانكشن يبحث عن الرقم في المصفوفة ويعيد الإنديكس إذا وجد  الرقم   
 // وإذا لم يجد الرقم يعيد 1 - أي لم يتم العثور على الرقم   
 
 for (int i = 0; i < arrLength; i++) 
 { 
  if (arr[i] == Number) 
   return i; 
 } 
 return -1; 
} 
 
bool IsNumberInArray(int Number, int arr[100], int arrLength) 
{ 
 return FindNumberPositionInArray(Number, arr, arrLength) != -1; 
} 
 
void AddArrayElement(int Number, int arr[100], int& arrLength) 
{ //its a new element so we need to add the length by 1 
 arrLength++; 
 arr[arrLength - 1] = Number; 
} 
 
void CopyDistinactNumbersToArray(int arrSource[100], int 
arrDestination[100], int arrLength, int& arrDestinationLength) 
{ 
 for (int i = 0; i < arrLength; i++) 
 { 
  if(! IsNumberInArray(arrSource[i],arrDestination,arrLength )) 
  { 
   AddArrayElement(arrSource[i], arrDestination, 
arrDestinationLength); 
  } 
 } 
} 
 
int main() 
{ 
 
 int arrSource[100], SourceLength = 0, arrDestination[100], 
DestinationLength = 0; 
 
 FillArray(arrSource,  SourceLength); 
 
 cout << "\nArray 1 Elements : \n"; 
 PrintArray(arrSource, SourceLength); 
 
 CopyDistinactNumbersToArray(arrSource, arrDestination, SourceLength, 
DestinationLength); 
 
 cout << "\nArray 1 distivct Elements : \n"; 
 PrintArray(arrDestination, DestinationLength); 
 
}