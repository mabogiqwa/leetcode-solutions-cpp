#include <iostream>
#include <cmath>
#include <vector>

double triangle_area(const std::vector<int>& a,
                     const std::vector<int>& b,
                     const std::vector<int>& c) {
    int x1 = a[0], y1 = a[1];
    int x2 = b[0], y2 = b[1];
    int x3 = c[0], y3 = c[1];
    return std::abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;
}

int main() {
    std::vector<std::vector<int>> points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    double max_area = 0;
    std::vector<std::vector<int>> best_triangle;

    int n = points.size();
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            for(int k=j+1; k<n; ++k) {
                double area = triangle_area(points[i], points[j], points[k]);
                if(area > max_area) {
                    max_area = area;
                    best_triangle = {points[i], points[j], points[k]};
                }
            }
        }
    }

    std::cout << "Largest area: " << max_area << std::endl;
    std::cout << "Triangle points: ";
    for(auto &p : best_triangle)
        std::cout << "(" << p[0] << "," << p[1] << ") ";
    std::cout << std::endl;

    return 0;
}
