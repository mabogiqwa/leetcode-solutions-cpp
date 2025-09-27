#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

void print(std::vector<double> areas) {
    for (int i = 0; i < areas.size(); i++) {
        std::cout << areas[i] << " ";
    }
    std::cout << std::endl;
}

int largest(int i, int j, int k) {
    double largest = -std::numeric_limits<double>::infinity();

    if (i > largest) {
        largest = i;
        if (j > largest) {
            largest = j;
            if (k > largest) {
                largest = k;
            }
        }
    }

    return int(largest);
}

int smallest(int i, int j, int k) {
    double smallest = std::numeric_limits<double>::infinity();

    if (i < smallest) {
        smallest = i;
        if (j < smallest) {
            smallest = j;
            if (k < smallest) {
                smallest = k;
            }
        }
    }

    return int(smallest);
}

//the triangle doesn't have to begin at the origin
double largestTriangleArea(std::vector<std::vector<int>> points) {
    std::vector<std::vector<std::vector<int>>> triples; //going to store all the possible combinations of ordered sets of 3 pairs
}

int main() {

  std::vector<std::vector<int>> points = {{0,0},{0,1},{1,0},{0,2},{2,0}};

  std::cout << largestTriangleArea(points);

  return 0;
}
