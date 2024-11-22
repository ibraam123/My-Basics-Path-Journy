#include<iostream>
using namespace std;


// function to print name
void printname(string name){
    cout << "your name is: " << name << endl;
}


// function to read name
string readname(){
    string name;
    cout << "what is your name:  " << endl;
    getline(cin,name);
    return name;
}

// function to read positive number
int ReadPositiveNumber(string Message)
  {
    int Number = 0;
   do    
   {       
             cout << Message << endl;
             cin >> Number;    
   } while (Number <= 0);
     return Number; 
  } 



  int RandomNumber(int From, int To)
{
 //Function to generate a random number

 int randNum = rand() % (To - From + 1) + From;
 srand((unsigned)time(NULL));
 return randNum;
}
// function to print from A to Z
void print_letters_from_A_to_Z(){

    for (int  i = 65; i < 91; i++)
    {
        cout << char(i) << endl;
    }
    
}
// function to reverse numbers
int ReverseNumber(int Number) {
  int Remainder = 0;
  int ReversedNumber = 0;  // Initialize a variable to store the reversed number

  while (Number > 0) {
    Remainder = Number % 10;  // Extract the last digit
    Number = Number / 10;    // Remove the last digit from the original number
    ReversedNumber = ReversedNumber * 10 + Remainder;  // Build the reversed number
  }
  return ReversedNumber;     // Return the reversed number
}

// function to reverse numbers
void printdigit(int number){
  int remainder = 0 ;
  while (number > 0)
  {
    remainder = number % 10;
    number = number / 10;
    cout << remainder << endl;
  }
  
}
// function to wrte pattern 
void printinvertednumber(int number){
    for (int i = number; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
        
    }
    
}

// print trible letter
void printtribleletter(){
    for (int i = 65; i < 91 ; i++)
    {
        for (int j = 65; j < 91 ; j++)
        {
            for (int k = 65; k < 91 ; k++)
            {
               cout << char(i);
               cout << char(j);
               cout << char(k);
               cout << endl;
            }
            
           
        }
        cout << endl;
        
    }
    
}

// finction to encryption 
string encrypttext(string Text, short Encryptionkey){

    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int) Text[i] + Encryptionkey);
    }

    return Text;
}

// function to number of trails 
int number_of_trails(){
    int number;
    cout << "enter number of trails? " << endl;
    cin >> number;
    return number;
}
// function to read array

void ReadArray(int arr[100], int& arrLength)   
// & main لترجع ( تخزن ) القيمة المدخلة في  
{ 
 cout << "Enter number of elements : \n"; 
 cin >> arrLength; 
 cout << "\n"; 
 
 for (int i = 0 ; i < arrLength; i++) 
 // index[0] == arr مكان تخزين أول عنصر في   
 { 
  cout << "Elements [" << i +1 << "] : ";  
// [1] == arr أول قيمة  عنصر  في    
  cin >> arr[i]; 
 } 
 cout << endl; 
} 

// function to print array

void PrintArray(int arr[100], int arrLength)  
// main استدعاء  القيمة المخزنة في   arrLength 
{ 
 for (int i = 0; i < arrLength; i++) 
  cout << arr[i] << " "; 
 
 cout << "\n"; 
} 

// function to find max number

int MaxNumberInArray(int arr[100], int arrLength) 
{ 
  
 int Max = 0; 
 for (int i = 0; i < arrLength; i++) 
 { 
  if (arr[i] > Max) 
  { 
   Max = arr[i]; 
  } 
 } 
 return Max; 
}


// function to shafle numbers

void shuffle_array(int arr[100], int arrlength) {
    // Shuffles the array elements using the swap function
    for (int i = 0; i < arrlength; ++i) {
        swap(arr[i], arr[RandomNumber(0, arrlength - 1)]); // Swap with a random element
    }
}

 // function to swap 
 void swap(int& a, int& b) {
    // Swaps the values of two integers using a temporary variable
    int temp = a;
    a = b;
    b = temp;
}

// function to check a prime number
/*enPrimNotPrime CheckPrime(int Number) 
{ 
 int M = round(Number / 2); 
 
 for (int Counter = 2; Counter <= M; Counter++) 
 { 
 
  if (Number % Counter == 0) 
   return enPrimNotPrime::NotPrime; 
 } 
 return  enPrimNotPrime::Prime; 
}*/

// function to read just negative number

int read_ngative_number(int& number){
    do
    {
       cout << "enter ngative number: " << endl;
       cin >> number;
    } while (number >= 0);
    

    return number;
}

//  function to abslute numbers

int abslute_function(int number){
    return number * (-1);
}