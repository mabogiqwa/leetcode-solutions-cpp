#include <iostream>
#include <vector>
#include <string>

//not functional
std::string longestCommonPrefix(std::vector<std::string> strs)
{
    std::string longestCPrfx = "";
    std::string longestCPrfx2 = ""; //stores the shorter prefix option
    std::string firstWord = "", nextString;
    int iterations = 0;
    int length;
    int nextStringLength;
    bool longestPrefixExists = false;

    firstWord = strs[0];
    length = strs[0].length();
    nextStringLength = strs[iterations+1].length();
    nextString = strs[iterations+1];

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
        }
        else {
            if (!longestPrefixExists) {
                return "";
            }
            //This for loop evaluates whether the string after the second
            //string contain the prefix substring
            if ((iterations + 1) < (strs.size())) { //ensures that we do not access unassigned index value
                nextString = strs[iterations+1];
            }

            //std::cout << nextString << std::endl;
            for (int i = 0; i < longestCPrfx.length(); i++) {
                if (longestCPrfx[i] == nextString[i]) {
                    longestCPrfx2 += longestCPrfx[i];
                }
            }
            longestCPrfx = longestCPrfx2;
            std::cout << longestCPrfx << std::endl;
        }
        iterations++;
    }

    return longestCPrfx;
}

int main()
{
    std::vector<std::string> strs = {"flower","flow","flight"};

    longestCommonPrefix(strs);

    return 0;
}
