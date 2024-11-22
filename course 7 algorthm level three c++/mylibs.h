#pragma once


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;



namespace mylib
{
    void test()
    {
        cout << "Hi, this is my first function in my first library!" << endl;
    }


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

    int printpownumbers(int N , int M)
    {

    if (M == 0)
    {
        return 1;
    }
    else
    {
        return (N * printpownumbers(N , M - 1));
    }
    
    

    }


    int factroial(int number)
    {
    if (number == 1)
    {
        return 1;
    }
    else
    {
        return ( number * factroial(number - 1));
    }
    
    
    }

    string reverseString (string str )
    {
      for (int i = str.length(); i >= 0 ; i--)
      {
        cout << str[i];
      }
    
        
      return "done"  ;
    }


    void PrintFileContenet(string FileName , vector <string>& vfilename)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::in ); // Read Mode
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                vfilename.push_back(Line);
            }


            MyFile.close();
        }


    }

    void readmatrix(int matrix[3][3])
    {
       for (int i = 0; i < 3; i++)
       {
           for (int j = 0; j < 3; j++)
           {
               matrix[i][j] = mylib::RandomNumber(1 , 100);
           }
           
       }

    
    }
    void printmatrix(int matrix[3][3])
    {
    
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
               cout << matrix[i][j] << "\t\t";
            }
            cout << endl;

        }

    }
    int RowSum(int matrix[3][3], short RowNumber, short Cols)
    {
        int Sum = 0;
    
        for (short j = 0; j <= Cols -1 ; j++)
        {
             Sum += matrix[RowNumber][j];
        }
    
    
        return Sum;
    } 

    bool sparce(int matrix[3][3])
    {
        int zero_count = 0;
        int not_zero_count = 0; 
        for (int i = 0; i < 3; i++)
        {
                for (int j = 0; j < 3; j++)
                {
                       if (matrix[i][j] == 0)
                       {
                        zero_count ++;
                       }
                       else
                       {
                        not_zero_count ++;
                       }
                }
        }
        return (zero_count > not_zero_count);

    }

    void intersiction(int matrix_one[3][3] , int matrix_two[3][3])
    {
        for (int i = 0; i < 3; i++)
        {
                for (int j = 0; j < 3; j++)
                {
                    if (matrix_one[i][j] == matrix_two[i][j])
                    {
                        cout << matrix_one[i][j] << "\t";
                    }
                }
        }

    }


    void printfirstlitter( string sentence )
    {


        cout << sentence << endl;
        cout << "first litters of this string is : " << endl;

        for (int i = 0; i < sentence.length(); i++)
        {
            if (i == 0)
            {
                cout << sentence[i] << endl;
            }
            else if (sentence[i] == ' ')
            {
                cout << sentence[i+1] << endl;
            }

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

    string ReadString()
    {
        string S1 = " ";
        cout << "Pleas Enter your string ? \n";
        getline(cin, S1);
        return S1;
    }


    string UpeerFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (int i = 0; i < S1.length(); i++)
        {
         if (S1[i] != ' ' && isFirstLetter)
         {
            S1[i] = toupper(S1[i]);
         }


          isFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }

    string UpperAllString(string S3)
    {
        for (int i = 0; i < S3.length(); i++)
        {
         S3[i] = toupper(S3[i]);
        }
        return S3;
    }


    string LowerAllString(string S3)
    {
        for (int i = 0; i < S3.length(); i++)
        {
            S3[i] = tolower(S3[i]);
        }
        return S3;
    }

    char read_char(){
        char letter;
        cout << "\nplease enter a charcter? " << endl;
        cin >> letter;
        return letter;
    }
    
    
    char inverting_char(char letter){
    
        if (letter == toupper(letter))
        {
            return tolower(letter);
        }
        else
        {
            return toupper(letter);
        }
        
    }

    void countsmallandupperletter(string str)
    {
    	int Sletter=0,UPletter=0;
    	for (int i = 0; i < str.length(); i++)
    	{   if (isupper(str[i]))
    		UPletter++ ;
    	  if (islower(str[i]))
    		 Sletter++ ;
    	}
    	cout << "string length :" << str.length() << "\n";
    	cout << "the upper case count is : " << UPletter << "\n";
    	cout << "the lower case count is : " << Sletter << "\n";
    }

    void split(string S1, vector<string> &vword)
    {
        string word = "";
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ') // If the current character is not a space
            {
                word += S1[i]; // Add the character to the current word
            }
            else if (!word.empty())
            {
                vword.push_back(word); // Push the completed word into the vector
                word = ""; // Reset the word for the next word
            }
        }
        // Add the last word (if any) to the vector
        if (!word.empty())
        {
            vword.push_back(word);
        }
    
        // Print the words in the vector
        for (int i = 0; i < vword.size(); i++)
        {
            cout << vword[i] << endl;
        }
    }

    string replace(string S12, string StringToReplace, string sRepalceTo){

         int pos = S12.find(StringToReplace);
         while(pos != string::npos)
         {
             S12.erase(pos , StringToReplace.length());
             S12.insert(pos , sRepalceTo);
             pos = S12.find(StringToReplace);
         }

         return S12;
    

    }

   /* void rclient(vector<string> &clients) {  // Pass by reference
        // clientdata client;

        cout << "enter client data? " << endl;

        cout << "Please enter account number: " << endl;
        getline(cin >> ws, client.accountn);  // Read input
        clients.push_back(client.accountn);   // Add to clients vector

        cout << "Please enter pincode: " << endl;
        getline(cin, client.pincode);
        clients.push_back(client.pincode);

        cout << "Please enter name: " << endl;
        getline(cin, client.name);
        clients.push_back(client.name);

        cout << "Please enter phone number: " << endl;
        getline(cin, client.phone);
        clients.push_back(client.phone);

        cout << "Please enter balance: " << endl;
        getline(cin, client.balance);
        clients.push_back(client.balance);
    }*/

       void checksentence(string S1)
       {
          int smallcount = 0;
          int capitalletter = 0;
     
     
          for (int i = 0; i < S1.length(); i++)
          {
              if (isupper(S1[i]))
              {
                  capitalletter ++;
              }
              else if (islower(S1[i]))
              {
                  smallcount ++;
              }
     
          }
     
          cout << "capital letters = " << capitalletter << endl;
          cout << "small letters = " << smallcount << endl;

       }

        void readvector(vector <int> &series , int count){
        
            series.push_back(1);
            series.push_back(1);
            for (int i = 2; i < count; i++)
            {
                series[i] = series[i - 1] + series[i - 2];
            }

            /** 1 1 2 3 5 8 13 21 34 55 */
        }

        bool identity(int matrix[3][3])
        {
            for (int i = 0; i < 3; i++)
            {
                    for (int j = 0; j < 3; j++)
                    {
                        if (((matrix[0][0]) && (matrix[1][1]) && (matrix[2][2]) == 1))
                        {
                            return true;
                        }


                    }


            }

            return false;

        }

        void middlerow(int matrix[3][3] , int row)
        {
            for (int i = 0; i < 3; i++)
            {
                cout << matrix[row][i] << "\t";
            }
            cout << endl;

        }

        void middlecol(int matrix[3][3] , int col)
        {
            for (int i = 0; i < 3; i++)
            {
                cout << matrix[i][col] << "\t";
            }
            cout << endl;

        }

        /*void convert_to_string(int matrix[3][3])
        {
        
          converter tostring;

        for (int i = 0; i < 3; i++)
        {
            tostring.row_one += to_string (matrix[0][i]);
            tostring.row_two += to_string (matrix[1][i]);
            tostring.row_three += to_string (matrix[2][i]);
        }

         int rowone = stoi (tostring.row_one);
         int rowtwo = stoi (tostring.row_two);
         int rowthree = stoi (tostring.row_three);

         if ((rowone == ReverseNumber(rowone)) && (rowtwo == ReverseNumber(rowtwo)) && (rowthree == ReverseNumber(rowthree)))
         {
            cout << "it is a plaindrome number." << endl;
         }
         else
         {
            cout << "it is not a plaindrome number." << endl;
         }

        }
  */

        string ReplaceWordInStringUsingBuiltInFunction(string S12, string StringToReplace, string sRepalceTo)
        {
            // البحث عن الكلمة المراد تبديلها
            short pos = S12.find(StringToReplace);
            // هل الكلمة موجودة ل تساوي فراغ
            while (pos != std::string::npos)
            {
            // بدل الكلمة من طول مثلا 12 , + طول
            S12 = S12.replace(pos, StringToReplace.length(), sRepalceTo);
            // البحث عن الكلمة المراد تبديلها
            pos = S12.find(StringToReplace); //find next
            }
            return S12;
        }

 // project bank

const string filename = "train.txt";
const string separator = "//##//";

// Enum to define menu options
enum options_choose {
    show_client = 1,
    add_new_client = 2,
    delete_client = 3,
    update_client = 4,
    find_client = 5,
    transction_menue = 6, 
    exit_program = 7
};

enum transction
{
    edoposit = 1 , 
    ewithdraw = 2 ,
    etotal_balance = 3,
    emain_menue = 4
};

// Structure to hold client data
struct sCleintdata {
    string accountNumber;
    string pincode;
    string name;
    string phoneNumber;
    string balance;
};

// Function to display the main menu
void main_menu() {
    cout << "===========================================" << endl;
    cout << "\t\tMain Menu Screen" << endl;
    cout << "===========================================" << endl;
    cout << "[1] Show Client list." << endl;
    cout << "[2] Add new Client." << endl;
    cout << "[3] Delete Client." << endl;
    cout << "[4] Update Client." << endl;
    cout << "[5] Find Client." << endl;
    cout << "[6] transction menue." << endl;
    cout << "[7] Exit." << endl;
    cout << "===========================================" << endl;
}


void main_menu_transction() {
    cout << "===========================================" << endl;
    cout << "\t\ttransction menue" << endl;
    cout << "===========================================" << endl;
    cout << "[1] deposite." << endl;
    cout << "[2] withdraw." << endl;
    cout << "[3] total balance." << endl;
    cout << "[4] main menue." << endl;
    cout << "===========================================" << endl;
}


// Function to read a client's data and push it into a vector
void vCleintread(vector<string>& vcleint) {
    sCleintdata info;

    cout << "Enter Account Number: ";
    getline(cin >> ws, info.accountNumber);
    vcleint.push_back(info.accountNumber);

    cout << "Enter Pincode: ";
    getline(cin, info.pincode);
    vcleint.push_back(info.pincode);

    cout << "Enter Name: ";
    getline(cin, info.name);
    vcleint.push_back(info.name);

    cout << "Enter Phone Number: ";
    getline(cin, info.phoneNumber);
    vcleint.push_back(info.phoneNumber);

    cout << "Enter Balance: ";
    getline(cin, info.balance);
    vcleint.push_back(info.balance);
}

// Function to read the client list from the file at the beginning of the program
void loadClientsFromFile(vector<string>& lines, vector<string>& AN) {
    fstream MyFile;
    MyFile.open(filename, ios::in); // Open file in read mode

    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {
            lines.push_back(Line);
            AN.push_back(Line.substr(0, Line.find(separator))); // Extract account number
        }
        MyFile.close();
    } else {
        cout << "Error loading client data!" << endl;
    }
}

