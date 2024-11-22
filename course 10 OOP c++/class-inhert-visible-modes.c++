/**Syntax:
 *  class drivedclassname : <Visibilty mode> baseclass
 * {
 *      block of code
 * };
 * 
 */

/**
 **public inhertence: 
 * 
 * to private member
 * inaccessible
 * 
 * to protected member
 * protected
 * 
 * to public
 * public
 * 
 * 
 **public inhertence: 
 * 
 * to private member
 * inaccessible
 * 
 * to protected member
 * protected
 * 
 * to public
 * public
 * 
 **public inhertence: 
 * 
 * to private member
 * inaccessible
 * 
 * to protected member
 * protected
 * 
 * to public
 * public
 * 
 * 
 * 
 */


#include <iostream>
using namespace std;

class clsA 
{

private: 
    int V1;
    int Fun1()
    {
        return 1;
    }

protected:
    int V2;
    int Fun2()
    {
        return 2;
    }

public:
    int V3;
    int Fun3()
    {
        return 3;
    }

};

//try to change visibility mode public/private/protected 
//and see in the main what will happen iside objects.
class clsB : private clsA
{

public:
    
    int Fun4()
    {
        return 4;
    }

};

class clsC : public clsB
{

public:

    int Fun5()
    {
        return 5;
    }
};


int main()
{   
  

    clsB B1;
    //Try B1 after you change visibility mode in clsB.   and see what you can see.
    
    
    clsC C1;
    //Try C1 after you change visibility mode in clsB.   and see what you can see.
 
}

class Base {
  public:
    int x;
  protected:
    int y;
  private:
    int z;
};

class PublicDerived: public Base {
  // x is public
  // y is protected
  // z is not accessible from PublicDerived
};

class ProtectedDerived: protected Base {
  // x is protected
  // y is protected
  // z is not accessible from ProtectedDerived
};

class PrivateDerived: private Base {
  // x is private
  // y is private
  // z is not accessible from PrivateDerived
};
