#include <iostream>

double myPow(double x, int n);

int main()
{
    double x = 2;
    long long n = -3;

    std::cout << myPow(x, n);

    return 0;
}

double myPow(double x, int n)
{
    double product, power = x, reciprocalPower;

    if (n == 0) { return 1; }

    if (n > 0)
    {
        for (int j = 1; j < n; j++)
        {
            product = power*x;
            power = product;
        }
        return power;
    }
    if (n < 0)
    {
        for (int j = 1; j < (-1*n); j++)
        {
            product = power*x;
            reciprocalPower = (1.0/(product));
            power = product;
        }
        return reciprocalPower;
    }

    return 1;
}
