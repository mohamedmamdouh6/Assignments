#include "LinkedList.h"
#include <iostream>
#include <string>
#include <exception>
using namespace std;
// Main
int main()
{
    try
    {
        // Some Of Code Here
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }
    catch (out_of_range e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
