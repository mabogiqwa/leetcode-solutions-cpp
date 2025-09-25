#include <iostream>
#include <vector>
#include <limits>

//algorithm not optimal
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
        if (i > 0) {
            v = k + 2;
        } else {
            v = k + 1;
        }

        totalMin += min;
        min = std::numeric_limits<double>::infinity();
    }

    return totalMin;
}

int main()
{
    std::vector<std::vector<int>> triangle = {{0},{8,7}};

    std::cout << minimumTotal(triangle) << std::endl << std::endl;

    triangle = {{4},{3,17},{2,18,13}};

    std::cout << minimumTotal(triangle) << std::endl<< std::endl;

    triangle = {{0},{2, 6}};

    std::cout << minimumTotal(triangle) << std::endl<< std::endl;

    triangle = {{16},{19,0},{17,6,20}};

    std::cout << minimumTotal(triangle) << std::endl<< std::endl;

    triangle = {{13},{7,14},{18,8,0},{5,13,10,8},{4,6,10,3,2},{12,3,11,11,19,8}};

    std::cout << minimumTotal(triangle) << std::endl<< std::endl;

    triangle = {{14},{17,3}};

    std::cout << minimumTotal(triangle) << std::endl<< std::endl;

    triangle = {{2},{17,9},{20,19,11},{18,6,2,1},{7,9,2,7,3}};

    std::cout << minimumTotal(triangle) << std::endl<< std::endl;

    triangle = {{8},{14,20},{11,5,11},{11,6,8,20},{2,19,20,5,17}};

    std::cout << minimumTotal(triangle) << std::endl<< std::endl;

    triangle = {{5},{14,12},{8,20,17}};

    std::cout << minimumTotal(triangle) << std::endl<< std::endl;

    triangle = {{10},{1,7},{1,10,12}};

    std::cout << minimumTotal(triangle) << std::endl<< std::endl;

    return 0;
}
