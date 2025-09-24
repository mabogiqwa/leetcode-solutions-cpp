#include <iostream>
#include <cmath>
#include <string>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    int sum = 0;
    std::string stringSum;
    std::vector<int> output;

    int j = digits.size() - 1;
    for (int i = 0; i < digits.size(); i++) {
        sum += (digits[i] *pow(10, j));
        j--;
    }
    sum += 1;
    stringSum = std::to_string(sum);

    for (int j = 0; j < stringSum.length(); j++) {
        output.push_back(stringSum[j] - '0');
    }

    return output;
}

void print(std::vector<int> dgts) {
    for (int i = 0; i < dgts.size(); i++) {
        std::cout << dgts[i] << " ";
    }
}

int main()
{
    std::vector<int> digits = {9};

    print(plusOne(digits));

    return 0;
}
