#include <iostream>
#include <vector>
#include <string>

//not functional
std::string longestCommonPrefix(std::vector<std::string> strs)
{
    std::string longestCPrfx = "";
    std::string firstWord = "", nextString;
    int iterations = 0;
    int length, lengthOfPrefix = 0;
    int nextStringLength;
    bool longestPrefixExists = false;

    firstWord = strs[0];
    length = strs[0].length();
    nextStringLength = strs[iterations+1].length();
    nextString = strs[iterations+1];
    std::cout << nextString << std::endl;

    while (iterations < strs.size())
    {
        //compares the first and second words and captures the longest prefix
        if (iterations == 0) {
            for (int i = 0; i < nextStringLength; i++) { //also fix this
                if (firstWord[0] != nextString[0]) { //checks if the first character match or not
                    return "";
                }
                if (firstWord[i] == nextString[i]) {
                    longestPrefixExists = true;
                    longestCPrfx += (firstWord[i]);
                }
            }
            std::cout << longestCPrfx << std::endl;
        }
        /*
        else {
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
        */
        iterations++;
    }

    /*
    if (longestPrefixExists) {
        return longestCPrfx;
    } else {
        return "";
    }
    */
    return "";
}

int main()
{
    std::vector<std::string> strs = {"flower","flow","flight"};

    longestCommonPrefix(strs);

    return 0;
}
