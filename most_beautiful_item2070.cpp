//Want to keep the streak
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const int SIZE = 6;

class Item
{
public:
    Item(int p, int b)
    {
        price = p;
        beauty = b;
    }
    int getPrice()
    {
        return price;
    }
    int getBeauty()
    {
        return beauty;
    }
private:
    int price;
    int beauty;
};

void print(std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
}

int binarySearch(int price, const std::vector<int> q)
{
    int first = 0, difference, smallest;
    int last = q.size() - 1;
    int index = 0, approximateValue;
    bool found = false;

    int iteration = 0;
    while (first <= last)
    {
        int mid = (first + last)/2;
        if (q[mid] == price) {
            return q[mid];
        }
        else if (q[mid] > price)
            last = mid - 1;
        else
            first = mid + 1;

        //When the cases are reduced to about 7, we will choose
        //the element in queries which has the smallest difference
        if (abs(first - last) < 6) {
            std::cout << "Iteration: " << iteration << std::endl;
            std::cout << first << " " << last << std::endl;
            difference = abs(q[first] - price);
            smallest = difference;
            approximateValue = q[first];
            for (int i = first; i <= last; i++)
            {
                difference = abs(q[i] - last);
                if (difference < smallest) {
                    smallest = difference;
                    approximateValue = q[i];
                }
            }
            return approximateValue;
        }
        iteration += 1;
    }
}


int main()
{
    std::vector<Item> items;
    std::vector<int> queries = {1,2,3,4,5,6}; //6,11,13,34,50
    int prices[5];
    int price, closestQuery, q;
    std::vector<int> answer;

    std::sort(queries.begin(), queries.end());
    items.push_back(Item(1,2));
    items.push_back(Item(3,2));
    items.push_back(Item(2,4));
    items.push_back(Item(5,6));
    items.push_back(Item(3,5));

    for (int i = 0; i < 5; i++)
    {
        prices[i] = items[i].getPrice();
    }
    std::sort(prices, prices + 5);

    //std::cout << binarySearch(1, queries);

    for (int i = 0; i < items.size(); i++)
    {
        closestQuery = binarySearch(items[i].getPrice(), queries);

        //std::cout << closestQuery << " ";
    }

    return 0;
}
