#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString{
private:
    string _value;
public: 
    clsString(){
        _value = " ";
    }
    clsString(string value){
        _value = value;
    }

    void setstring(string value){
        _value = value;
    }
    string getstring(){
        return _value;
    }

    // without using object
    static int printnumberofword(string S1)
    {
        int countword = 0;
        bool inWord = false;

        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ') // If the current character is not a space
            {
                if (!inWord)
                {
                    countword++; // Start of a new word
                    inWord = true; // We are inside a word now
                }
            }
            else
            {
                inWord = false; // We are between words (or at the start)
            }
        }

        return countword;
    }

    int printnumberofword(){
        return printnumberofword(_value);
    }

    static int Count_Capitallitters(string S1){
        int count = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
            {
                count++;
            }
            
        }
        return count;
        
    }
    int Count_Capitallitters(){
        return Count_Capitallitters(_value);
    }


    static int Countletters(string S1){
        int count = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                count++;
            }     

        }
        return count;
        
    }
    int Countletters(){
        return Countletters(_value);
    }

    static int Count_Smaalletters(string S1){
        int count = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
            {
                count++;
            }
            
        }
        return count;
        
    }
    int Count_Smaalletters(){
        return Count_Smaalletters(_value);
    }

    static int CountSpesaficletter( string S1 , char letter){

        int count = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] == letter)
            {
                count++;
            }
            
        }
        return count;
        
    }
    int CountSpesaficletter(char letter){
        return CountSpesaficletter(_value , letter);
    }


    static int CountVowels( string S1 ){

        int count = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] == 'a' || S1[i] == 'e' || S1[i] == 'i' || S1[i] == 'o' || S1[i] == 'u')
            {
                count++;
            }

        }
        return count;
        
    }
    int CountVowels(){
        return CountVowels(_value);
    }

    static string InvertALLlettercase( string S1 ){
        for (int i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
            {
               S1[i] = tolower(S1[i]);
            }
            else
            {
               S1[i] = toupper(S1[i]);
            }
            
        }
        return S1;
        
    }
    string InvertALLlettercase(){
        return InvertALLlettercase(_value);
    }

    static string invert_lettercase( string S1 , char letter){

        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] == letter)
            {
                if (isupper(S1[i]))
                {
                   S1[i] = tolower(S1[i]);
                }
                else
                {
                    S1[i] = toupper(S1[i]);
                }
                
            }
            
        }

        return S1;
        
    }
    string invert_lettercase(char letter){
        return invert_lettercase(_value , letter);
    }

    string Joinstring(vector <string>& words){
        string empty = "";
        for (int i = 0; i < words.size(); i++)
        {
            empty += words[i] + " " ;
        }
        return empty;
    }

    static short Length(string S1)
    {
        return S1.length();
    };

    short Length()
    {
        return _value.length();
    };

    static string Lowerallstring( string S1 ){
        for (int i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
            {
               S1[i] = tolower(S1[i]);
            }

        }
        return S1;
        
    }
    string Lowerallstring(){
        return Lowerallstring(_value);
    }

    static string Upperallstring( string S1 ){
        for (int i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
            {
               S1[i] = toupper(S1[i]);
            }
            
        }
        return S1;
        
    }
    string Upperallstring(){
        return Upperallstring(_value);
    }

    static string Removepuncuation( string S1 ){
        for (int i = 0; i < S1.length(); i++)
        {
            if (ispunct(S1[i]))
            {
               S1.erase(i , 1);
            }
            
        }
        return S1;
        
    }
    string Removepuncuation(){
        return Removepuncuation(_value);
    }

    static string Lowerfirstletter(string S1 ){
        char delim = ' ';
         S1[0] = tolower(S1[0]);
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] == delim)
            {
                S1[i+1] = tolower(S1[i+1]);
            }
            

        }
        return S1;
        
    }
    string Lowerfirstletter(){
        return Lowerfirstletter(_value);
    }

    static vector<string> Split(string S1, string Delim)
    {
  
        vector<string> vString;
  
        short pos = 0;
        string sWord; // define a string variable  
  
        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                vString.push_back(sWord);
            }
  
            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }
  
        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }
  
        return vString;
  
    }
  
    vector<string> Split( string Delim)
    {
        return Split(_value, Delim);
    }

    string reblace(string raplaceword){

        return _value.replace(6 , 6 , raplaceword);
    }


     void reversestring(string S1){
        for (int i = S1.length(); i >= 0; i--)
        {
            cout << S1[i];
        }
        
    }


        


};