// Function to write a new client to the file
void writefile(vector<string>& vcleint, vector<string>& lines, vector<string>& AN ,vector<string>& balance) {
    fstream myfile;
    myfile.open(filename, ios::out | ios::app); // Open file in append mode

    if (!myfile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    char check = 'y';
    string all_line;

    while (check == 'y' || check == 'Y') {
        vCleintread(vcleint);
        AN.push_back(vcleint[0]); // Add the account number to the vector
        balance.push_back(vcleint[4]); // add the balance number to vector

        // Build the line to write to the file
        for (int i = 0; i < vcleint.size(); i++) {
            all_line += vcleint[i] + separator;
        }
        lines.push_back(all_line); // Store the entire line in the vector
        myfile << all_line << endl; // Write to file
        all_line.clear();
        vcleint.clear(); // Clear the vector for the next client

        // Ask if the user wants to add more clients
        cout << "Client Added Successfully. Do you want to add more clients (y/n)? ";
        cin >> check;
        cin.ignore();
    }


    myfile.close(); // Close the file
}

// Function to show the list of clients from the file
void show_clients_list(vector<string>& lines) {
    for (const string& line : lines) {
        cout << line << endl;
    }
}

// Function to delete a client based on the account number
void delete_marked_line(vector<string>& lines, vector<string>& AN) {
    string account;
    char check = 'y';
    fstream MyFile;
    MyFile.open(filename, ios::out); // Open file in write mode

    cout << "Please enter the account number of the record you want to delete: ";
    cin >> account;

    for (int i = 0; i < AN.size(); i++) {
        if (account == AN[i]) {
            cout << "The following data will be deleted: " << endl;
            cout << lines[i] << endl;
            cout << "Are you sure you want to delete this record? (y/n): ";
            cin >> check;

            if (check == 'y' || check == 'Y') {
                lines.erase(lines.begin() + i);
                AN.erase(AN.begin() + i);
                cout << "Record deleted successfully!" << endl;
            }
            break;
        }
    }

    // Rewrite the remaining data to the file
    for (const string& line : lines) {
        MyFile << line << endl;
    }
    MyFile.close();
}

// Function to update a client's information
void update_client_function(vector<string>& lines, vector<string>& AN) {
    string account, newline;
    vector<string> client;
    char check = 'n';

    cout << "Please enter the account number of the record you want to update: ";
    cin >> account;

    for (int i = 0; i < AN.size(); i++) {
        if (account == AN[i]) {
            cout << "The following data will be updated: " << endl;
            cout << lines[i] << endl;
            cout << "Are you sure you want to update this record? (y/n): ";
            cin >> check;

            if (check == 'y' || check == 'Y') {
                vCleintread(client); // Read the updated information
                for (int j = 0; j < client.size(); j++) {
                    newline += client[j] + separator;
                }
                lines[i] = newline;
                cout << "Client updated successfully!" << endl;
            }
            break;
        }
    }

    // Write the updated data back to the file
    fstream MyFile;
    MyFile.open(filename, ios::out); // Open file in write mode
    for (const string& line : lines) {
        MyFile << line << endl;
    }
    MyFile.close();
}

// Function to find a client by account number
void find_client_function(vector<string>& lines, vector<string>& AN) {
    string account;

    cout << "Please enter the account number of the client you want to find: ";
    cin >> account;

    for (int i = 0; i < AN.size(); i++) {
        if (account == AN[i]) {
            cout << "Client data found: " << endl;
            cout << lines[i] << endl;
            
        }
    }


}


void deposite(vector<string>& lines, vector<string>& AN, vector<string>& balance) {
    string account;
    int deposit_amount;
    int current_balance;
    string line;
    int count = 0;

    cout << "===========================================" << endl;
    cout << "\t\tDeposit Screen" << endl;
    cout << "===========================================" << endl;

    cout << "Please enter the account number of the client you want to deposit to: ";
    cin >> account;

    // Find the client by account number
    for (int i = 0; i < AN.size(); i++) {
        if (account == AN[i]) {
            cout << "Client data details: " << endl;
            cout << lines[i] << endl;
            line = lines[i]; // Get the client data line

            cout << "Please enter deposit amount: ";
            cin >> deposit_amount;

            // Look for the 8th '#' separator to find the balance
            for (int x = 0; x < line.length(); x++) {
                if (line[x] == '#') {
                    count++;
                    if (count == 8) { // Assuming the balance is after the 8th '#'
                        // Convert current balance to integer, update with deposit, and update line
                        current_balance = deposit_amount + stod(balance[i]);
                        balance[i] = to_string(current_balance); // Update balance vector

                        // Replace the balance in the line
                        size_t start_pos = x + 3; // Move position to where balance starts
                        size_t balance_length = balance[i].length();
                        line.replace(start_pos, balance_length, to_string(current_balance));

                        // Update the line in the lines vector
                        lines[i] = line;
                        break;
                    }
                }
            }
        }
    }

    // Display updated client data (for debugging purposes)
    for (int i = 0; i < lines.size(); i++) {
        cout << "Line " << i << ": " << lines[i] << endl;
    }

    // Save updated data back to the file
    fstream MyFile;
    MyFile.open(filename, ios::out); // Open file in write mode to overwrite with new data

    if (!MyFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    // Write updated client data to the file
    for (const string& line : lines) {
        MyFile << line << endl;
    }

    MyFile.close(); // Close the file
    cout << "Deposit completed and data saved successfully!" << endl;
}


void withdraw(vector<string>& lines, vector<string>& AN, vector<string>& balance) {
    string account;
    int draw_amount;
    int current_balance;
    string line;
    int count = 0;

    cout << "===========================================" << endl;
    cout << "\twithdraw Screen" << endl;
    cout << "===========================================" << endl;

    cout << "Please enter the account number of the client you want to withdraw to: ";
    cin >> account;

    // Find the client by account number
    for (int i = 0; i < AN.size(); i++) {
        if (account == AN[i]) {
            cout << "Client data details: " << endl;
            cout << lines[i] << endl;
            line = lines[i]; // Get the client data line

            cout << "Please enter deposit amount: ";
            cin >> draw_amount;

            // Look for the 8th '#' separator to find the balance
            for (int x = 0; x < line.length(); x++) {
                if (line[x] == '#') {
                    count++;
                    if (count == 8) { // Assuming the balance is after the 8th '#'
                        // Convert current balance to integer, update with deposit, and update line
                        current_balance = stod(balance[i]) - draw_amount;
                        balance[i] = to_string(current_balance); // Update balance vector

                        // Replace the balance in the line
                        size_t start_pos = x + 3; // Move position to where balance starts
                        size_t balance_length = balance[i].length();
                        line.replace(start_pos, balance_length, to_string(current_balance));

                        // Update the line in the lines vector
                        lines[i] = line;
                        break;
                    }
                }
            }
        }
    }

    // Display updated client data (for debugging purposes)
    for (int i = 0; i < lines.size(); i++) {
        cout << "Line " << i << ": " << lines[i] << endl;
    }

    // Save updated data back to the file
    fstream MyFile;
    MyFile.open(filename, ios::out); // Open file in write mode to overwrite with new data

    if (!MyFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    // Write updated client data to the file
    for (const string& line : lines) {
        MyFile << line << endl;
    }

    MyFile.close(); // Close the file
    cout << "withdraw completed and data saved successfully!" << endl;
}

double totbalance(vector<string>& balance)
{
    double total = 0;

    for (int i = 0; i < balance.size(); i++)
    {
        total = total + stod(balance[i]);
    }

    return total;
    

}


void transaction(vector<string>& lines, vector<string>& AN, vector<string>& balance) {
    int choice;
    while (true) {
        main_menu_transction();
        cout << "Choose what you want to do (1-4): ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character in input

        switch (choice) {
            case edoposit:
                system("cls");
                deposite(lines, AN, balance);
                break;
            case ewithdraw:
                system("cls");
                withdraw(lines, AN, balance);
                break;
            case etotal_balance:
                system("cls");
                show_clients_list(lines);
                cout << "\n\n totala balance = " << totbalance(balance);
                break;
            case emain_menue:
                return; // Go back to the main menu
            default:
                cout << "Invalid option. Please choose again." << endl;
                break;
        }
    }
}


int main() {
    vector<string> client;
    vector<string> AN;
    vector<string> lines;
    vector<string> balace;

    // Load the existing clients from the file
    loadClientsFromFile(lines, AN);
    int choice;
    while (true) {
        main_menu();
        cout << "Choose what you want to do (1-7): ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character in input

        switch (choice) {
            case show_client:
                system("cls");
                show_clients_list(lines);
                break;
            case add_new_client:
                system("cls");
                writefile(client, lines, AN ,balace);
                break;
            case delete_client:
                system("cls");
                delete_marked_line(lines, AN);
                break;
            case update_client:
                system("cls");
                update_client_function(lines, AN);
                break;
            case find_client:
                system("cls");
                find_client_function(lines, AN);
                break;
            case transction_menue:
                system("cls");
                transaction(lines,AN,balace);
                break;    
            case exit_program:
                system("cls");
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid option. Please choose again." << endl;
                break;
        }
    }



    system("pause>0");
}


bool isValidWalk(std::vector<char> walk) {
    int count = 0;
    std::vector<std::string> direction;

    int left = 0, right = 0, up = 0, down = 0;

    // Process each step in the walk
    for (int i = 0; i < walk.size(); i++) {
        if (walk[i] == 'n') {
            direction.push_back("up");
        } else if (walk[i] == 's') {
            direction.push_back("down");
        } else if (walk[i] == 'e') {
            direction.push_back("right");
        } else if (walk[i] == 'w') {
            direction.push_back("left");
        }
        count++;
    }

    // Count occurrences of each direction
    for (int i = 0; i < direction.size(); i++) {
        if (direction[i] == "up") {
            up++;
        } else if (direction[i] == "down") {
            down++;
        } else if (direction[i] == "left") {
            left++;
        } else if (direction[i] == "right") {
            right++;
        }
    }

    // Check if the walk is valid (10 steps and balanced directions)
    if (count == 10 && (up == down) && (left == right)) {
        return true;
    }

    return false;
}

}
