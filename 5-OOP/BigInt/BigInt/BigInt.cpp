#include "BigInt.h"
// -------------------Constructors-----------------------
BigInt::BigInt()
{
	number = "0";
}
BigInt::BigInt(const char* ch)
{
	if (validate(ch))
		number = ch;
}
BigInt::BigInt(const string& str)
{
	if (validate(str))
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
	if (validate(object.number))
		number = object.number;
}
// -----------------Functionalities----------------------
void BigInt::equalSize(string& str1, string& str2)
{
	int size1 = str1.size();
	int size2 = str2.size();
	if (size1 > size2)
	{
		for (int i = 0; i < size1 - size2; i++)
			str2.insert(0, "0");
	}
	else if (size2 > size1)
	{
		for (int i = 0; i < size2 - size1; i++)
			str1.insert(0, "0");
	}
}
void BigInt::removeLeadingZeros(string& str)
{ 
	int size = str.size();
	int i = 0;
	while (str[i] == '0' || str[i] == '-')
		i++;
	if (i == size)
	{
		str = "0";
	}
	else if (str[0] == '-')
	{
		i--;
		str.erase(1, i);
	}
	else
		str.erase(0, i);
}
bool BigInt::validate(string str)
{
	int size = str.size();
	// Is empty
	if (size == 0)
		throw invalid_argument("The BigInt Is Empty!");
	// If BigInt == -00000000000
	if ((str[0] == '-' && str[1] == '0'))
	{
		int i = 1;
		while (str[i] == '0')
			i++;
		if (i == str.size())
			throw invalid_argument("BigInt Can't be: " + str);
	}
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
	int size1 = object1.number.size();
	int size2 = object2.number.size();
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
string BigInt::subtract(string str1, string str2)
{
	// Padding Using Zeros 
	equalSize(str1, str2);
	// Swap To subtract the small number from the larg number
	bool sign = false;
	if (str1 < str2)
	{
		swap(str1, str2);
		sign = true;
	}
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
	if (sign)
	{
		result.insert(0, "-");
	}
	return result;
}
string BigInt::add(string str1, string str2)
{
	// Padding Using Zeros
	equalSize(str1, str2);
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
string BigInt::multiply(string str1, string str2)
{
	string result = "0";
	for (int i = str1.size() - 1; i >= 0; i--)
	{
		string multiplier = "";
		int carry = 0;
		for (int j = str2.size() - 1; j >= 0; j--)
		{
			int num1 = str1[i] - '0';
			int num2 = str2[j] - '0';
			int total = num1 * num2 + carry;
			carry = total / 10;
			char digit = (total % 10) + '0';
			multiplier.insert(multiplier.begin(), digit);
		}
		if (carry > 0)
		{
			multiplier.insert(multiplier.begin(), carry + '0');
		}
		if (i != str1.size() - 1)
		{
			for (int zeros = i; zeros < str1.size() - 1; zeros++)
				multiplier.insert(multiplier.size(), "0");
		}
		result = add(multiplier, result);
	}
	return result;
}
long long BigInt::divideByApproximation(string numerator, string denominator)
{
	int size1 = numerator.size();
	int size2 = denominator.size();
	string partOfNumerator = "";
	string partOfDenominator = "";
	if (size1 > 17 && size2 > 17)
	{
		partOfNumerator.insert(0, numerator, 0, 17);
		partOfDenominator.insert(0, denominator, 0, 17);
		if (size1 > size2)
		{
			partOfNumerator += "0";
		}
	}
	else
	{
		partOfNumerator = numerator;
		partOfDenominator = denominator;
	}
	long long  num1 = stod(partOfNumerator);
	long long  num2 = stod(partOfDenominator);
	long long result = num1 / num2;
	return result;
}
string BigInt::divide(string dividend, string divisor)
{
	removeLeadingZeros(dividend);
	removeLeadingZeros(divisor);
	if (divisor == "0")
		throw runtime_error("Can Not Divide By Zero!");
	if (dividend == "0")
		return "0";
	string result = "";
	string product = "";
	string remainder = "";
	string number = "";
	long long quotient;
	bool terminate = false;
	while (dividend.size() > 0)
	{
		int index = 0;

		// Getting the number >= divisor
		while ((number.size() == divisor.size() && divisor > number) || divisor.size() > number.size())
		{
			if (dividend.size() > 0)
			{
				terminate = false;
				number += dividend[0];
				dividend.erase(dividend.begin());
				removeLeadingZeros(number);
				if ((number.size() == divisor.size() && divisor > number) || divisor.size() > number.size())
				{
					result += "0";
					terminate = true;
				}
			}
			else
				break;
		}
		removeLeadingZeros(number);
		if (terminate && dividend.size() == 0)
		{
			removeLeadingZeros(result);
			return result;
		}
		else
		{
			string s1 = number;
			string s2 = divisor;
			quotient = divideByApproximation(number, divisor);
			if (quotient != 0)
			{
				result.insert(result.size(), to_string(quotient));
				product = multiply(to_string(quotient), divisor);
				remainder = subtract(number, product);
				if (remainder == "0" || remainder[0] == '-')
					number = "";
				else
					number = remainder;
			}
		}
	}
	removeLeadingZeros(result);
	return result;
}
string BigInt::mod(string str1, string str2)
{
	removeLeadingZeros(str1);
	removeLeadingZeros(str2);
	if (str2 == "0")
		throw runtime_error("Can Not Modulus By Zero!");
	int size1 = str1.size();
	int size2 = str2.size();
	string result;
	if (size1 < size2 || (size1 == size2 && str1 < str2))
		result = str1;
	string quotient = divide(str1, str2);
	string product = multiply(quotient, str2);
	string remainder = subtract(str1, product);
	if (remainder == "0")
		result = "0";
	else
		result = remainder;
	return result;
}
string BigInt::pow(string base, string power)
{
	removeLeadingZeros(base);
	removeLeadingZeros(power);
	if (power[0] == '-')
		return "0";
	if (power == "0")
		return "1";
	string odd = mod(power, "2");
	if (odd == "1")
		power = subtract(power, "1");
	string result = base;
	while (power != "1")
	{
		result = multiply(result, result);
		power = divide(power, "2");
	}
	if (odd == "1")
		result = multiply(result, base);
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
BigInt& BigInt::operator ++ ()
{
	number = add(number, "1");
	return *(this);
}
BigInt& BigInt::operator ++ (int)
{
	number = add(number, "1");
	return *(this);
}
BigInt& BigInt::operator -- ()
{
	number = subtract(number, "1");
	return *(this);
}
BigInt& BigInt::operator -- (int)
{
	number = subtract(number, "1");
	return *(this);
}
BigInt BigInt::operator + (BigInt& object)
{
	BigInt result;
	// I'm taking copies
	string num1 = number;
	string num2 = object.number;
	// -------If they are negative-------
	if (num1[0] == '-' && num2[0] == '-')
	{
		num1.erase(num1.begin());
		num2.erase(num2.begin());
		result.number = add(num1, num2);
		result.number.insert(0, "-");
	}// ------if one of them is negative-----
	else if (num1[0] == '-' || num2[0] == '-')
	{	
		bool sign = false;
		if (num1[0] == '-')
		{
			num1.erase(num1.begin());
			equalSize(num1, num2);
			if (num1 > num2)
				sign = true;
		}
		else
		{
			num2.erase(num2.begin());
			equalSize(num1, num2);
			if (num2 > num1)
				sign = true;
		}
		result.number = subtract(num1, num2);
		if (result.number[0] == '-')
			result.number.erase(result.number.begin());
		if (sign)
			result.number.insert(0, "-");
	}// ------if they are positive------
	else
	{
		result.number = add(num1, num2);
	}
	return result;
}
BigInt BigInt::operator - (BigInt& object)
{
	BigInt result;
	// I'm taking copies
	string num1 = number;
	string num2 = object.number;
	// ------If they are negative--------
	if (num1[0] == '-' && num2[0] == '-')
	{
		num1.erase(num1.begin());
		num2.erase(num2.begin());
		result.number = subtract(num1, num2);
		if (result.number[0] == '-')
			result.number.erase(result.number.begin());
		else if (result.number[0] != '-' && result.number[0] != '0')
			result.number.insert(0, "-");
	}// ------if one of them is negative------
	else if (num1[0] == '-' || num2[0] == '-')
	{
		bool sign = false;
		if (num1[0] == '-')
		{
			num1.erase(num1.begin());
			sign = true;
		}
		else
		{
			num2.erase(num2.begin());
		}
		result.number = add(num1, num2);
		if (sign)
			result.number.insert(0, "-");
	}// ------if they are positive-------
	else
	{
		bool sign = false;
		equalSize(num1, num2);
		if (num1 < num2)
			sign = true;
		result.number = subtract(num1, num2);
		if (result.number[0] == '-')
			result.number.erase(result.number.begin());
		if (sign)
			result.number.insert(0, "-");
	}
	return result;
}
BigInt BigInt::operator * (BigInt& object)
{
	BigInt result;
	// I'm Taking copies
	string num1 = number;
	string num2 = object.number;
	// If They Are Negative
	if (num1[0] == '-' && num2[0] == '-')
	{
		num1.erase(num1.begin());
		num2.erase(num2.begin());
		result.number = multiply(num1, num2);
	}// If One Of Them Is Negative
	else if (num1[0] == '-' || num2[0] == '-')
	{
		if (num1[0] == '-')
		{
			num1.erase(num1.begin());
		}
		else
		{
			num2.erase(num2.begin());
		}
		result.number = multiply(num1, num2);
		if (result.number[0] != '0')
			result.number.insert(0, "-");
	}// If They Are Positive
	else
	{
		result.number = multiply(num1, num2);
	}
	return result;
}
BigInt BigInt::operator / (BigInt& object)
{
	// I'm Taking Copies
	string num1 = number;
	string num2 = object.number;
	BigInt result;
	// If They Are Negative
	if (num1[0] == '-' && num2[0] == '-')
	{
		num1.erase(num1.begin());
		num2.erase(num2.begin());
		result.number = divide(num1, num2);
	}// If One Of Them Is Negative
	else if (num1[0] == '-' || num2[0] == '-')
	{
		if (num1[0] == '-')
		{
			num1.erase(num1.begin());
		}
		else
		{
			num2.erase(num2.begin());
		}
		result.number = divide(num1, num2);
		result.number.insert(0, "-");
	}// If They Are Positive
	else
	{
		result.number = divide(num1, num2);
	}
	return result;
}
BigInt BigInt::operator % (BigInt& object)
{
	// I'm Taking Copies
	string num1 = number;
	string num2 = object.number;
	BigInt result;
	// If They Are Negative
	if (num1[0] == '-' && num2[0] == '-')
	{
		num1.erase(num1.begin());
		num2.erase(num2.begin());
		result.number = mod(num1, num2);
		if (result.number != "0")
			result.number.insert(result.number.begin(), '-');
	}// If One Of Them Is Negative
	else if (num1[0] == '-' || num2[0] == '-')
	{
		bool sign = false;
		if (num1[0] == '-')
			num1.erase(num1.begin());
		else
		{
			num2.erase(num2.begin());
			sign = true;
		}
		result.number = mod(num1, num2);
		if (sign && result.number != "0")
			result.number.insert(result.number.begin(), '-');
	}// If They Are Positive
	else
	{
		result.number = mod(num1, num2);
	}
	return result;
}
BigInt BigInt::operator ^ (BigInt& object)
{
	// I'm Taking Copies
	string base = number;
	string power = object.number;
	BigInt result;
	bool sign = false;
	if (base[0] == '-')
	{
		base.erase(base.begin());
		string temp = divide(power, "2");
		if (temp == "1")
			sign = true;
	}
	result.number = pow(base, power);
	if (sign)
		result.number.insert(result.number.begin(), '-');
	return result;
}
// -----------------Assignment Operators-----------------
void BigInt::operator += (BigInt& object)
{
	// I'm taking copies
	string num1 = number;
	string num2 = object.number;
	// -------If they are negative-------
	if (num1[0] == '-' && num2[0] == '-')
	{
		num1.erase(num1.begin());
		num2.erase(num2.begin());
		number = add(num1, num2);
		number.insert(0, "-");
	}// ------if one of them is negative-----
	else if (num1[0] == '-' || num2[0] == '-')
	{
		bool sign = false;
		if (num1[0] == '-')
		{
			num1.erase(num1.begin());
			equalSize(num1, num2);
			if (num1 > num2)
				sign = true;
		}
		else
		{
			num2.erase(num2.begin());
			equalSize(num1, num2);
			if (num2 > num1)
				sign = true;
		}
		number = subtract(num1, num2);
		if (number[0] == '-')
			number.erase(number.begin());
		if (sign)
			number.insert(0, "-");
	}// ------if they are positive------
	else
	{
		number = add(num1, num2);
	}
}
void BigInt::operator -= (BigInt& object) 
{
	// I'm taking copies
	string num1 = number;
	string num2 = object.number;
	// ------If they are negative--------
	if (num1[0] == '-' && num2[0] == '-')
	{
		num1.erase(num1.begin());
		num2.erase(num2.begin());
		number = subtract(num1, num2);
		if (number[0] == '-')
			number.erase(number.begin());
		else if (number[0] != '-' && number[0] != '0')
			number.insert(0, "-");
	}// ------if one of them is negative------
	else if (num1[0] == '-' || num2[0] == '-')
	{
		bool sign = false;
		if (num1[0] == '-')
		{
			num1.erase(num1.begin());
			sign = true;
		}
		else
		{
			num2.erase(num2.begin());
		}
		number = add(num1, num2);
		if (sign)
			number.insert(0, "-");
	}// ------if they are positive-------
	else
	{
		bool sign = false;
		equalSize(num1, num2);
		if (num1 < num2)
			sign = true;
		number = subtract(num1, num2);
		if (number[0] == '-')
			number.erase(number.begin());
		if (sign)
			number.insert(0, "-");
	}
}
void BigInt::operator *= (BigInt& object) 
{
	// I'm Taking copies
	string num1 = number;
	string num2 = object.number;
	// If They Are Negative
	if (num1[0] == '-' && num2[0] == '-')
	{
		num1.erase(num1.begin());
		num2.erase(num2.begin());
		number = multiply(num1, num2);
	}// If One Of Them Is Negative
	else if (num1[0] == '-' || num2[0] == '-')
	{
		if (num1[0] == '-')
		{
			num1.erase(num1.begin());
		}
		else
		{
			num2.erase(num2.begin());
		}
		number = multiply(num1, num2);
		if (number[0] != '0')
			number.insert(0, "-");
	}// If They Are Positive
	else
	{
		number = multiply(num1, num2);
	}
}
void BigInt::operator /= (BigInt& object)
{
	// I'm Taking Copies
	string num1 = number;
	string num2 = object.number;
	// If They Are Negative
	if (num1[0] == '-' && num2[0] == '-')
	{
		num1.erase(num1.begin());
		num2.erase(num2.begin());
		number = divide(num1, num2);
	}// If One Of Them Is Negative
	else if (num1[0] == '-' || num2[0] == '-')
	{
		if (num1[0] == '-')
		{
			num1.erase(num1.begin());
		}
		else
		{
			num2.erase(num2.begin());
		}
		number = divide(num1, num2);
		number.insert(0, "-");
	}// If They Are Positive
	else
	{
		number = divide(num1, num2);
	}
}
void BigInt::operator %= (BigInt& object)
{
	// I'm Taking Copies
	string num1 = number;
	string num2 = object.number;
	// If They Are Negative
	if (num1[0] == '-' && num2[0] == '-')
	{
		num1.erase(num1.begin());
		num2.erase(num2.begin());
		number = mod(num1, num2);
		if (number != "0")
			number.insert(number.begin(), '-');
	}// If One Of Them Is Negative
	else if (num1[0] == '-' || num2[0] == '-')
	{
		bool sign = false;
		if (num1[0] == '-')
			num1.erase(num1.begin());
		else
		{
			num2.erase(num2.begin());
			sign = true;
		}
		number = mod(num1, num2);
		if (sign && number != "0")
			number.insert(number.begin(), '-');
	}// If They Are Positive
	else
	{
		number = mod(num1, num2);
	}
}
void BigInt::operator ^= (BigInt& object)
{
	// I'm Taking Copies
	string base = number;
	string power = object.number;
	bool sign = false;
	if (base[0] == '-')
	{
		base.erase(base.begin());
		string temp = divide(power, "2");
		if (temp == "1")
			sign = true;
	}
	number = pow(base, power);
	if (sign)
		number.insert(number.begin(), '-');
}
// -------------------Other Operators--------------------
ostream& operator << (ostream& out, const BigInt& value)
{
	out << value.number;
	return out;
}
istream& operator >> (istream& in, BigInt& i)
{
	BigInt temp1;
	in >> temp1.number;
	BigInt temp2(temp1);
	i.number = temp2.number;
	return in;
}