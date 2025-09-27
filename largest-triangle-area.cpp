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
    std::vector<double> areas;
    double area, breadth, height;

    if (points.size() >= 3) {
        int k, l;

        for (int i = 0; i < points.size() - 2; i++) {
            k = i+1;
            l = i+2;
            //height = points[i][1] + points[k][1] + points[l][1];
            //breadth = points[i][0] + points[k][0] + points[l][0];

            area = (1.0/2.0)*breadth*height;
            areas.push_back(area);
        }
    } else {
        return -1;
    }
    print(areas);

    auto max = std::max_element(areas.begin(), areas.end());
    double largestArea = *max;

    return largestArea;
}

int main() {

  std::vector<std::vector<int>> points = {{0,0},{0,1},{1,0},{0,2},{2,0}};

  //std::cout << "Output: " << largestTriangleArea(points);
  std::cout << largest(10,19,7) << std::endl;
  std::cout << smallest(14,5,19);

  return 0;
}
