#include <iostream>
#include <vector>
#include <limits>

//Does not choose next min based on adjacent element in the next row
int minimumTotal(std::vector<std::vector<int>>& triangle)
{
    double min = std::numeric_limits<double>::infinity();
    int totalMin = 0;

    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (triangle[i][j] < min) {
                min = triangle[i][j];
            }
        }
        totalMin += min;
        min = std::numeric_limits<double>::infinity();
    }

    return totalMin;
}

int main()
{
    std::vector<std::vector<int>> triangle = {{-10}};

    std::cout << minimumTotal(triangle);

    return 0;
}
