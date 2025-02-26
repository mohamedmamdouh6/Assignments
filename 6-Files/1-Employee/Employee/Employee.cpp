#include "Employee.h"
// Generic Functionalities
string Employee::isEmpExist(string id)
{
	string line;
	if (employee.is_open())
		employee.close();
	if (!employee.is_open())
	{
		employee.open("Employees.txt", ios::in | ios::app);
		if (employee.fail())
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
			return line;
		}
	}
	employee.close();
	return "0";
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
bool Employee::isID(string str)
{
	if (!isalpha(str[0]) || !isupper(str[0]) || str[1] != '0')
		return false;
	str.erase(str.begin());
	int size = str.size();
	for (int i = 1; i < size; i++)
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
bool Employee::verifyPipe(string str)
{
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '|')
			return true;
	}
	return false;
}
void Employee::print(string line)
{
	stringstream temp(line);
	int i = 0;
	string arr[16];
	while (getline(temp >> ws, arr[i], '|'))
		i++;
	// Printing
	cout << "====================== Employee " << arr[0] << " =======================" << endl;
	cout << "|ID|: " << arr[0] << "\n---------------------\n";
	cout << "|First Name|: " << arr[1] << "\n---------------------\n";
	cout << "|Surname|: " << arr[2] << "\n---------------------\n";
	cout << "|Email|: " << arr[3] << "\n---------------------\n";
	cout << "|Role|: " << arr[4] << "\n---------------------\n";
	cout << "|Responsibility|: " << arr[5] << "\n---------------------\n";
	cout << "|Skills|: " << arr[6] << "\n---------------------\n";
	cout << "|Work Model|: " << arr[7] << "\n---------------------\n";
	cout << "|Project|: " << arr[8] << "\n---------------------\n";
	cout << "|Team|: " << arr[9] << "\n---------------------\n";
	cout << "|Status|: " << arr[10] << "\n---------------------\n";
	cout << "|Shift|: " << arr[11] << "\n---------------------\n";
	cout << "|Salary|: $" << arr[12] << "\n---------------------\n";
	cout << "|Achievements|: " << arr[13] << "\n---------------------\n";
	cout << "|Behavior|: " << arr[14] << "\n---------------------\n";
	cout << arr[15];
	cout << "\n===============================================================" << endl;
}
// Storing Functionalities
void Employee::storeID(string& id)
{
	while (isEmpExist(id) != "0" || !isID(id) || id.size() > 7)
	{
		if (isEmpExist(id) != "0")
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
}
void Employee::storeName(string& name)
{
	while (!isChars(name) || name.size() > 15)
	{
		cout << "Invalide Name!" << endl;
		cout << "Enter Again: ";
		cin >> name;
	}
}
void Employee::storeEmail(string& email)
{
	while (!isMail(email) || email.size() > 33)
	{
		cout << "Invalide Email!" << endl;
		cout << "Email: ";
		cin >> email;
	}

}
void Employee::storeData(string& data)
{
	while (data.size() > 1000 || verifyPipe(data))
	{
		cout << "Invalid Data!" << endl;
		cout << "Please Enter Again: ";
		getline(cin >> ws, data);
	}
}
void Employee::storeSalary(int& salary)
{
	while (salary < 500)
	{
		cout << "Invalid Salary!" << endl;
		cout << "Salary: ";
		cin >> salary;
	}
}
// User Functionalities
void Employee::addEmployee()
{
	cout << "Please Enter The Following Data Of The Employee:-" << endl;
	// ID
	cout << "ID: ";
	string id;
	cin >> id;
	storeID(id);
	// First Name
	cout << "First Name: ";
	string firstName;
	cin >> firstName;
	storeName(firstName);
	// Surname
	cout << "Surname: ";
	string surname;
	cin >> surname;
	storeName(surname);
	// Email
	cout << "Email: ";
	string email;
	cin >> email;
	storeEmail(email);
	// Role
	cout << "Role: ";
	string role;
	getline(cin >> ws, role);
	storeData(role);
	// Responsibility
	cout << "Responsibility: ";
	string responsibility;
	getline(cin >> ws, responsibility);
	storeData(responsibility);
	// Skills
	cout << "Skills: ";
	string skills;
	getline(cin >> ws, skills);
	storeData(skills);
	// Work Model
	cout << "Work Model: ";
	string workModel;
	getline(cin >> ws, workModel);
	storeData(workModel);
	// Project
	cout << "Project: ";
	string project;
	getline(cin >> ws, project);
	storeData(project);
	// Team
	cout << "Team: ";
	string team;
	getline(cin >> ws, team);
	storeData(team);
	// Status
	cout << "Status: ";
	string status;
	getline(cin >> ws, status);
	storeData(status);
	// Shift
	cout << "Shift: ";
	string shift;
	getline(cin >> ws, shift);
	storeData(shift);
	// Salary
	cout << "Salary: ";
	int salary;
	cin >> salary;
	storeSalary(salary);
	// Achievements
	cout << "Achievements: ";
	string achievement;
	getline(cin >> ws, achievement);
	storeData(achievement);
	// Behavior
	cout << "Behavior: ";
	string behavior;
	getline(cin >> ws, behavior);
	storeData(behavior);
	// Date & Time
	time_t now = time(nullptr);
	tm localTime;
	localtime_s(&localTime, &now);
	char buffer[100];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime);
	string date_time(buffer);
	// Opening The Employee File
	if (employee.is_open())
		employee.close();
	if (!employee.is_open())
	{
		employee.open("Employees.txt", ios::out | ios::app);
		if (employee.fail())
			throw runtime_error("We Can Not Access The File!");
	}
	// Storing The Data
	employee << id << "|";
	employee << firstName << "|";
	employee << surname << "|";
	employee << email << "|";
	employee << role << "|";
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
	string line = isEmpExist(id);
	cout << "		-----------------------------------------------------------" << endl;
	cout << "		.*.    The Employee Has Been Successfully Registered!	.*." << endl;
	cout << "		-----------------------------------------------------------" << endl;
	print(line);
}
void Employee::showEmployee()
{
	// Verify ID
	cout << "Please Enter The Employee ID: ";
	string id;
	cin >> id;
	string line = isEmpExist(id);
	while (line == "0")
	{
		cout << "ID Is Not Exist!" << endl;
		cout << "Please Enter an Exist ID: ";
		cin >> id;
		line = isEmpExist(id);
	}
	// Print
	print(line);
}
void Employee::editEmployee()
{
	// Get The Employee Line
	string line;
	char again = 'n';
	while (again == 'n' || again == 'N')
	{
		cout << "Please Enter The Employee ID: ";
		string id;
		cin >> id;
		line = isEmpExist(id);
		while (line == "0")
		{
			cout << "ID Is Not Exist!" << endl;
			cout << "Please Enter an Exist ID: ";
			cin >> id;
			line = isEmpExist(id);
		}
		print(line);
		cout << "Is This What You Are Looking For? (N/y): ";
		cin >> again;
	}
	// Specify Which Data
	cout << "Which Data Would You Like To Modify?\n"
		<< "[0] ID\n"
		<< "[1] First Name\n"
		<< "[2] Surname\n"
		<< "[3] Email\n"
		<< "[4] Role\n"
		<< "[5] Responsibility\n"
		<< "[6] Skills\n"
		<< "[7] Work Model\n"
		<< "[8] Project\n"
		<< "[9] Team\n"
		<< "[10] Status\n"
		<< "[11] Shift\n"
		<< "[12] Salary\n"
		<< "[13] Achievements\n"
		<< "[14] Behavior\n" << endl;
	cout << "Which One?: ";
	int choice;
	cin >> choice;
	while (choice > 14 || choice < 0)
	{
		cout << "Invalid Choice!" << endl;
		cout << "Please Choose Again: ";
		cin >> choice;
	}
	// Store Employee Info In Array Of String
	int i = 0;
	string str[16];
	stringstream temp(line);
	while (getline(temp >> ws, str[i], '|'))
		i++;
	// Store Modifications In m
	cout << "Please Enter Your Modifications:-\n";
	string m;
	switch (choice)
	{
	case 0:
	{
		cout << "New ID: ";
		cin >> m;
		storeID(m);
		break;
	}
	case 1:
	{
		cout << "New First Name: ";
		cin >> m;
		storeName(m);
		break;
	}
	case 2:
	{
		cout << "New Surname: ";
		cin >> m;
		storeName(m);
		break;
	}
	case 3:
	{
		cout << "New Email: ";
		cin >> m;
		storeEmail(m);
		break;
	}
	case 4:
	{
		cout << "New Role: ";
		cin >> m;
		storeData(m);
		break;
	}
	case 5:
	{
		cout << "New Responsibility: ";
		cin >> m;
		storeData(m);
		break;
	}
	case 6:
	{
		cout << "New Skills: ";
		cin >> m;
		storeData(m);
		break;
	}
	case 7:
	{
		cout << "New Work Model: ";
		cin >> m;
		storeData(m);
		break;
	}
	case 8:
	{
		cout << "New Project: ";
		cin >> m;
		storeData(m);
		break;
	}
	case 9:
	{
		cout << "New Team: ";
		cin >> m;
		storeData(m);
		break;
	}
	case 10:
	{
		cout << "New Status: ";
		cin >> m;
		storeData(m);
		break;
	}
	case 11:
	{
		cout << "New Shift: ";
		cin >> m;
		storeData(m);
		break;
	}
	case 12:
	{
		cout << "New Salary: ";
		int s;
		cin >> s;
		storeSalary(s);
		break;
	}
	case 13:
	{
		cout << "New Achievements: ";
		cin >> m;
		storeData(m);
		break;
	}
	case 14:
	{
		cout << "New Behavior: ";
		cin >> m;
		storeData(m);
		break;
	}
	}
	// Replace Old Data With New Data
	str[choice] = m;
	// Convert Array To Line
	string newLine;
	for (int i = 0; i < 16; i++)
	{
		newLine += str[i];
		newLine += '|';
	}
	// Store New Line In File
	if (employee.is_open())
		employee.close();
	if (!employee.is_open())
	{
		employee.open("Employees.txt", ios::in);
		if (employee.fail())
			throw runtime_error("We Can Not Access The File!");
	}
	// Create New Temp File
	fstream tempFile;
	if (tempFile.is_open())
		tempFile.close();
	else
	{
		tempFile.open("Temp_File.txt", ios::out);
		if (tempFile.fail())
			throw runtime_error("We Can Not Access The File!");
		tempFile.seekg(0, ios::end);
		if (tempFile.tellg() != 0)
			throw runtime_error("'Temp_File.txt' Is Exist Already!");
	}
	// Get Old ID
	string oldID;
	int x = 0;
	while (line[x] != '|')
	{
		oldID += line[x];
		x++;
	}
	// Move The Data From ''Employees.txt' To 'Temp_File.txt'
	string tempLine;
	while (getline(employee, tempLine))
	{
		int i = 0;
		string checkID;
		while (tempLine[i] != '|')
		{
			checkID += tempLine[i];
			i++;
		}
		if (checkID != oldID)
		{
			tempFile << tempLine << endl;
		}
	}
	// Add The Employee After Modification
	tempFile << newLine << endl;
	// Delete The Old File And Rename The New File
	employee.close();
	tempFile.close();
	remove("Employees.txt");
	rename("Temp_File.txt", "Employees.txt");
	// Printing The Modification
	cout << "		-----------------------------------------------------------" << endl;
	cout << "		.*.    The Employee Has Been Successfully Modified!	.*." << endl;
	cout << "		-----------------------------------------------------------" << endl;
	print(newLine);
}