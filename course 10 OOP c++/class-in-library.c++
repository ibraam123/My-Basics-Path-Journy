#include <iostream>
#include "person.h"
#include "employee.h"
using namespace std;


int main()

{

    clsEmployee Employee1 ( 10, "Mohammed","Abu-Hadhoud","A@a.com","8298982","CEO","ProgrammingAdvices",5000);
    
    Employee1.Print();
    return 0;
}