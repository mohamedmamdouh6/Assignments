#include "Employee.h"
// Private Functionalities
bool Employee::isIDExist(string id)
{
	string line;
	if (employee.is_open())
		employee.close();
	if (!employee.is_open())
	{
		employee.open("Employees.txt", ios::in | ios::app);
		if (!employee.is_open())
			throw runtime_error("We Can Not Access The File!");
	}
	while (getline(employee, line))
	{
		int i = 0;
		string check = "";
		while (line[i] != '|')
		{
			check += line[i];
			i++;
		}
		if (check == id)
		{
			employee.close();
			return true;
		}
	}
	employee.close();
	return false;
}
bool Employee::isChars(string str)
{
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'))
			return false;
	}
	return true;
}
bool Employee::isIdDigits(string str)
{
	str.erase(str.begin());
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}
bool Employee::isMail(string str)
{
	if (isalpha(str[0]) == 0)
		return false;
	int size = str.size();
	int i = 0;
	while (str[i] != '@' && i < size)
		i++;
	if (i == size || i == 1)
		return false;
	for (int j = 0; j < i; j++)
	{
		if (isalpha(str[j]) == 0 && !isdigit(str[j]) && str[j] != '.')
			return false;
		if (str[j] == '.' && isalpha(str[j + 1]) == 0)
			return false;
	}
	str.erase(0, i);
	if (str == "@gmail.com" || str == "@outlook.com" || str == "@hotmail.com" ||
		str == "@yahoo.com" || str == "@icloud.com")
		return true;
	return false;
}
// Public Functionalities
void Employee::addEmployee()
{
	cout << "Please Enter The Following Data Of The Employee:-" << endl;
	// ID
	cout << "ID: ";
	string id;
	cin >> id;
	while (isdigit(id[0]) || id[1] != '0' || !isupper(id[0]) || isIDExist(id) || !isIdDigits(id) || id.size() > 7)// M023
	{
		if (isIDExist(id))
		{
			cout << "The ID Is Exist Already!" << endl;
			cout << "Please Enter Another One: ";
		}
		else
		{
			cout << "Invalid ID!" << endl;
			cout << "Please Enter The ID Again: ";
		}
		cin >> id;
	}
	// First Name
	cout << "First Name: ";
	string firstName;
	cin >> firstName;
	while (!isChars(firstName) || firstName.size() > 15)
	{
		cout << "Invalide First Name!" << endl;
		cout << "First Name: ";
		cin >> firstName;
	}
	// Surname
	cout << "Surname: ";
	string surname;
	cin >> surname;
	while (!isChars(surname) || surname.size() > 15)
	{
		cout << "Invalide Surname!" << endl;
		cout << "Surname: ";
		cin >> surname;
	}
	// Email
	cout << "Email: ";
	string email;
	cin >> email;
	while (!isMail(email) || email.size() > 33)
	{
		cout << "Invalide Email!" << endl;
		cout << "Email: ";
		cin >> email;
	}
	// Roll
	cout << "Roll: ";
	string roll;
	getline(cin >> ws, roll);
	while (roll.size() > 50)
	{
		cout << "Invalid Roll!" << endl;
		cout << "Roll: ";
		getline(cin >> ws, roll);
	}
	// Responsibility
	cout << "Responsibility: ";
	string responsibility;
	getline(cin >> ws, responsibility);
	while (responsibility.size() > 100)
	{
		cout << "Invalid Responsibility!" << endl;
		cout << "Responsibility: ";
		getline(cin >> ws, responsibility);
	}
	// Skills
	cout << "Skills: ";
	string skills;
	getline(cin >> ws, skills);
	while (skills.size() > 150)
	{
		cout << "Invalid Skills!" << endl;
		cout << "Skills: ";
		getline(cin >> ws, skills);
	}
	// Work Model
	cout << "Work Model: ";
	string workModel;
	getline(cin >> ws, workModel);
	while (workModel.size() > 20)
	{
		cout << "Invalid Work Model!" << endl;
		cout << "Work Model: ";
		getline(cin >> ws, workModel);
	}
	// Project
	cout << "Project: ";
	string project;
	getline(cin >> ws, project);
	while (project.size() > 100)
	{
		cout << "Invalid Project!" << endl;
		cout << "Project: ";
		getline(cin >> ws, project);
	}
	// Team
	cout << "Team: ";
	string team;
	getline(cin >> ws, team);
	while (team.size() > 50)
	{
		cout << "Invalid Team!" << endl;
		cout << "Team: ";
		getline(cin >> ws, team);
	}
	// Status
	cout << "Status: ";
	string status;
	getline(cin >> ws, status);
	while (status.size() > 100)
	{
		cout << "Invalid Status!" << endl;
		cout << "Status: ";
		getline(cin >> ws, status);
	}
	// Shift
	cout << "Shift: ";
	string shift;
	getline(cin >> ws, shift);
	while (shift.size() > 20)
	{
		cout << "Invalid Shift!" << endl;
		cout << "Shift: ";
		getline(cin >> ws, shift);
	}
	// Salary
	cout << "Salary: ";
	float salary;
	cin >> salary;
	while (salary < 500)
	{
		cout << "Invalid Salary!" << endl;
		cout << "Salary: ";
		cin >> salary;
	}
	// Achievements
	cout << "Achievements: ";
	string achievement;
	getline(cin >> ws, achievement);
	while (achievement.size() > 1000)
	{
		cout << "Invalid Achievement!" << endl;
		cout << "Achievement: ";
		getline(cin >> ws, achievement);
	}
	// Behavior
	cout << "Behavior: ";
	string behavior;
	getline(cin >> ws, behavior);
	while (behavior.size() > 500)
	{
		cout << "Invalid Behavior!" << endl;
		cout << "Behavior: ";
		getline(cin >> ws, behavior);
	}
	// Date & Time
	time_t now = time(nullptr);
	tm localTime;
	localtime_s(&localTime, &now);
	char buffer[100];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime);
	string date_time(buffer);
	// Opening The Employee File
	employee.open("Employees.txt", ios::out | ios::app);
	if (!employee.is_open())
		throw runtime_error("We Can Not Access The File!");
	// Storing The Data
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
	employee << endl;
	employee.close();
}
void Employee::editEmployee()
{
}
void Employee::showEmployee()
{
}