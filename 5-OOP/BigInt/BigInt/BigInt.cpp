#include "BigInt.h"
// Constructors
BigInt::BigInt()
{
	internalNumber = "0";
}
BigInt::BigInt(const string& s)
{
	internalNumber = "";
	int i = 0;
	while (s[i] != '\0')
		i++;

}
