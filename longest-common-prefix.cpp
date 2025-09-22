#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string> strs)
{
    std::string longestCPrfx = "";
    std::string firstWord = "";
    int iterations = 0;
    int length;
    std::string nextString;
    bool longestPrefixExists = false;

    firstWord = strs[0];
    length = strs[0].length();
    while (index < strs.size())
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
            for (int i = 0; i < longestCPrfx.length(); i++) {
                if (longestCPrfx[i] == strs[iterations][i]) {

                }
            }
        }
        iterations++;
    }
}

int main()
{
    std::vector<std::string> strs = {"flower","flow","flight"};

    return 0;
}

//0 0 1 0 2 0
