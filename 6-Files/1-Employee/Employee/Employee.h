#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <ctime>
using namespace std;
// Employee
class Employee {
private:
	// Private Data Members
	fstream employee;
	// Private Functionalities Members
	bool isIDExist(string);
	bool isChars(string);
	bool isIdDigits(string);
	bool isMail(string);
public:
	// Public Functionalities Members
	void addEmployee();
	void editEmployee();
	void showEmployee();
};
#endif
