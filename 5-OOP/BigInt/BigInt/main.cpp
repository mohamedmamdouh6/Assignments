#include "BigInt.h"

int main()
{
    BigInt number1;
    BigInt number2;
    BigInt sum;
    cout << "Enter number1: ";
    cin >> number1;
    cout << "Enter numbre2: ";
    cin >> number2;
    sum = number1 + number2;
    cout << sum << endl;
    return 0;
}