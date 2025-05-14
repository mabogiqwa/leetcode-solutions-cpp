//Time complexity of O(log2n) - Improvement
#include <iostream>
#include <cmath>

double myPow(double x, int n);

int main()
{
    double x = 1;
    long long n = 10;

    std::cout << myPow(x, n);

    return 0;
}

double myPow(double x, int n)
{
    double result = 1;
    int iteration = 1;

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

