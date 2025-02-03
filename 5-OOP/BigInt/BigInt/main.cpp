#include "BigInt.h"
// The main Function

int main() {
    try
    {
        BigInt i("01"); // Invalid
        BigInt j("-1");
        BigInt result = i + j;
        cout <<  result.show() << endl;
    }
    catch (invalid_argument s)
    {
        cout << s.what();
    }
    return 0;
}