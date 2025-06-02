//Overflows for any value x such that -2^{63} <= x <= 2^{63-1}
//Incomplete solution
#include <iostream>
#include <cmath>

long double myPow(long double x, long long n)
{
    long double result = 1;
    long long iteration = 1;

    if (n == 0) { return 1; }

    if (n < 0) {
        n = -n;
        x = 1/x;
    }
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            x = (x*x);
            n = (n/2);
        } else {
            result = result * x;
            x = (x*x);
            n = floor(n/2);
        }
        iteration++;
    }

    return result;
}

std::string addStrings(std::string num1, std::string num2) {
     long long sum1 = 0, sum2 = 0, grandSum;
     int multiplier = 0;

     for (int i = num1.length()-1; i >= 0; i--) {
        sum1 += (num1[i] - '0')*myPow(10, multiplier);
        multiplier += 1;
     }
     multiplier = 0;
     for (int j = num2.length()-1; j >= 0; j--) {
        sum2 += (num2[j] - '0')*myPow(10, multiplier);
        multiplier += 1;
     }

     grandSum = sum1 + sum2;

     return std::to_string(grandSum);
}

int main()
{
    std::cout << addStrings("9333852702227987","85731737104263");

    return 0;
}
