#include <iostream>
#include <vector>

int countTrapezoids(std::vector<std::vector<int>>& points) {
    return 0;
}

int computeDistinctYCoordinates(std::vector<std::vector<int>>& points) {
    int total = 0;
    int initialYVal = points[0][1];
    for (int i = 0; i < points.size(); i++) {
        if (points[i][1] != initialYVal) {
            total += 1;
        }
    }

    return total;
}

int main()
{
    std::vector<std::vector<int>> points = {{0,0},{1,0},{0,1},{2,1}};

    std::cout << computeDistinctYCoordinates(points) << std::endl;

    return 0;
}
