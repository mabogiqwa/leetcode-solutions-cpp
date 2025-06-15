#include <iostream>
#include <vector>

std::vector<std::string> getLongestSubsequence(std::vector<std::string>& wrds, std::vector<int>& grps)
{
    std::vector<std::string> longestSubsequence;
    int hDistance = 0;

    if(!wrds.empty()) { longestSubsequence.push_back(wrds[0]); }
    else { return {}; }

    int i = 0;
    while (i < (wrds.size() - 1))
    {
        std::cout << i << std::endl;
        if (grps[i] != grps[i+1])
        {
            if (i < (wrds.size() - 2))
            if (grps[i+1] == grps[i+2])
            {
                i++;
                while (grps[i] == grps[i+1])
                {
                    i++;
                }
                longestSubsequence.push_back(wrds[i]);
            } else {
                longestSubsequence.push_back(wrds[i]);
            }
        } else {
            i++;
        }
    }

    return longestSubsequence;
}

int main()
{
    std::vector<std::string> words = {"d","w","a","e","s"};
    std::vector<int> groups = {0,1,1,1,0};

    std::vector<std::string> subSequence = getLongestSubsequence(words, groups);

    for (int j = 0; j < subSequence.size(); j++)
    {
        std::cout << subSequence[j] << " ";
    }

    return 0;
}
