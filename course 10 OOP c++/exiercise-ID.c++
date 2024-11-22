#include <iostream>
using namespace std;

class clspersons{
private:
    short  _ID;
    string _fname;
    string _sname;
    string _fullname;
    string _email;
    string _phone;


public:
    clspersons(short ID , string fname , string sname , string email , string phone){
        _ID = ID;
        _fname = fname;
        _sname = sname;
        _fullname = fname + " " + sname;
        _email = email;
        _phone = phone;
    }


    void sendemail(string subject , string body){
        cout << "The folowing message sent successfully to email : " << _email << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
    }

    void sendSMS(string SMS){
        cout << "The folowing message sent successfully to phone : " << _phone << endl;
        cout << SMS << endl;
    }

    short ID(){
        return _ID;
    }


    string firstname(){
        return _fname;
    }

    string lastname(){
        return _sname;
    }

    string fullname(){
        return _fullname;
    }

    string Email(){
        return _email;
    }
    string Phone(){
        return _phone;
    }

    void print(){
        cout << "Info: \n";
        cout << "___________________\n";
        cout << "ID        :" << _ID << endl;
        cout << "Firstname :" << _fname << endl;
        cout << "Secondname:" << _sname << endl;
        cout << "Full name :" << _fullname << endl;
        cout << "Email     :" << _email << endl;
        cout << "Phone     :" << _phone << endl;
        cout << "___________________\n\n";
    }

};
int main(){
    clspersons person1(10 , "ibraam" , "magdy" , "ibraamwar@gmail.com" , "01201382622");

    person1.print();

    person1.sendemail("Hi" , "How are you?");
    person1.sendSMS("how are you?");

    return 0;
}