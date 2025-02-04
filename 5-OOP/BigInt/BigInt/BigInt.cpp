#include "BigInt.h"
// -------------------Constructors-------------------
BigInt::BigInt()
{
	number = "0";
}
BigInt::BigInt(const char* ch)
{
	if (validation(ch))
		number = ch;
}
BigInt::BigInt(const string& str)
{
	if (validation(str))
		number = str;
}
BigInt::BigInt(unsigned long long ll)
{
	number = to_string(ll);
}
BigInt::BigInt(int i)
{
	number = to_string(i);
}
BigInt::BigInt(const BigInt& object) // I'm using '&' so that i don't have to init a new object
{
	number = object.number;
}
// -----------------Functionalities------------------
void BigInt::removeLeadingZeros(string& str) // 0
{
	int size = str.size();
	int i = 0;
	while (str[i] == '0' || str[i] == '-') // -0012 0012221
		i++;
	if (i == size)
	{
		str = "0";
	}
	else if (str[0] == '-')// -00012
	{
		i--;
		str.erase(1, i);
	}
	else
	{
		str.erase(0, i);
	}

}
bool BigInt::validation(const string& str)
{
	if (str.empty())
		throw invalid_argument("The BigInt Is Empty!");
	int size = str.size();
	// Validation for Numbers
	int start = 0;
	if (str[0] == '-' && size > 1)
		start++;
	for (int i = start; i < size; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			throw invalid_argument("The BigInt Is Not A Digit!");
	}
	return true;
}
int BigInt::compare(const BigInt& object1, const BigInt& object2)
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
string BigInt::subtraction(string str1, string str2)
{
	if (str1 == str2)
		return "0";
	if (str1 == "0")
		return str2;
	if (str2 == "0")
		return str1;
	if (str1 < str2)
		swap(str1, str2);
	int size1 = str1.size();
	int size2 = str2.size();
	if (size1 > size2)
	{
		for (int i = 0; i < size1 - size2; i++)
		{
			str2.insert(0, "0");
		}
	}
	if (size1 < size2)
	{
		for (int i = 0; i < size2 - size1; i++)
		{
			str1.insert(0, "0");
		}
	}
	string result = "";
	int borrow = 0;
	for (int i = size1 - 1; i >= 0; i--)
	{
		int num1 = str1[i] - '0';
		int num2 = str2[i] - '0';
		int total = num1 - num2 - borrow;
		if (total < 0)
		{
			total += 10;
			borrow = 1;
		}
		else
		{
			borrow = 0;
		}
		result.insert(result.begin(), total + '0');
	}
	// Remove Leading Zeros If There Are
	int i = 0;
	while (i < result.size() && result[i] == '0')
		i++;
	if (i == result.size())// 00000000
	{
		result = "0";
	}
	else
	{
		result.erase(0, i);
	}
	return result;
}
string BigInt::addition(string str1, string str2)
{
	int size1 = str1.size();
	int size2 = str2.size();
	if (str1[0] == '0')
		return str2;

	if (str2[0] == '0')
		return str1;
	if (size1 > size2)
	{
		for (int i = 0; i < size1 - size2; i++)
		{
			str2.insert(0, "0");
		}
	}
	if (size1 < size2)
	{
		for (int i = 0; i < size2 - size1; i++)
		{
			str1.insert(0, "0");
		}
	}
	string result = "";
	int tens = 0;
	for (int i = size1 - 1; i >= 0; i--)
	{
		int num1 = str1[i] - '0';
		int num2 = str2[i] - '0';
		int total = num1 + num2 + tens;
		tens = total / 10;
		char digit = (total % 10) + '0';
		result.insert(result.begin(), digit);
	}
	if (tens == 1)
	{
		result.insert(0, "1");
	}
	return result;
}
// -------------------Relational Operators----------------
bool BigInt::operator == (const BigInt& object)
{
	return compare(number, object) == 0;
}
bool BigInt::operator > (const BigInt& object)
{
	return compare(number, object) == 1;
}
bool BigInt::operator < (const BigInt& object)
{
	return compare(number, object) == -1;
}
bool BigInt::operator >= (const BigInt& object)
{
	int temp = compare(number, object);
	return temp == 1 || temp == 0;
}
bool BigInt::operator <= (const BigInt& object)
{
	int temp = compare(number, object);
	return temp == -1 || temp == 0;
}
bool BigInt::operator != (const BigInt& object)
{
	return !(compare(number, object) == 0);
}
// -------------------Logical Operators-------------------
bool BigInt::operator && (const BigInt& object)
{
	return !(number == "0") && !(object.number == "0");
}
bool BigInt::operator || (const BigInt& object)
{
	return !(number == "0") || !(object.number == "0");
}
bool BigInt::operator ! ()
{
	return number == "0";
}
// ------------------Arithmatic Operators-----------------
BigInt BigInt::operator + (BigInt& object)
{
	// I'm taking a copy
	string num1 = number;
	string num2 = object.number;

	removeLeadingZeros(num1);
	removeLeadingZeros(num2);
	BigInt result;
	// -------If they are negative-------
	if (num1[0] == '-' && num2[0] == '-')
	{
		num1.erase(num1.begin());
		num2.erase(num2.begin());
		result.number = addition(num1, num2);
		result.number.insert(0, "-");
	}// ------if one of them is negative-----
	else if (num1[0] == '-' || num2[0] == '-')
	{	
		bool sign = false;
		if (num1[0] == '-')
		{
			num1.erase(num1.begin());
			if (num1 > num2) // It Doesn't work
			{
				sign = true;
				result.number = subtraction(num1, num2);
			}
		}
		else if (num2[0] == '-')
		{
			num2.erase(num2.begin());
			if (num2 > num1) // It Doesn't work
			{
				sign = true;
				result.number = subtraction(num2, num1);
			}
		}
		if (sign)
			result.number.insert(0, "-");
	}// ------if they are positive------
	else
	{
		result.number = addition(num1, num2);

	}
	return result;
}
BigInt BigInt::operator - (BigInt& object)
{
	// I'm taking a copy
	string num1 = number;
	string num2 = object.number;

	removeLeadingZeros(num2);
	removeLeadingZeros(num1);
	bool sign = false;
	BigInt result;
	// ------If they are negative--------
	if (num1[0] == '-' && num2[0] == '-')
	{
		num1.erase(num1.begin());
		num2.erase(num2.begin());
		result.number = subtraction(num1, num2);
		result.number.insert(0, "-");
	}// ------if one of them is negative------
	else if (num1[0] == '-' || num2[0] == '-')
	{
		if (num1[0] == '-')
		{
			num1.erase(num1.begin());
			if (num1 > num2) // It Doesn't work
			{
				sign = true;
			}
		}
		else if (num2[0] == '-')
		{
			num2.erase(num2.begin());
			if (num2 > num1) // It Doesn't work
			{
				sign = true;
			}
		}
		result.number = addition(num1, num2);
		if (sign)
			result.number.insert(0, "-");
	}// ------if they are positive-------
	else
	{
		result.number = subtraction(num1, num2);
	}
	return result;
}