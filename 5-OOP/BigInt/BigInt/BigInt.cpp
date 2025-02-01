#include "BigInt.h"
// -------------------Constructors-------------------
BigInt::BigInt()
{
	number = "0";
}
BigInt::BigInt(const string& str)
{
	if (str[0] == '\0')
		throw invalid_argument("The String Is Empty!");
	number = "";
	int size = 0;
	while (str[size] != '\0')
		size++;
	// Validation of Leading Zeros:
	if (size > 1 && str[0] == '-')
	{
		if (str[1] == '0') // -0
			throw invalid_argument("Invalid Number!");
	}
	if (size > 1 && str[0] != '-')
	{
		if (str[0] == '0') // 01
			throw invalid_argument("Invalid Number!");
	}
	// Validation Of Numbers
	int start = 0;
	if (str[0] == '-')
	{
		number += '-';
		start = 1;
	}
	for (int i = start; i < size; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			number += str[i];
		}
		else
			throw invalid_argument("The String Is Not A Digit!");
	}
}
BigInt::BigInt(long long ll)
{
	if (ll < 0)
		throw invalid_argument("The Number Must Be Positive!");
	if (ll == 0)
	{
		number = '0';
		return;
	}
	while (ll)
	{
		number = char((ll % 10) + '0') + number;
		ll /= 10;
	}
}
BigInt::BigInt(const char ch)
{
	number = "";
	if (ch >= '0' && ch <= '9')
		number += ch;
	else
		throw invalid_argument("The Character Is Not A Digit!");
}
BigInt::BigInt(const BigInt& object) // I'm using '&' so that i don't have to init a new object
{
	number = object.number;
}
// -------------------Operator Overloading-------------------
int compare(const BigInt& object1, const BigInt& object2)
{
	// If they are equal
	if (object1.number == object2.number)
		return 0;
	int size1 = 0;
	int size2 = 0;
	while (object1.number[size1] != '\0')
		size1++;
	while (object2.number[size2] != '\0')
		size2++;
	// If they are Negative
	if (object1.number[0] == '-' && object2.number[0] == '-')
	{
		if (size1 > size2)
		{
			return -1;
		}
		else if (size1 < size2)
		{
			return 1;
		}
		for (int i = 1; i < size1; i++)
		{
			if (object1.number[i] > object2.number[i])
				return -1;
			if (object1.number[i] < object2.number[i])
				return 1;
		}
	}
	// If one of them is Negative
	if (object1.number[0] == '-')
	{
		return -1;
	}
	if (object2.number[0] == '-')
	{
		return 1;
	}
	// If they are Positive
	if (size1 > size2)
		return 1;
	if (size1 < size2)
		return -1;
	for (int i = 0; i < size1; i++)
	{
		if (object1.number[i] > object2.number[i])
			return 1;
		if (object1.number[i] < object2.number[i])
			return -1;
	}
}
// -------------------Relational Operators-------------------
bool operator == (const BigInt& object1, const BigInt& object2)
{
	return compare(object1, object2) == 0;
}
bool operator > (const BigInt& object1, const BigInt& object2)
{
	return compare(object1, object2) == 1;
}
bool operator < (const BigInt& object1, const BigInt& object2)
{
	return compare(object1, object2) == -1;
}
bool operator >= (const BigInt& object1, const BigInt& object2)
{
	int temp = compare(object1, object2);
	return temp == 1 || temp == 0;
}
bool operator <= (const BigInt& object1, const BigInt& object2)
{
	int temp = compare(object1, object2);
	return temp == -1 || temp == 0;
}
bool operator != (const BigInt& object1, const BigInt& object2)
{
	return !(compare(object1, object2) == 0);
}
// -------------------Logical Operator-------------------
bool operator && (const BigInt& object1, const BigInt& object2)
{
	return !(object1.number == "0") && !(object2.number == "0");
}
bool operator || (const BigInt& object1, const BigInt& object2)
{
	return !(object1.number == "0") || !(object2.number == "0");
}
bool operator ! (const BigInt& object)
{
	return object.number == "0";
}