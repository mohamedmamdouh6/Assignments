#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;
// Employee
class Employee {
private:
	// Data Members
	fstream employee;
	// Generic Functionalities
	string isEmpExist(string);
	bool isChars(string);
	bool isID(string);
	bool isMail(string);
	bool verifyPipe(string);
	void print(string);
	// Storing Functionalities
	void storeID(string);
	void storeName(string);
	void storeEmail(string);
	void storeData(string);
	void storeSalary(double);
public:
	// User Functionalities
	void addEmployee();
	void editEmployee();
	void showEmployee();
};
#endif
