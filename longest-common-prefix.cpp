#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string> strs)
{
    std::string longestCPrfx = "";
    int index = 0;

    while (index < lengthOfLongest)
    {

        index++;
    }
}

int determineLongestString(std::vector<std::string> strs)
{
    int lengthOfLongest;

    for (int i = 0; i < strs.size()-1; i++)
    {
        if (strs[i].length() > strs[i+1].length())
            lengthOfLongest = strs[i].length();
        else
            lengthOfLongest = strs[i+1].length();
    }

    return lengthOfLongest;
}

int main()
{
    std::vector<std::string> strs = {"flower","flow","flight"};

    return 0;
}

//0 0 1 0 2 0
