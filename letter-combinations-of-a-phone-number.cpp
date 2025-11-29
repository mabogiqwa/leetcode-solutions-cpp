#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> letterCombinations(std::string digits)
{
    std::vector<std::vector<std::string>> numbers = {{"a","b","c"},
                                     {"d","e","f"},
                                     {"g","h","i"},
                                     {"j","k","l"},
                                     {"m","n","o"},
                                     {"p","q","r","s"},
                                     {"t","u","v"},
                                     {"w","x","y","z"}};
    if (digits.length() == 1) {
        if (digits == "2") { return numbers[0]; }
        if (digits == "3") { return numbers[1]; }
        if (digits == "4") { return numbers[2]; }
        if (digits == "5") { return numbers[3]; }
        if (digits == "6") { return numbers[4]; }
        if (digits == "7") { return numbers[5]; }
        if (digits == "8") { return numbers[6]; }
        if (digits == "9") { return numbers[7]; }
    }

    return {{}};
}

void print(std::vector<std::string> letterComb) {
    for (int i = 0; i < letterComb.size(); i++) {
        std::cout << letterComb[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::string digits = "9";
    std::vector<std::string> lC;

    lC = letterCombinations(digits);

    print(lC);

    return 0;
}
//There could be 1 up till 4 digits
//Case 1: 1
//Case 2: 12
//Case 3: 123
//Case 4: 1234
