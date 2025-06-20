//Exceeds time limit for large s
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

bool isPalindrome(std::string input)
{
    bool isPalindrome = false;
    int j = input.size() - 1;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == input[j])
        {
            isPalindrome = true;
        } else {
            return false;
        }
        j--;
    }
    return isPalindrome;
}

std::vector<std::string> generateAllSubstrings(const std::string& s) {
    std::unordered_set<std::string> seen;
    std::vector<std::string> result;

    for (int i = 0; i < s.size(); ++i) {
        std::string current = "";
        for (int j = i; j < s.size(); ++j) {
            current += s[j];
            if (seen.insert(current).second) {
                result.push_back(current);
            }
        }
    }
    return result;
}


std::string longestPalindromeFromList(const std::vector<std::string>& list) {
    std::string longest = "";
    for (const auto& str : list) {
        if (isPalindrome(str) && str.size() > longest.size()) {
            longest = str;
        }
    }
    return longest;
}

int main()
{
    std::vector<std::string> testCases = {"babad","cbbd","a","ac","racecar","anana","forgeerksskeegfor","abddcbax","abacdfgdcaba","abcba"};

    for (const auto& test : testCases) {
        std::vector<std::string> list = generateAllSubstrings(test);
        std::string result = longestPalindromeFromList(list);
        std::cout << "Input: " << test << " -> Longest Palindromic Substring: " << result << std::endl;
    }

    return 0;
}
