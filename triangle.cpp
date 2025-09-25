#include <iostream>
#include <vector>
#include <limits>

int minimumTotal(std::vector<std::vector<int>>& triangle)
{
    int min = std::numeric_limits<int>::infinity();

    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {

        }
    }
}

int main()
{
    std::vector<std::vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};

    std::cout << triangle.size();

    return 0;
}
