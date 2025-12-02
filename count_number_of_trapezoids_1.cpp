#include <iostream>
#include <vector>

long long factorial(int n) {
    long long result = 1;

    if (n < 0) { return 0; }
    if (n == 0 || n == 1) {
        return 1;
    }

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

void print(std::vector<int>& sums) {
    for (int i = 0; i < sums.size(); i++) {
        std::cout << sums[i] << " ";
    }
    std::cout << std::endl;
}

long long combination(long long n, long long r) {
    long long result;
    result = factorial(n)/(factorial(r)*factorial(n - r));

    return result;
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

int countTrapezoids(std::vector<std::vector<int>>& points) {
    int initialYVal = points[0][1];
    std::vector<int> numOfPoints;
    int sum = 0, numOfYPoints;
    long long multiplication = 1, combntn, currentVal;

    for (int i = 0; i < points.size();i++) {
        if (points[i][1] == initialYVal) {
            sum += 1;
        } else {
            initialYVal = points[i][1];
            numOfPoints.push_back(sum);
            sum = 1;
        }
    }
    numOfPoints.push_back(sum);

    numOfYPoints = computeDistinctYCoordinates(points);
    for (int i = 0; i < numOfPoints.size(); i++) {
        currentVal = numOfPoints[i];
        combntn = combination(currentVal, numOfYPoints);
        multiplication *= combntn;
    }

    return multiplication;
}

int main()
{
    std::vector<std::vector<int>> points = {{1,0},{2,0},{3,0},{2,2},{3,2}};

    std::cout << countTrapezoids(points);

    return 0;
}
