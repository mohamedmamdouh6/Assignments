#include "ArrayList.h"
#include <iostream>
using namespace std;
// Main
int main()
{ 
    try
    {
        // Some Of Code Here
    }
    catch (out_of_range e)
    {
        cout << e.what() << endl;
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }
    catch (invalid_argument e)
    {
        cout << e.what() << endl;
    }
	return 0;
}