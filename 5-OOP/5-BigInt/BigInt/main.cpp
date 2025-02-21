#include <iostream>
#include <exception>
#include "BigInt.h"
using namespace std;
// Main
int main()
{
    BigInt number1, number2, result;
    bool terminate = true;
    char sign;
    while (terminate)
    {
        cout << "Enter The First Number: ";
        try
        {
            cin >> number1;
            terminate = false;
        }
        catch (invalid_argument e)
        {
            cout << e.what() << endl;
        }
        catch (runtime_error e)
        {
            cout << e.what() << endl;
        }
    }
    cout << "Enter an operator (-, +, *, /, %, ^): ";
    cin >> sign;
    while (sign != '-' && sign != '+' && sign != '*' && sign != '/' && sign != '%' && sign != '^')
    {
        cout << "Invalid Operator! " << endl;
        cout << "Please Enter An Operator Again: ";
        cin >> sign;
    }
    terminate = true;
    while (terminate)
    {
        cout << "Enter The Second Number: ";
        try
        {
            cin >> number2;
            terminate = false;
        }
        catch (invalid_argument e)
        {
            cout << e.what() << endl;
        }
        catch (runtime_error e)
        {
            cout << e.what() << endl;
        }
    }
    switch (sign)
    {
    case '+':
        result = number1 + number2;
        break;
    case '-':
        result = number1 - number2;
        break;
    case '*':
        result = number1 * number2;
        break;
    case '/':
        result = number1 / number2;
        break;
    case '%':
        result = number1 % number2;
        break;
    case '^':
        result = number1 ^ number2;
        break;
    }
    cout << "Result: " << result;
    return 0;
}