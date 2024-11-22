#include <iostream>
using namespace std;


// abstract class / interface / contract.
class clsmobile
{
    virtual void Dial(string Phonenumber);
    virtual void sendSMS(string Phonenumber , string Text) = 0;
    virtual void Takepicture() = 0;
   
};

class clsiPhone : public clsmobile
{

public:
    void Dial(string Phonenumber){

    };
    void sendSMS(string Phonenumber , string Text){

    };
    void Takepicture(){

    };
    

};


int main()
{

    clsiPhone iphone1;

    iphone1.Dial("012");
    
}