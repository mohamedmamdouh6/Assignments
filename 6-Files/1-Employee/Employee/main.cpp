#include "Employee.h"
#include <iostream>
#include <exception>
using namespace std;
// Employee Records
void employeeRecords()
{
    cout << "   -----------------------------------------" << endl;
    cout << "   .*.    Weclome To Employee Program    .*." << endl;
    cout << "   -----------------------------------------" << endl;
    cout << "Options:-" << endl
        << "=====================" << endl
        << "|1| To Add Employee |" << endl
        << "=====================" << endl
        << "|2| To Show Employee|" << endl
        << "=====================" << endl
        << "|3| To Edit Employee|" << endl
        << "=====================" << endl;
    cout << "Enter: ";
    int choice;
    cin >> choice;
    while (choice > 3 || choice < 1)
    {
        cout << "Invalid Choice!" << endl;
        cout << "Enter: ";
        cin >> choice;
    }
    Employee emp;
    switch (choice)
    {
    case 1:
    {
        try
        {
            emp.addEmployee();
        }
        catch (runtime_error e)
        {
            cout << e.what() << endl;
        }
        break;
    }
    case 2:
    {
        try
        {
            emp.showEmployee();
        }
        catch (runtime_error e)
        {
            cout << e.what() << endl;
        }
        break;
    }
    case 3:
    {
        try
        {
            emp.editEmployee();
        }
        catch (runtime_error e)
        {
            cout << e.what() << endl;
        }
        break;
    }
    }
    cout << "       -------------------------------" << endl;
    cout << "       .*.    See You Next Time    .*." << endl;
    cout << "       -------------------------------" << endl;
}
// Main
int main()
{
    char again = 'Y';
    while (again == 'y' || again == 'Y')
    {
        employeeRecords();
        cout << "Would You Like To Use It Again? (Y/n):";
        cin >> again;
    }
    return 0;
}