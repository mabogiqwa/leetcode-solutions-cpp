#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

double findMedianSortedArrays(std::vector<int> nums1, std::vector<int> nums2)
{
    double medianIndex, lastIndex, firstElem, median;

    nums1.insert(nums1.end(), nums2.begin(), nums2.end());

    lastIndex = nums1.size() - 1;

    std::sort(nums1.begin(), nums1.end());

    if ((nums1.size() % 2) != 0) {
        medianIndex = floor((0 + lastIndex)/2.0);

        return double(nums1[medianIndex]);
    }
    if ((nums1.size() % 2) == 0) {
        firstElem = floor((0 + lastIndex)/2.0);

        median = (nums1[firstElem] + nums1[firstElem+1])/2.0;

        return median;
    }

    return 0;
}

int main()
{
    std::vector<int> nums1 = {1,2};
    std::vector<int> nums2 =  {3,4};

    std::cout << findMedianSortedArrays(nums1, nums2);

    return 0;
}
