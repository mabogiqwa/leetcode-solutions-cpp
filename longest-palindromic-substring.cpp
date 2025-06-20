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

std::vector<std::string> generateUniqueSubstrings(const std::string& s) {
    std::vector<std::string> listOfStrings;
    std::vector<std::string> listOfPalindromes;
    std::string someString;
    int k = 1;
    int iter = 0;
    int size2 = 1;

    while (s[iter] != s[s.length() - 1]) {
        for (int i = 0; i < s.length() - 1; i++) {
            someString += s[iter];
            for (int j = k; j <= size2; j++) {
                if (j < s.length()) {
                    someString += s[j];
                }
            }
            listOfStrings.push_back(someString);
            size2++;
            someString = "";
        }
        iter++;
        size2 = iter + 1;
        k++;
    }

    /*
    for (int i = 0; i < listOfStrings.size();i++)
    {
        std::cout << listOfStrings[i] << " ";
    }
    */

    // Remove duplicates while preserving order
    std::unordered_set<std::string> seen;
    std::vector<std::string> unique;
    for (const auto& str : listOfStrings) {
        if (seen.insert(str).second) {
            unique.push_back(str);
        }
    }

    /*
    for (int i = 0; i < unique.size();i++)
    {
        std::cout << unique[i] << " ";
    }
    */

    for (int j = 0; j < unique.size(); j++)
    {
        if(isPalindrome(unique[j]))
            listOfPalindromes.push_back(unique[j]);
    }

    /*
    for (int i = 0; i < listOfPalindromes.size();i++)
    {
        std::cout << listOfPalindromes[i] << " ";
    }
    */

    return listOfPalindromes;
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
        std::vector<std::string> list = generateUniqueSubstrings(test);
        std::string result = longestPalindromeFromList(list);
        std::cout << "Input: " << test << " -> Longest Palindromic Substring: " << result << std::endl;
    }

    return 0;
}
