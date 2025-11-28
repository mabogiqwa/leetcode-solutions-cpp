//Doesn't work on various cases
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
    for (int i = 0; i < h.size(); i++) {
        std::cout << h[i] << " ";
    }
    std::cout << std::endl;
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

    //print(largestVals);
    if (height[height.size()-1] == 1) {
        width = abs(returnIndex(height,largestVals[0])-(height.size()-2));
        area = width * height[height.size()-2];
        return area;
    } else if (height[0] == 1) {
        width = abs(returnIndex(height,largestVals[0])- 1);
        area = width * height[1];
        return area;
    } else {
        width = abs(returnIndex(height,largestVals[0])-(height.size()-1));
    }
    if (largestVals[0] > largestVals[1]) {
        if (height.size() == 3) { //For cases in which there are 3 elements
            width = abs(returnIndex(height,largestVals[1])-(height.size()-1));
        }
        area = width * height[height.size()-1];
    } else {
        area = width * largestVals[0];
    }

    return area;
}

int main()
{
    std::vector<int> h = {1,2,3,4,5};
    std::cout << "Output: " << maxArea(h) << std::endl;

    h = {1,1};
    std::cout << "Output: " << maxArea(h) << std::endl;

    h = {3,3};
    std::cout << "Output: " << maxArea(h) << std::endl;

    h = {1,3,2};
    std::cout << "Output: " << maxArea(h) << std::endl;

    h = {1,8,6,2,5,4,8,3,7};
    std::cout << "Output: " << maxArea(h) << std::endl;

    h = {1,2,3,4,5};
    std::cout << "Output: " << maxArea(h) << std::endl;

    h = {5,4,3,2,1};
    std::cout << "Output: " << maxArea(h) << std::endl;

    h = {2,100,2};
    std::cout << "Output: " << maxArea(h) << std::endl;

    h = {2,1,1,1,2};
    std::cout << "Output: " << maxArea(h) << std::endl;

    h = {7,1,7,1,7};
    std::cout << "Output: " << maxArea(h) << std::endl;

    h = {4,3,2,1,4};
    std::cout << "Output: " << maxArea(h) << std::endl;

    return 0;
}
