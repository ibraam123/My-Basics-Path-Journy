#include <iostream>
#include <string>
using namespace std;

int main(){
    string sinfo = "my name is ibraam magdy , i love programming." ;


    // print the length of the string
    cout << sinfo.length() << endl; // 45


    //return the letter at position (number of charcter)
    cout << sinfo.at(3) << endl; // n

    //adds (any sentence you want to main string)
    sinfo.append(" ibraamwar@gmail.com");
    cout << sinfo << endl;

    //inserts on position 
    sinfo.insert(23 , " haliem");
    cout << sinfo << endl;

    // prints all charcters next letters from postion substr( position , how many letters you want to print )
    cout << sinfo.substr(30 , 10) << endl;

    // add one charcter to the end of string
    sinfo.push_back('I');
    cout << sinfo << endl;

    // remove charcter from end of string
    sinfo.pop_back();
    cout << sinfo << endl;

    // find word you need in string 
    cout << sinfo.find("haliem") << endl;


    // clear all letters
    sinfo.clear();


    return 0;
}