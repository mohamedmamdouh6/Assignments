#include "BigInt.h"
// Main Function
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
    cout << "Enter a sign (-, +, *, /, %, ^): ";
    cin >> sign;
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