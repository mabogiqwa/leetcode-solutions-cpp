#include <iostream>
#include <vector>
#include <limits>

int findLargest(std::vector<int>& height) {
    int alpha = std::numeric_limits<int>::min();

    for (int i = 0; i < height.size(); i++) {
        if (height[i] > alpha)
            alpha = height[i];
    }

    return alpha;
}

int maxArea(std::vector<int>& height)
{
    for (int i = 1; i < height.size(); i++) {

    }
}

int main()
{
    std::vector<int> h = {1,8,6,2,5,4,8,3,7};

    std::cout << findLargest(h);

    return 0;
}
