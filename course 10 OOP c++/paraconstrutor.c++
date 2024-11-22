#include <iostream>

using namespace std;

class clsPerson
{
private:
    short _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:


    clsPerson(short ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    short ID() // Read-only property
    {
        return _ID;
    }

    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    string getFirstName()
    {
        return _FirstName;
    }

    void setLastName(string LastName)
    {
        _LastName = LastName;
    }
    string getLastName()
    {
        return _LastName;
    }

    void setEmail(string Email)
    {
        _Email = Email;
    }
    string getEmail()
    {
        return _Email;
    }

    void setPhone(string Phone)
    {
        _Phone = Phone;
    }
    string getPhone()
    {
        return _Phone;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void Print()
    {
        cout << "\nInfo:" << endl;
        cout << "___________________________" << endl;
        cout << "ID         : " << _ID << endl;
        cout << "First Name : " << _FirstName << endl;
        cout << "Last Name  : " << _LastName << endl;
        cout << "Full Name  : " << FullName() << endl;
        cout << "Email      : " << _Email << endl;
        cout << "Phone      : " << _Phone << endl;
        cout << "___________________________" << endl;
    }

    void SendEmail(string Subject, string Body)
    {
        cout << "\nThe following message sent succesfully to email: " << _Email << endl;
        cout << "Subject : " << Subject << endl;
        cout << "Body    : " << Body << endl;
    }

    void SendSMS(string TextMessage)
    {
        cout << "\nThe following SMS sent successfully to phone: " << _Phone << endl;
        cout << TextMessage << endl;
    }

};

class clsEmployee : public clsPerson
{
private:
    string _Title;
    string _Department;
    double _Salary;

public:

    clsEmployee(short ID, string FirstName, string LastName, string Email, string Phone , string Title , string Departement , double Salary)
            : clsPerson(ID , FirstName , LastName , Email , Phone)
    {
        _Title = Title;
        _Department = Departement;
        _Salary = Salary;
    }

    void setTitle(string Title)
    {
        _Title = Title;
    }
    string getTitle()
    {
        return _Title;
    }

    void setDepartment(string Department)
    {
        _Department = Department;
    }
    string getDepartment()
    {
        return _Department;
    }

    void setSalary(double Salary)
    {
        _Salary = Salary;
    }
    double getSalary()
    {
        return _Salary;
    }

};

int main()
{
    clsEmployee Employee1 (10 , "ibraam" , "magdy" , "ibraamwar@email.com", "01201382622" , "student" , "programmingadvices" , 5000);
    Employee1.Print();
    cout << Employee1.getTitle() << endl;
    cout << Employee1.getDepartment() << endl ;
    cout  << Employee1.getSalary() << endl ;

    system("pause>0");
    return 0;
}