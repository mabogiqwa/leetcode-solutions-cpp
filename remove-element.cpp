#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val)
{
    int k = nums.size();

    for (int index = 0; index < nums.size(); index++)
    {
        if (nums[index] == val) {
            if ((nums[index] == nums[index+1]) && (index < nums.size() - 1)) {
                nums.erase(nums.begin() + index);
                k--;
            }
            nums.erase(nums.begin() + index);
            k--;
        }
    }

    return k;
}

int main()
{
    std::vector<int> nums = {0,1,2,2,3,0,4,2};

    std::cout << removeElement(nums,2) << std::endl << std::endl;

    for (int i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i] << " ";
    }

    return 0;
}
