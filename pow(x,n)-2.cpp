#include <iostream>

double myPow(double x, int n);

int main()
{
    double x = 5;
    long long n = -3;

    std::cout << myPow(x, n);

    return 0;
}

double myPow(double x, int n)
{
    double product, power = x;
    long long n1 = n;

    if (n1 == 0) { return 1; }

    if (x == 1) { return 1; }

    if (n1 < 0) {
        x = 1/x;
        power = x;
        n1 = -n1;
    }

    if (n )

    for (long long j = 1; j < n1; j++)
    {
        product = power*x;
        power = product;
    }

    return power;
}

