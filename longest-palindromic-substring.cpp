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

    // Remove duplicates while preserving order
    std::unordered_set<std::string> seen;
    std::vector<std::string> unique;
    for (const auto& str : listOfStrings) {
        if (seen.insert(str).second) {
            unique.push_back(str);
        }
    }

    for (int j = 0; j < unique.size(); j++)
    {
        if(isPalindrome(unique[j]))
            listOfPalindromes.push_back(unique[j]);
    }

    return listOfPalindromes;
}

std::string determineLongestPalindrome(std::vector<std::string> s)
{
    std::string longestPalindrome;

    for (int i = 0; i < s.size()-1; i++)
    {
        if (s[i].length() > s[i+1].length())
            longestPalindrome = s[i];
        else
            longestPalindrome = s[i+1];
    }

    return longestPalindrome;
}

int main()
{
    std::string s = "cbbd";
    std::vector<std::string> substrings = generateUniqueSubstrings(s);

    std::cout << determineLongestPalindrome(substrings);

    return 0;
}
