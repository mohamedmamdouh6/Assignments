#include <iostream>
using namespace std;

struct Student {
	int age;
	char name[50];
	float english;
	float math;
	float arabic;
	float physics;
	float chemistry;
};
// Genral
void Add(Student* ptr, int index)
{
	cout << "Enter Name: ";
	cin >> ptr[index].name;
	
	cout << "Age: ";
	cin >> ptr[index].age;
	while (ptr[index].age > 16 || ptr[index].age < 10)
	{
		cout << "Invalid Age" << endl;
		cout << "Enter Again: ";
		cin >> ptr[index].age;
	}

	cout << "English: ";
	cin >> ptr[index].english;
	while (ptr[index].english < 0 || ptr[index].english > 100)
	{
		cout << "Invalid Score!" << endl;
		cout << "Enter Again: ";
		cin >> ptr[index].english;
	}

	cout << "Math: ";
	cin >> ptr[index].math;
	while (ptr[index].math < 0 || ptr[index].math > 100)
	{
		cout << "Invalid Score!" << endl;
		cout << "Enter Again: ";
		cin >> ptr[index].math;
	}

	cout << "Arabic: ";
	cin >> ptr[index].arabic;
	while (ptr[index].arabic < 0 || ptr[index].arabic > 100)
	{
		cout << "Invalid Score!" << endl;
		cout << "Enter Again: ";
		cin >> ptr[index].arabic;
	}

	cout << "Physics: ";
	cin >> ptr[index].physics;
	while (ptr[index].physics < 0 || ptr[index].physics > 100)
	{
		cout << "Invalid Score!" << endl;
		cout << "Enter Again: ";
		cin >> ptr[index].physics;
	}

	cout << "Chemistry: ";
	cin >> ptr[index].chemistry;
	while (ptr[index].chemistry < 0 || ptr[index].chemistry > 100)
	{
		cout << "Invalid Score!" << endl;
		cout << "Enter Again: ";
		cin >> ptr[index].chemistry;
	}
}
void Show(Student* ptr, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "Name: " << ptr[i].name << endl;
		cout << "Age: " << ptr[i].age << endl;
		cout << "English: " << ptr[i].english << endl;
		cout << "Math: " << ptr[i].math << endl;
		cout << "Arabic: " << ptr[i].arabic << endl;
		cout << "Physics: " << ptr[i].physics << endl;
		cout << "Chemistry: " << ptr[i].chemistry << endl << endl;
	}
}
void PrintPer(Student* ptr, int count)
{
	float total;
	float per;
	for (int i = 0; i < count; i++)
	{
		total = ptr[i].english + ptr[i].math + ptr[i].arabic + ptr[i].physics + ptr[i].chemistry;
		per = (total / 500) * 100;
		cout << "Name: " << ptr[i].name << endl;
		cout << "Per: " << per << "%" << endl << endl;
	}
}
void GetHighest(Student *ptr, int count)
{
	float total;
	float highest = -1;
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		total = ptr[i].english + ptr[i].math + ptr[i].arabic + ptr[i].physics + ptr[i].chemistry;
		if (highest < total)
		{
			highest = total;
			index = i;
		}
		
	}
	if (highest != -1)
		cout << "The highest is " << ptr[index].name << " With Score " << highest << endl;
}
void PrintAverage(Student* ptr, int count)
{
	for (int i = 0; i < count; i++)
	{
		float total = ptr[i].english + ptr[i].math + ptr[i].arabic + ptr[i].physics + ptr[i].chemistry;
		float average = total / 5;
		cout << "Name: " << ptr[i].name << endl;
		cout << "Average: " << average << endl << endl;
	}
}
// Highest
void HighestArabic(Student* ptr, int count)
{
	float temp = -1;
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp < ptr[i].arabic)
		{
			temp = ptr[i].arabic;
			index = i;
		}
	}
	if (temp != -1)
		cout << "The Highest in arabic is " << ptr[index].name << " With " << temp << endl;
}
void HighestEnglish(Student* ptr, int count)
{
	float temp = -1;
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp < ptr[i].english)
		{
			temp = ptr[i].english;
			index = i;
		}
	}
	if (temp != -1)
		cout << "The Highest in english is " << ptr[index].name << " With " << temp << endl;
}
void HighestMath(Student* ptr, int count)
{
	float temp = -1;
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp < ptr[i].math)
		{
			temp = ptr[i].math;
			index = i;
		}
	}
	if (temp != -1)
		cout << "The Highest in math is " << ptr[index].name << " With " << temp << endl;
}
void HighestPhysics(Student* ptr, int count)
{
	float temp = -1;
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp < ptr[i].physics)
		{
			temp = ptr[i].physics;
			index = i;
		}
	}
	if (temp != -1)
		cout << "The Highest in physics is " << ptr[index].name << " With " << temp << endl;
}
void HighestChemistry(Student* ptr, int count)
{
	float temp = -1;
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp < ptr[i].chemistry)
		{
			temp = ptr[i].chemistry;
			index = i;
		}
	}
	if (temp != -1)
		cout << "The Highest in chemistry is " << ptr[index].name << " With " << temp << endl;
}
// Lowest
void LowestArabic(Student* ptr, int count)
{
	float temp = 101;
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp > ptr[i].arabic)
		{
			temp = ptr[i].arabic;
			index = i;
		}
	}
	if (temp != 101)
		cout << "The lowest in Arabic is " << ptr[index].name << " With " << temp << endl;
}
void LowestEnglish(Student* ptr, int count)
{
	float temp = 101;
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp > ptr[i].english)
		{
			temp = ptr[i].english;
			index = i;
		}
	}
	if (temp != 101)
		cout << "The lowest in english is " << ptr[index].name << " With " << temp << endl;
}
void LowestMath(Student* ptr, int count)
{
	float temp = 101;
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp > ptr[i].math)
		{
			temp = ptr[i].math;
			index = i;
		}
	}
	if (temp != 101)
		cout << "The lowest in Math is " << ptr[index].name << " With " << temp << endl;
}
void LowestPhysics(Student* ptr, int count)
{
	float temp = 101;
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp > ptr[i].physics)
		{
			temp = ptr[i].physics;
			index = i;
		}
	}
	if (temp != 101)
		cout << "The lowest in Physics is " << ptr[index].name << " With " << temp << endl;
}
void LowestChemistry(Student* ptr, int count)
{
	float temp = 101;
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp > ptr[i].chemistry)
		{
			temp = ptr[i].chemistry;
			index = i;
		}
	}
	if (temp != 101)
		cout << "The lowest in Chemistry is " << ptr[index].name << " With " << temp << endl;
}
// Passed
void PassArabic(Student* ptr, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (ptr[i].arabic >= 50)
		{
			cout << ptr[i].name << " Passed" << endl;
		}
	}
}
void PassEnglish(Student* ptr, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (ptr[i].english >= 50)
		{
			cout << ptr[i].name << " Passed" << endl;
		}
	}
}
void PassMath(Student* ptr, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (ptr[i].math >= 50)
		{
			cout << ptr[i].name << " Passed" << endl;
		}
	}
}
void PassPhysics(Student* ptr, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (ptr[i].physics >= 50)
		{
			cout << ptr[i].name << " Passed" << endl;
		}
	}
}
void PassChemistry(Student* ptr, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (ptr[i].chemistry >= 50)
		{
			cout << ptr[i].name << " Passed" << endl;
		}
	}
}
// Filled
void FillArabic(Student* ptr, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (ptr[i].arabic < 50)
		{
			cout << ptr[i].name << " Filled " << endl;
		}
	}
}
void FillEnglish(Student* ptr, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (ptr[i].english < 50)
		{
			cout << ptr[i].name << " Filled " << endl;
		}
	}
}
void FillMath(Student* ptr, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (ptr[i].math < 50)
		{
			cout << ptr[i].name << " Filled " << endl;
		}
	}
}
void FillPhysics(Student* ptr, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (ptr[i].physics < 50)
		{
			cout << ptr[i].name << " Filled " << endl;
		}
	}
}
void FillChemistry(Student* ptr, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (ptr[i].chemistry < 50)
		{
			cout << ptr[i].name << " Filled " << endl;
		}
	}
}
// Main
void main()
{
	int count;
	cout << "Enter the total of Students: ";
	cin >> count;			
	int choice = 0;
	if (count > 0)
	{
		int current = 0;
		Student *students = new Student[count];
		do
		{
			cout << "	Genral:" << endl
				<< "1 To Add a Student" << endl
				<< "2 To Show Students" << endl
				<< "3 To Print Percentage" << endl
				<< "4 To Get The highest" << endl
				<< "5 To Get Average" << endl
				<< "	Highest:" << endl
				<< "6 To Get the highest in Arabic" << endl
				<< "7 To Get the highest in English" << endl
				<< "8 To Get the highest in Math" << endl
				<< "9 To Get the highest in Physics" << endl
				<< "10 To Get the highest in Chemistry" << endl
				<< "	Lowest:" << endl
				<< "11 To Get the Lowest in Arabic" << endl
				<< "12 To Get the Lowest in English" << endl
				<< "13 To Get the Lowest in Math" << endl
				<< "14 To Get the Lowest in Physics" << endl
				<< "15 To Get the Lowest in Chemistry" << endl
				<< "	Passed:" << endl
				<< "16 To Get who is passed in Arabic" << endl
				<< "17 To Get who is passed in English" << endl
				<< "18 To Get who is passed in Math" << endl
				<< "19 To Get who is passed in Physics" << endl
				<< "20 To Get who is passed in Chemistry" << endl
				<< "	Filled:" << endl
				<< "21 To Get who is filled in Arabic" << endl
				<< "22 To Get who is filled in English" << endl
				<< "23 To Get who is filled in Math" << endl
				<< "24 To Get who is filled in Physics" << endl
				<< "25 To Get who is filled in Chemistry" << endl
				<< "-1 To Terminate" << endl << endl;
			cout << "Which One: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				if (current == count)
				{
					cout << "List is Full!" << endl;
				}
				else
				{
					Add(students, current);
					current++;
				}
				break;
			case 2:
				Show(students, current);
				break;
			case 3:
				PrintPer(students, current);
				break;
			case 4:
				GetHighest(students, current);
				break;
			case 5:
				PrintAverage(students, current);
				break;
			case 6:
				HighestArabic(students, current);
				break;
			case 7: 
				HighestEnglish(students, current);
				break;
			case 8:
				HighestMath(students, current);
				break;
			case 9:
				HighestPhysics(students, current);
				break;
			case 10:
				HighestChemistry(students, current);
				break;
			case 11:
				LowestArabic(students, current);
				break;
			case 12:
				LowestEnglish(students, current);
				break;
			case 13:
				LowestMath(students, current);
				break;
			case 14:
				LowestPhysics(students, current);
				break;
			case 15:
				LowestChemistry(students, current);
				break;
			case 16:
				PassArabic(students, current);
				break;
			case 17:
				PassEnglish(students, current);
				break;
			case 18:
				PassMath(students, current);
				break;
			case 19:
				PassPhysics(students, current);
				break;
			case 20:
				PassChemistry(students, current);
				break;
			case 21:
				FillArabic(students, current);
				break;
			case 22:
				FillEnglish(students, current);
				break;
			case 23:
				FillMath(students, current);
				break;
			case 24:
				FillPhysics(students, current);
				break;
			case 25:
				FillChemistry(students, current);
				break;
			}
		} while (choice != -1);
		delete[] students;

	}
	else
	{
		cout << "Invalid Number!" << endl;
		return;
	}
}