#ifndef BIGINT_H
#define BIGINT_H
#include <iostream>
#include <string>
#include <exception>
using namespace std;
class BigInt {
private:
	string number;
	// ------------Functionalities-------------
	void equalSize(string&, string&);
	void removeLeadingZeros(string&);
	bool validate(string);
	int compare(const BigInt&, const BigInt&);
	string subtract(string, string);
	string add(string, string);
	string multiply(string, string);
	long long divideByApproximation(string, string);
	string divide(string, string);
	string mod(string, string);
	string pow(string, string);
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
	BigInt& operator -- ();
	BigInt& operator -- (int);
	BigInt& operator ++ ();
	BigInt& operator ++ (int);
	BigInt operator + (BigInt&);
	BigInt operator - (BigInt&);
	BigInt operator * (BigInt&);
	BigInt operator / (BigInt&);
	BigInt operator % (BigInt&);
	BigInt operator ^ (BigInt&);
	// ----------Assignment Operators----------
	void operator += (BigInt&);
	void operator -= (BigInt&);
	void operator *= (BigInt&);
	void operator /= (BigInt&);
	void operator %= (BigInt&);
	void operator ^= (BigInt&);
	// -------------Other Operators------------
	friend ostream& operator << (ostream& out, const BigInt&);
	friend istream& operator >> (istream&, BigInt&);
};
#endif // BIGINT_H