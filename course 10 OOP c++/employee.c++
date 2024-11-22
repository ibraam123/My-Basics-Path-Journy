#include <iostream>

using namespace std;

class clsEmployee
{
private:
    short _ID;
    string _FirstName;
    string _LastName;
    string _Title;
    string _Email;
    string _Phone;
    double _Salary;
    string _Department;

public:
    clsEmployee(short ID, string FirstName, string LastName,string Title, string Email, string Phone,double Salary,string Department)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Title = Title;
        _Email = Email;
        _Phone = Phone;
        _Salary = Salary;
        _Department = Department;
    }

    short ID()  //Read-only property
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

    void setTitle(string Title)
    {
        _Title = Title;
    }
    string getTitle()
    {
        return _Title;
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

    void setSalary(double Salary)
    {
        _Salary = Salary;
    }
    double getSalary()
    {
        return _Salary;
    }

    void setDepartment(string Department)
    {
        _Department = Department;
    }
    string getDepartment()
    {
        return _Department;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void Print()
    {
        cout << "\nInfo:" << endl;
        cout << "_____________________________________" << endl;
        cout << "ID         : " << _ID << endl;
        cout << "First Name : " << _FirstName << endl;
        cout << "Last Name  : " << _LastName << endl;
        cout << "Full Name  : " << FullName() << endl;
        cout << "Email      : " << _Email << endl;
        cout << "Phone      : " << _Phone << endl;
        cout << "Title      : " << _Title << endl;
        cout << "Department : " << _Department << endl;
        cout << "Salary     : " << _Salary << endl;
        cout << "_____________________________________" << endl;
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

int main()
{
    clsEmployee Employee1(20, "Dunia", "Sy","Mechatronics Engineer","std@yildiz.edu.tr","5353535",1700,"Mechanical Department"); //Encapsulation & Parameterized Constructor

    Employee1.Print();
    Employee1.SendEmail("Internship Job", "CNC");
    Employee1.SendSMS("Please I need an internship XD");
   
    system("pause>0");
    return 0;
}