#include<iostream>
using namespace std;


// problem one
/*void printname(string name){
    cout << "your name is: " << name << endl;
}
int main(){
    printname("ibraam");
    return 0;
}*/


// problem 

/*string readname(){
    string name;
    cout << "what is your name:  " << endl;
    getline(cin,name);
    return name;
}
void printname(string name){
    cout << "your name is: " << name << endl;
}
int main (){
    printname(readname());
}*/




// problem 
/*int ReadPositiveNumber(string Message)
  {
    int Number = 0;
   do    
   {       
             cout << Message << endl;
             cin >> Number;    
   } while (Number <= 0);
     return Number; 
  } 
  void checknumber(int Number){
    if (Number % 2 == 0)
    {
       cout << "nuumber is even";
    }
    else
    {
        cout << "number is odd";
    }
    

  }

  int main(){
    int Number = ReadPositiveNumber("enter a positive number? ");
    checknumber(Number);
  }*/




// problem 

/*struct stinfo
{
    int age;
    bool hasdriver;
};
stinfo readinfo(){
    stinfo info;

    cout << "please enter your age? " << endl;
    cin >> info.age;
    cout << "do you have driver license? " << endl;
    cin >> info.hasdriver;

    return info; 
}

bool isaccepted(stinfo info){
    return (info.age > 21 && info.hasdriver);
}

void printresult(stinfo info){
    if (isaccepted(info))
    {
        cout << "Hired";
    }
    else
    {
        cout << "rejected";
    }
    
    
}
int main(){
    printresult(readinfo());
}*/



// problem 
/*struct stinfo
{
    string fname;
    string lname;
};
stinfo readinfo(){

    stinfo info;
    cout << "please enter your first name? " << endl;
    cin >> info.fname;
    cout << "please enter your last name?  " << endl;
    cin >> info.lname;

    return info;
}
string getfullname(stinfo info){
    string fullname;

    fullname = info.fname + " " + info.lname;
    return fullname;
}
void printfullname(string fullname){
    cout << fullname;
}

int main(){
    printfullname(getfullname(readinfo()));
}*/
// problem 

/*int readnumbers(){
    int num1 , num2 , num3;
    cout << "please enter your numbers? " << endl;
    cin >> num1 >> num2 >> num3 ;
    return num1 + num2 + num3;
}
void printresult(){
    
    int result = readnumbers();
    cout << result;

}

int main(){
    printresult();
}*/


// problem 


/*int readN(){
    int N;
    cout << "enter last number? " << endl;
    cin >> N;
    return N;
}

void print_number_from_1_to_N(){
    int N = readN();
    int odd;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 != 0)
        {
            odd += i;
        }
        
        cout << i << endl;
    }
    cout << "sum of odd numbers is: " << odd;

}
int main(){
    print_number_from_1_to_N();
}*/




// problem 

/*void factrial_number(){
    int number;
    cout << "enter number you want to get factrial of it? " << endl;
    cin >> number;
    int factrial = 1;

    for (number;number > 0; number--)
    {
       // factrial *= number;
       factrial = factrial * number;
    }
    cout << "factrial is: " << factrial;
    
}
int main(){
    factrial_number();
}*/

// problem 
/*
void print_letters_from_A_to_Z(){

    for (int  i = 65; i < 91; i++)
    {
        cout << char(i) << endl;
    }
    
}
int main (){
    print_letters_from_A_to_Z();
}
*/

// problem 
#include <iostream> 
using namespace std; 
int ReadPositiveNumber(string Message) 
{ 
 int Number; 
 do 
 { 
  cout << Message << endl; 
  cin >> Number; 
 } while (Number < 0); 
 
 return Number; 
} 
 
 
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
 
void PrintArray(int arr[100], int arrLength)  
// main استدعاء  القيمة المخزنة في   arrLength 
{ 
 for (int i = 0; i < arrLength; i++) 
  cout << arr[i] << " "; 
 
 cout << "\n"; 
} 
int TimeRepeated(int Number, int arr[100], int arrLength) 
{ 
 int Count = 0; 
 for (int i = 0; i <= arrLength - 1; i++) 
 { 
  if (Number == arr[i]) 
   Count++; 
 } 
 return Count; 
} 
int main() 
{ 
 int arr[100], arrLength, NumberToCheck; 
 
 ReadArray(arr, arrLength); 
 
 NumberToCheck = ReadPositiveNumber("Enter the number you want to check : "); 
 
 cout << "\nOriginal array : "; 
 PrintArray(arr, arrLength); 
 
 cout << "\nNumber " << NumberToCheck; 
 cout << " is repeated "; 
 
 cout << TimeRepeated(NumberToCheck, arr, arrLength) << "time(s).\n"; 
} 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem 
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem
// problem 

