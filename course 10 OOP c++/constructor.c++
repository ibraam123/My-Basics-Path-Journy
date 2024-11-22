/**constructor from construction : بناء 
 * constructor is a tool of building
 * by defult a compiler bulid a constructor
 * 
 * name of comstructor same name of class
 * benifits:
 * he runing when make object without calling
 * 
*/


#include<iostream>
using namespace std;

class clsAddress
{
private:
    string _adressline1;
    string _adressline2;
    string _POBox;
    string _ZipCode;

public:


    clsAddress(string adressline1 ,string adressline2 , string pobox , string zipcode){
        _adressline1 = adressline1;
        _adressline2 = adressline2;
        _POBox = pobox;
        _ZipCode = zipcode;

    }
    clsAddress(){

    }
    // forced object dont empty must input a parameters
    // default constructor removed

    void Setadressline1(string adressline1){
        _adressline1 = adressline1;
    }

    void Setadressline2(string adressline2){
        _adressline2 = adressline2;
    }

    void SetPObox(string pobox){
        _POBox = pobox;
    }

    void SetZipcode(string zipcode){
        _ZipCode = zipcode;
    }

    string adressline1(){
        return _adressline1 ;
    }

    string adressline2(){
        return _adressline2 ;
    }

    string PObox(){
       return _POBox ;
    }

    string Zipcode(){
         return _ZipCode;
    }


    void print(){
        cout << "Address Details: " << endl << "---------------------" << endl;
        cout << "Addressline1: " << _adressline1 << endl;
        cout << "Addressline2: " << _adressline2 << endl;
        cout << "POBox       : " << _POBox << endl;
        cout << "ZipCode     : " << _ZipCode << endl; 
    }
    
};

int main(){
    clsAddress adress1("Queen alia Street","B 4001","112451","5555");

    adress1.print();

    return 0;
}