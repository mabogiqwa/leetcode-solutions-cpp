#include <iostream>
#include <cmath>

int mySqrt(int x1)
{
    return std::floor(pow(x1, 1.0/2.0));
}

int main()
{
    int x = 8;

    std::cout << mySqrt(x);

    return 0;
}
