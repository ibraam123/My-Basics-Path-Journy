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

    //copy constructor 
    //not important to make it
    clsAddress(clsAddress &old_object){
        _adressline1 = old_object.adressline1();
        _adressline2 = old_object.adressline2();
        _POBox = old_object.PObox();
        _ZipCode = old_object.Zipcode();

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


    clsAddress adress2 = adress1;
    adress2.print();
    return 0;
}