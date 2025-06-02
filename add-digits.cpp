#include <iostream>
#include <string>
#include <vector>

int addDigits(int num) {
    std::string stringNum = std::to_string(num);
    int sum = 10;

    while (std::to_string(sum).length() != 1)
    {
        sum = 0;
        for (int j = 0; j < stringNum.length(); j++) {
            sum += (stringNum[j] - '0');
        }
        stringNum = std::to_string(sum);
    }

    return sum;
}

int main()
{
    std::cout << addDigits(0);
    return 0;
}
