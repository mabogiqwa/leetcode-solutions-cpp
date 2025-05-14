#include <iostream>
#include <vector>

std::vector<int> get_two_sum(std::vector<int> n, int target);

int main()
{
    std::vector<int> nums = {2,7,11,15};
    std::vector<int> sumIndices;
    int target = 26;

    sumIndices = get_two_sum(nums, target);

    for (int i = 0; i < sumIndices.size(); i++)
    {
        std::cout << sumIndices[i] << " ";
    }

    return 0;
}

std::vector<int> get_two_sum(std::vector<int> n, int target)
{
    int staticVal, sum, j;

    j = 1;
    for (int i = 0; i < n.size(); i++)
    {
        staticVal = n[i];
        for (int k = j; k < n.size(); k++)
        {
            sum = staticVal + n[j];
            if (sum == target)
            {
                return {i, j};
            }
        }
        j++;
    }

    return {};
}
