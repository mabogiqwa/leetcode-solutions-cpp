//Tested on one case
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

void print(std::vector<int>& h) {

}

int maxArea(std::vector<int>& height)
{
    std::vector<int> largestVals;
    std::vector<int> cpy = height;
    int largest, width, area;

    if (height.size() == 2) {
        return height[0];
    }

    for (int i = 0; i < 2; i++) {
        largest = findLargest(cpy);
        largestVals.push_back(largest);
        cpy.erase(std::remove(cpy.begin(), cpy.end(), largest), cpy.end());
    }

    width = abs(returnIndex(height,largestVals[0])-(height.size()-1));
    std::cout << width << std::endl;
    if (largestVals[0] > largestVals[1]) {
        area = width * height[height.size()-1];
    } else {
        area = width * largestVals[0];
    }

    return area;
}

int main()
{
    std::vector<int> h = {2,100,2};

    std::cout << maxArea(h);

    return 0;
}
