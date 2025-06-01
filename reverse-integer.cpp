#include <iostream>

int reverse(int x)
{
    std::string stringX = std::to_string(x);
    std::string reversedX = "";
    long long reversedX2;
    int lastIndex = stringX.length() - 1;

    while (lastIndex >= 0)
    {
        reversedX += stringX[lastIndex];
        lastIndex--;
    }

    reversedX2 = std::stoll(reversedX);

    if (reversedX2 < INT_MIN || reversedX2 > INT_MAX) {
            return 0;
    }

    if (x < 0) {
        return int(reversedX2)*(-1);
    } else {
        return int(reversedX2);
    }
}

int main()
{
    std::cout << reverse(-555);

    return 0;
}
