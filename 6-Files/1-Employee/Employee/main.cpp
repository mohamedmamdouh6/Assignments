#include "Employee.h"
#include <iostream>
#include <string>
#include <exception>
using namespace std;
/*
ID – Unique identifier for records.
Name – Essential for identification.
Email – Primary contact information.
Role – Defines position in the company.
Responsibility – Outlines duties and expectations.
Skills – Important for job performance and role suitability.
Work Model – Defines if the job is remote, hybrid, or on-site.
Current Project – Shows what the employee is working on.
Team – Indicates team association.
Status – Employment status (active, on leave, etc.).
Shift – Specifies working hours.
Salary – Compensation details.
Achievement Log – Tracks accomplishments.
Behavior – Notes on conduct and performance.
Date – Could refer to joining date or last updated record.
	employee << id << "|";
	employee << firstName << "|";
	employee << surname << "|";
	employee << email << "|";
	employee << roll << "|";
	employee << responsibility << "|";
	employee << skills << "|";
	employee << workModel << "|";
	employee << project << "|";
	employee << team << "|";
	employee << status << "|";
	employee << shift << "|";
	employee << salary << "|";
	employee << achievement << "|";
	employee << behavior << "|";
	employee << date_time << "|";

*/
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