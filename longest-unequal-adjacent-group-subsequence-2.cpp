#include <iostream>
#include <vector>

std::vector<std::string> getWordsInLongestSubsequence(std::vector<std::string>& wrds, std::vector<int>& grps)
{
    std::vector<std::string> longestSubsequence;

    if (grps.size() > 1) {
        for (int i = 0; i < wrds.size() - 1; i++)
        {

        }
    }
    else if (grps.size() == 1) {
        longestSubsequence.push_back(wrds[0]);
    }

    return longestSubsequence;
}

int main()
{
    return 0;
}
