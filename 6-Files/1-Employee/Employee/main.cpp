#include "Employee.h"
#include <iostream>
#include <string>
#include <exception>
using namespace std;
// Main
int main()
{
    try
    {
        Employee emp;
        emp.addEmployee();
    }
    catch (runtime_error e)
    {
        cout << e.what() << endl;
    }
    return 0;
}