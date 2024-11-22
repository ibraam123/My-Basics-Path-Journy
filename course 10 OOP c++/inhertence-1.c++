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
    // we put the default constructor here temporarly becasue inheritance will use it
    // in the comming lectures we will solve the prametarized constructor with inheritance
    clsPerson() {
        
    };

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
    clsEmployee Employee1;
    Employee1.setFirstName("Mohammed");
    Employee1.setLastName("Abu-Hadhoud");
    Employee1.setEmail("a@gmail.com");
    Employee1.Print();
    Employee1.setSalary(1700);
    cout << "Salary: " << Employee1.getSalary() << endl;

    // Calling the print will not print anything from derived class, only base class
    Employee1.Print();
    // therfore the print method will not serve me here, this is a problem will be solved in the next lecture

    system("pause>0");
    return 0;
}