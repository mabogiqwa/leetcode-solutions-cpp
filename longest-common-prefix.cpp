#include <iostream>
#include <vector>
#include <string>

//not functional
std::string longestCommonPrefix(std::vector<std::string> strs)
{
    std::string longestCPrfx = "";
    std::string firstWord = "";
    int iterations = 0;
    int length, lengthOfPrefix = 0;
    std::string nextString;
    bool longestPrefixExists = false;

    firstWord = strs[0];
    length = strs[0].length();
    while (iterations < strs.size())
    {
        nextString = strs[iterations+1].length();
        //compares the first and second words and captures the longest prefix
        if (index == 0) {
            for (int i = 0; i < strs[iterations+1].length(); i++) {
                if (firstWord[0] != nextString[0]) {
                    return "";
                }
                if (firstWord[i] == nextString[i]) {
                    longestPrefixExists = true;
                    longestCPrfx += (firstWord[i]);
                }
            }
        } else {
            if (!longestPrefixExists) {
                return "";
            }
            //This for loop evaluates whether the string after the second
            //string contain the prefix substring
            for (int i = 0; i < longestCPrfx.length(); i++) {
                if (longestCPrfx[i] == strs[iterations][i]) {
                    lengthOfPrefix++;
                }
            }
            if (lengthOfPrefix != longestCPrfx.length()) {
                return "";
                longestPrefixExists = false;
            }
        }
        iterations++;
    }

    if (longestPrefixExists) {
        return longestCPrfx;
    } else {
        return "";
    }
}

int main()
{
    std::vector<std::string> strs = {"flower","flow","flight"};

    return 0;
}
