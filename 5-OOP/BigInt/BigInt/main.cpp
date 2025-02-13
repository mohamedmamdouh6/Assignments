#include "BigInt.h"
// Main Function

int main()
{
    try
    {
        BigInt a("7423985720934750000020"), b("78423957293849");
        cout << "100 / 10 = " << (a / b) << " (Expected: 94664767)" << endl;

        a = BigInt("12345");
        b = BigInt("5");
        cout << "12345 / 5 = " << (a / b) << " (Expected: 2469)" << endl;

        a = BigInt("999999999999999999");
        b = BigInt("3");
        cout << "999999999999999999 / 3 = " << (a / b) << " (Expected: 333333333333333333)" << endl;

        a = BigInt("500");
        b = BigInt("2");
        cout << "500 / 2 = " << (a / b) << " (Expected: 250)" << endl;

        a = BigInt("1");
        b = BigInt("2");
        cout << "1 / 2 = " << (a / b) << " (Expected: 0)" << endl; // Assuming integer division

        a = BigInt("-100");
        b = BigInt("10");
        cout << "-100 / 10 = " << (a / b) << " (Expected: -10)" << endl;

        a = BigInt("100");
        b = BigInt("-10");
        cout << "100 / -10 = " << (a / b) << " (Expected: -10)" << endl;

        a = BigInt("-100");
        b = BigInt("-10");
        cout << "-100 / -10 = " << (a / b) << " (Expected: 10)" << endl;

        a = BigInt("0");
        b = BigInt("5");
        cout << "0 / 5 = " << (a / b) << " (Expected: 0)" << endl;

        a = BigInt("10");
        b = BigInt("0");
        cout << "10 / 0 = " << (a / b) << " (Expected: Error)" << endl;
    }
    catch (invalid_argument e)
    {
        cout << e.what() << endl;
    }
    catch (runtime_error e)
    {
        cout << e.what() << endl;
    }
    cout;
    return 0;
}