#include "BigInt.h"
// Main Function
int main()
{
    try
    {
        BigInt num1 = BigInt("100");
        BigInt num2 = BigInt("50");
        BigInt num3 = BigInt("-100");
        BigInt num4 = BigInt("-50");
        BigInt num5 = BigInt("-100");
        BigInt num6 = BigInt("0");

        BigInt result0 = num2 + num1;
        BigInt result1 = num1 + num2;
        BigInt result2 = num3 + num4;
        BigInt result3 = num3 + num2;
        BigInt result4 = num1 + num4;
        BigInt result5 = num4 + num1;
        BigInt result6 = num2 + num3;
        BigInt result7 = num5 + num3;
        BigInt result8 = num6 + num6;
        BigInt result9 = num6 + num4;
        BigInt result10 = num6 + num2;
        BigInt result11 = num4 + num6;
        BigInt result12 = num2 + num6;

        std::cout << "50 + 100 = " << result0 << " (Expected: 150)\n";
        std::cout << "100 + 50 = " << result1 << " (Expected: 150)\n";
        std::cout << "-100 + (-50) = " << result2 << " (Expected: -150)\n";
        std::cout << "-100 + 50 = " << result3 << " (Expected: -50)\n";
        std::cout << "100 + (-50) = " << result4 << " (Expected: 50)\n";
        std::cout << "-50 + 100 = " << result5 << " (Expected: 50)\n";
        std::cout << "50 + (-100) = " << result6 << " (Expected: -50)\n";
        std::cout << "-100 + (-100) = " << result7 << " (Expected: -200)\n";
        std::cout << "0 + 0 = " << result8 << " (Expected: 0)\n";
        std::cout << "0 + (-50) = " << result9 << " (Expected: -50)\n";
        std::cout << "0 + 50 = " << result10 << " (Expected: 50)\n";
        std::cout << "-50 + 0 = " << result11 << " (Expected: -50)\n";
        std::cout << "50 + 0 = " << result12 << " (Expected: 50)\n";

    }
    catch (invalid_argument e)
    {
        cout << e.what() << endl;
    }

    return 0;
}