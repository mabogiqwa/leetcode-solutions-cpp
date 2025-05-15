#include <iostream>
#include <vector>

std::vector<std::string> getLongestSubsequence(std::vector<std::string> wrds, std::vector<int> grps)
{
    std::vector<std::string> longestSubsequence;

    if (grps.size() > 1) {
        for (int i = 0; i < wrds.size()-1; i++)
        {
                if (i == 0) { longestSubsequence.push_back(wrds[i]); }

                if (grps[i] != grps[i+1])
                {
                    if (i == 0) {
                        longestSubsequence.push_back(wrds[i+1]);
                    } else if (i > 0 && longestSubsequence.empty()) {
                        longestSubsequence.push_back(wrds[i]);
                        longestSubsequence.push_back(wrds[i+1]);
                    } else {
                        longestSubsequence.push_back(wrds[i+1]);
                    }
                }
        }
    } else if (grps.size() == 1) {
        longestSubsequence.push_back(wrds[0]);
    }

    return longestSubsequence;
}

int main()
{
    std::vector<std::string> words = {"a", "b", "c", "d", "e", "f", "g", "h"};
    std::vector<int> groups = {1, 1, 1, 2, 1, 2, 1, 2};

    std::vector<std::string> subSequence = getLongestSubsequence(words, groups);

    for (int j = 0; j < subSequence.size(); j++)
    {
        std::cout << subSequence[j] << " ";
    }

    return 0;
}
