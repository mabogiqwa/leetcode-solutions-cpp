//Incomplete solution
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    int firstNumIndex = 0, secondNumIndex = 1;
    int pseudoSecondIndex = secondNumIndex;
    int k = 2, index = 0;
    int twoSum = 0, threeSum = 0;
    int sentinel;
    std::vector<std::vector<int>> threeSums;

    while (index < nums.size())
    {
        while (sentinel != nums[nums.size()-2])
        {
            for (int j = k; j < nums.size(); j++)
            {
                twoSum += (nums[firstNumIndex] + nums[secondNumIndex]);
                threeSum += (twoSum + nums[j]);
                //std::cout  << nums[firstNumIndex] << " " << nums[secondNumIndex] << " " << nums[j] << std::endl;

                if (threeSum == 0)
                {
                    threeSums.push_back({nums[firstNumIndex],nums[secondNumIndex],nums[j]});
                }
                twoSum = 0;
                threeSum = 0;
            }
            secondNumIndex++;
            k++;
            if (secondNumIndex < nums.size())
            {
                sentinel = nums[secondNumIndex];
            } else {
                break;
            }

        }
        firstNumIndex++;
        secondNumIndex = pseudoSecondIndex + 1;
        pseudoSecondIndex += 1;
        index++;
    }

    for (auto& sums : threeSums) {
        std::sort(threeSums.begin(), threeSums.end());
    }

    std::sort(threeSums.begin(), threeSums.end());

    auto last = std::unique(threeSums.begin(), threeSums.end());
    threeSums.erase(last, threeSums.end());

    return threeSums;
}

int main()
{
    std::vector<int> nums = {0,0,0};

    std::vector<std::vector<int>> sums3 = threeSum(nums);

    for (const auto& num : sums3) {
        for (const auto& val : num) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
