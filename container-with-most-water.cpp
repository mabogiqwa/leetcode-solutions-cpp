#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>

int findLargest(const std::vector<int>& height) {
    int alpha = std::numeric_limits<int>::min();

    for (int i = 0; i < height.size(); i++) {
        if (height[i] > alpha)
            alpha = height[i];
    }

    return alpha;
}

int findLowest(const std::vector<int>& height) {
    int beta = std::numeric_limits<int>::max();

    for (int i = 0; i < height.size(); i++) {
        if (height[i] < beta)
            beta = height[i];
    }

    return beta;
}

int returnIndex(std::vector<int>& h, int val) {
    int index;
    for (int i = 0; i < h.size(); i++) {
        if (val == h[i]) {
            return i;
        }
    }
    return -1;
}

int maxArea(std::vector<int>& height)
{
    std::vector<int> largestVals;
    std::vector<int> cpy = height;
    int largest, width, area;

    for (int i = 0; i < 2; i++) {
        largest = findLargest(cpy);
        largestVals.push_back(largest);
        cpy.erase(std::remove(cpy.begin(), cpy.end(), largest), cpy.end());
    }

    width = abs(returnIndex(height,largestVals[0])-returnIndex(height,largestVals[1]));

    area = width * findLowest(largestVals);

    return area;
}

int main()
{
    std::vector<int> h = {1,8,6,2,5,4,8,3,7};

    std::cout << maxArea(h);

    return 0;
}
