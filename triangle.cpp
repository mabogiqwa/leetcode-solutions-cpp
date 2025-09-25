#include <iostream>
#include <vector>
#include <limits>

//Does not choose next min based on adjacent element in the next row
int minimumTotal(std::vector<std::vector<int>>& triangle)
{
    double min = std::numeric_limits<double>::infinity();
    int totalMin = 0;

    int k = 0;
    int v = k + 1;
    int currentIndex = k;
    for (int i = 0; i < triangle.size(); i++) {
        for (int j = k; j < v; j++) {
            if (triangle[i][j] < min) {
                min = triangle[i][j];
                k = j;
            }
        }
        if (k == 0)
            v = k + 2;
        else
            v = k + 1;

        totalMin += min;
        min = std::numeric_limits<double>::infinity();
    }

    return totalMin;
}

int main()
{
    std::vector<std::vector<int>> triangle = {{2},{3,4},{6,1,100}};

    std::cout << minimumTotal(triangle);

    return 0;
}
