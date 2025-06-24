#include <iostream>

 int divide(int dividend, int divisor) {
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Use long long to avoid overflow
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long result = 0;

        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        // Apply sign
        return (dividend > 0) == (divisor > 0) ? result : -result;
}

int main()
{
    return 0;
}
