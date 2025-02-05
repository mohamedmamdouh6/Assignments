#include <iostream>
#include <string>
#include <exception>
#ifndef BIGINT_H
#define BIGINT_H
using namespace std;
class BigInt {
private:
	string number;
	// ------------Functionalities-------------
 	void paddingZeros(string&, int);
	void removeLeadingZeros(string&);
	bool validation(string);
	int compare(const BigInt&, const BigInt&);
	string subtraction(string str1, string str2);
	string addition(string str1, string str2);
public:
	// --------------Constructors--------------
	BigInt();
	BigInt(const string&);
	BigInt(const char*);
	BigInt(unsigned long long);
	BigInt(int);
	BigInt(const BigInt&);
	// ----------Relational Operator-----------
	bool operator == (const BigInt&);
	bool operator > (const BigInt&);
	bool operator < (const BigInt&);
	bool operator >= (const BigInt&);
	bool operator <= (const BigInt&);
	bool operator != (const BigInt&);
	// -----------Logical Operators------------
	bool operator && (const BigInt&);
	bool operator || (const BigInt&);
	bool operator ! ();
	// ----------Arithmetic Operators----------
	BigInt operator + (BigInt&);
	BigInt operator - (BigInt&);
	// -----------Bitwise Operators------------

	// ----------Assignment Operators----------
	
	// -------------Other Operators------------
	friend ostream& operator << (ostream& out, BigInt& i)
	{
		out << i.number;
		return out;
	}
	friend istream& operator >> (istream& in, BigInt& i)
	{
		in >> i.number;
		return in;
	}
};

#endif