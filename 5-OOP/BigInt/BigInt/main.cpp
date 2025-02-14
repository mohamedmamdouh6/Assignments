#include "BigInt.h"
// Main Function

int main()
{
    try
    {
    }
    catch (invalid_argument e)
    {
        cout << e.what() << endl;
    }
    catch (runtime_error e)
    {
        cout << e.what() << endl;
    }
    return 0;
}