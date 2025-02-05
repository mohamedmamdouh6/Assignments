#include "BigInt.h"
// -------------------Constructors-----------------------
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
BigInt::BigInt(const BigInt& object)
{
	number = object.number;
}
// -----------------Functionalities----------------------
void BigInt::paddingZeros(string& str1, int size)
{
	for (int i = 0; i < size; i++)
		str1.insert(0, "0");
}
void BigInt::removeLeadingZeros(string& str)
{ 
	int size = str.size();
	int i = 0;
	while (str[i] == '0' || str[i] == '-')
		i++;
	if (i == size)
		str = "0";
	else if (str[0] == '-')
	{
		i--;
		str.erase(1, i);
	}
	else
		str.erase(0, i);
}
bool BigInt::validation(string str)
{
	int size = str.size();
	// Is empty
	if (size == 0)
		throw invalid_argument("The BigInt Is Empty!");
	// If BigInt == -0
	if ((str[0] == '-' && str[1] == '0') && size == 2)
		throw invalid_argument("BigInt Can't be -0");
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
	int size1 = str1.size();
	int size2 = str2.size();
	// Padding Using Zeros 
	if (size1 > size2)
		paddingZeros(str2, size1 - size1);
	if (size2 > size1)
		paddingZeros(str1, size2 - size1);
	// Swap To subtract the larg number from the small number
	if (str1 < str2)
		swap(str1, str2);
	// Subtraction Operation
	string result = "";
	int borrow = 0;
	for (int i = str1.size() - 1; i >= 0; i--)
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
	removeLeadingZeros(result);
	return result;
}
string BigInt::addition(string str1, string str2)
{
	int size1 = str1.size();
	int size2 = str2.size();
	// Padding Using Zeros
	if (size1 > size2)
		paddingZeros(str2, size1 - size2);
	if (size1 < size2)
		paddingZeros(str1, size2 - size1);
	// Addition Operation
	string result = "";
	int tens = 0;
	for (int i = str1.size() - 1; i >= 0; i--)
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
	// Remove Leading Zeros If There are
	removeLeadingZeros(result);
	return result;
}
// ---------------Relational Operators-------------------
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
// ----------------Logical Operators---------------------
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
// ---------------Arithmatic Operators-------------------
BigInt BigInt::operator + (BigInt& object)
{
	// I'm taking a copy
	string num1 = number;
	string num2 = object.number;
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
			int size1 = num1.size();
			int size2 = num2.size();
			if (size1 > size2)
				paddingZeros(num2, size1 - size2);
			if (size2 > size1)
				paddingZeros(num1, size2 - size2);
			if (num1 > num2)
				sign = true;
		}
		else if (num2[0] == '-')
		{
			num2.erase(num2.begin());
			int size1 = num1.size();
			int size2 = num2.size();
			if (size1 > size2)
				paddingZeros(num2, size1 - size2);
			if (size2 > size1)
				paddingZeros(num1, size2 - size2);
			if (num2 > num1)
				sign = true;
		}
		result.number = subtraction(num1, num2);
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
	BigInt result;
	// ------If they are negative--------
	if (num1[0] == '-' && num2[0] == '-')
	{
		bool sign = false;
		num1.erase(num1.begin());
		num2.erase(num2.begin());
		int size1 = num1.size();
		int size2 = num2.size();
		if (size1 > size2)
			paddingZeros(num2, size1 - size2);
		if (size2 > size1)
			paddingZeros(num1, size2 - size2);
		if (num1 > num2)
			sign = true;
		result.number = subtraction(num1, num2);
		if (sign)
			result.number.insert(0, "-");
	}// ------if one of them is negative------
	else if (num1[0] == '-' || num2[0] == '-')
	{
		bool sign = false;
		if (num1[0] == '-')
		{
			num1.erase(num1.begin());
			int size1 = num1.size();
			int size2 = num2.size();
			if (size1 > size2)
				paddingZeros(num2, size1 - size2);
			if (size2 > size1)
				paddingZeros(num1, size2 - size2);
			if (num1 > num2)
				sign = true;
		}
		else if (num2[0] == '-')
		{
			num2.erase(num2.begin());
			int size1 = num1.size();
			int size2 = num2.size();
			if (size1 > size2)
				paddingZeros(num2, size1 - size2);
			if (size2 > size1)
				paddingZeros(num1, size2 - size2);
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
		bool sign = false;
		int size1 = num1.size();
		int size2 = num2.size();
		if (size1 > size2)
			paddingZeros(num2, size1 - size2);
		if (size2 > size1)
			paddingZeros(num1, size2 - size2);
		if (num1 < num2)
			sign = true;
		result.number = subtraction(num1, num2);
		if (sign)
			result.number.insert(0, "-");
	}
	return result;
}