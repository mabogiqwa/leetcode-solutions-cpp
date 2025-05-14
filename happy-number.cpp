#include <iostream>
#include <cmath>

bool isHappy(int num)
{
    std::string stringNum;
    int digit, sumOfSquares = 10;
    int index = 0;

    stringNum = std::to_string(num);

    while (sumOfSquares != 1)
    {
        sumOfSquares = 0;

        for (int i = 0; i < stringNum.size(); i++)
        {
            digit = std::stoi(std::string(1, stringNum[i]));
            sumOfSquares += pow(digit, 2.0);
        }
        stringNum = std::to_string(sumOfSquares);

        index++;

        if (index > 30)
            break;
    }

    if (sumOfSquares == 1)
        return true;
    else
        return false;
}

int main()
{
    int n = 19;

    std::cout << isHappy(n);

    return 0;
}
