//Still too slow for large cases of n
#include <iostream>

double myPow(double x, int n);

int main()
{
    double x = 1;
    long long n = 8;

    std::cout << myPow(x, n);

    return 0;
}

double myPow(double x, int n)
{
    double product, power = x;

    if (n == 0) { return 1; }

    if (x == 1) { return 1; }

    if (n < 0) {
        x = 1/x;
        power = x;
        n = (-1)*n;
    }

    if (n )

    for (int j = 1; j < n; j++)
    {
        product = power*x;
        power = product;
    }

    return power;
}
