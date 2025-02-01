#include <iostream>
#include <string>
#include <exception>
#ifndef BIGINT_H
#define BIGINT_H
using namespace std;
class BigInt {
private:
	string number;
public:
	// --------------Constructors--------------
	BigInt();
	BigInt(const string&);
	BigInt(long long);
	BigInt(const char);
	BigInt(const BigInt&);
	// ----------Operator Overloading----------
	friend int compare(const BigInt&, const BigInt&);
	// Relational Operator
	friend bool operator == (const BigInt&, const BigInt&);
	friend bool operator > (const BigInt&, const BigInt&);
	friend bool operator < (const BigInt&, const BigInt&);
	friend bool operator >= (const BigInt&, const BigInt&);
	friend bool operator <= (const BigInt&, const BigInt&);
	friend bool operator != (const BigInt&, const BigInt&);
	// -----------Logical Operators------------
	friend bool operator && (const BigInt&, const BigInt&);
	friend bool operator || (const BigInt&, const BigInt&);
	friend bool operator ! (const BigInt&);
	// ----------Arithmetic Operators----------
		
	// -----------Bitwise Operators------------
		 
	// ----------Assignment Operators----------

};

#endif