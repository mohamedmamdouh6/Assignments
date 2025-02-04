#include "BigInt.h"

int main()
{
    try
    {
        BigInt num1("-0001");
        BigInt num2("9999999");
        BigInt result1 = num1 - num2;
        cout << result1 << endl;

    }
    catch (invalid_argument e)
    {
        cout << e.what() << endl;
    }
    return 0;
}