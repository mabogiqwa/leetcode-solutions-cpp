#include <iostream>
#include <string>
#include <vector>

void print(std::vector<std::vector<std::string>>& v) {
    //std::cout << "This was called" << std::endl;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::string> distribute(std::vector<std::vector<std::string>> v)
{
    std::vector<std::string> output;
    std::string s = "";

    if (v.size() == 2) {
        std::vector<std::string> firstRow = v[0];
        std::vector<std::string> secondRow = v[1];

        for (int i = 0; i < firstRow.size(); i++) {
            for (int j = 0; j < secondRow.size(); j++) {
                s += firstRow[i] + secondRow[j];
                output.push_back(s);
                s = "";
            }
        }
    }
    if (v.size() == 3) {
        std::vector<std::string> firstRow = v[0];
        std::vector<std::string> secondRow = v[1];
        std::vector<std::string> thirdRow = v[2];

        for (int i = 0; i < firstRow.size(); i++) {
            for (int j = 0; j < secondRow.size(); j++) {
                for (int k = 0; k < thirdRow.size(); k++) {
                    s += firstRow[i] + secondRow[j] + thirdRow[k];
                    output.push_back(s);
                    s = "";
                }
            }
        }
    }

    if (v.size() == 4) {
        std::vector<std::string> firstRow = v[0];
        std::vector<std::string> secondRow = v[1];
        std::vector<std::string> thirdRow = v[2];
        std::vector<std::string> fourthRow = v[3];

        //O(n^4) - hectic
        for (int i = 0; i < firstRow.size(); i++) {
            for (int j = 0; j < secondRow.size(); j++) {
                for (int k = 0; k < thirdRow.size(); k++) {
                    for (int v = 0; v < fourthRow.size(); v++) {
                        s += firstRow[i]+secondRow[j]+thirdRow[k]+fourthRow[v];
                        output.push_back(s);
                        s = "";
                    }
                }
            }
        }
    }

    return output;
}

void print(std::vector<std::string> letterComb) {
    for (int i = 0; i < letterComb.size(); i++) {
        std::cout << letterComb[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<std::string> letterCombinations(std::string digits)
{
    int val;
    std::vector<std::vector<std::string>> combinationPair;
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
    if (digits.length() == 2) {
        for (int i = 0; i < 2; i++) {
            val = digits[i] - '0';
            if (val == 2) { combinationPair.push_back(numbers[0]); }
            if (val == 3) { combinationPair.push_back(numbers[1]); }
            if (val == 4) { combinationPair.push_back(numbers[2]); }
            if (val == 5) { combinationPair.push_back(numbers[3]); }
            if (val == 6) { combinationPair.push_back(numbers[4]); }
            if (val == 7) { combinationPair.push_back(numbers[5]); }
            if (val == 8) { combinationPair.push_back(numbers[6]); }
            if (val == 9) { combinationPair.push_back(numbers[7]); }
        }
    }
    if (digits.length() == 3) {
        for (int i = 0; i < 3; i++) {
            val = digits[i] - '0';
            if (val == 2) { combinationPair.push_back(numbers[0]); }
            if (val == 3) { combinationPair.push_back(numbers[1]); }
            if (val == 4) { combinationPair.push_back(numbers[2]); }
            if (val == 5) { combinationPair.push_back(numbers[3]); }
            if (val == 6) { combinationPair.push_back(numbers[4]); }
            if (val == 7) { combinationPair.push_back(numbers[5]); }
            if (val == 8) { combinationPair.push_back(numbers[6]); }
            if (val == 9) { combinationPair.push_back(numbers[7]); }
        }
    }
    if (digits.length() == 4) {
        for (int i = 0; i < 4; i++) {
            val = digits[i] - '0';
            if (val == 2) { combinationPair.push_back(numbers[0]); }
            if (val == 3) { combinationPair.push_back(numbers[1]); }
            if (val == 4) { combinationPair.push_back(numbers[2]); }
            if (val == 5) { combinationPair.push_back(numbers[3]); }
            if (val == 6) { combinationPair.push_back(numbers[4]); }
            if (val == 7) { combinationPair.push_back(numbers[5]); }
            if (val == 8) { combinationPair.push_back(numbers[6]); }
            if (val == 9) { combinationPair.push_back(numbers[7]); }
        }
    }


    return distribute(combinationPair);
}

int main()
{
    std::string digits = "97";

    print(letterCombinations(digits));
    std::cout << std::endl;
    digits = "2";
    print(letterCombinations(digits));
    std::cout << std::endl;
    digits = "23";
    print(letterCombinations(digits));
    std::cout << std::endl;
    digits = "27";
    print(letterCombinations(digits));
    std::cout << std::endl;
    digits = "72";
    print(letterCombinations(digits));
    std::cout << std::endl;
    digits = "234";
    print(letterCombinations(digits));
    std::cout << std::endl;
    digits = "777";
    print(letterCombinations(digits));
    std::cout << std::endl;
    digits = "2345";
    print(letterCombinations(digits));
    std::cout << std::endl;
    digits = "7777";
    print(letterCombinations(digits));

    return 0;
}

