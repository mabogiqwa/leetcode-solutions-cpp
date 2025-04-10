#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

void print(int* nums, int length)
{
   for (int i = 0; i < length; ++i)
   {
       std::cout << nums[i] << " ";
   }
   std::cout << std::endl;
}

int main()
{
    int nums[] = {5,2,5,4,5};
    int length = sizeof(nums) / sizeof(nums[0]);
    int index, secondIndex, lengthOfV, indexS;
    int k = 2, h, firstGValue, result = 0;
    bool validInt = false;
    std::vector<int> indexStorage;

    std::cout << "Enter a value for h: ";
    std::cin >> h;

   do
   {
       index = 0;
       secondIndex = 0;
       while(index < length)
       {
        if (nums[index] > k) { firstGValue = nums[index]; }

        while (secondIndex < length)
        {
           if (nums[secondIndex] > k)
           {
              if (nums[secondIndex] == firstGValue) {
                  validInt = true;
                  indexStorage.push_back(secondIndex);
              } else {
                  validInt = false;
                  break;
              }
           } else {
               validInt = false;
           }
           secondIndex = secondIndex + 1;
        }

        index = index + 1;
       }

       indexS = 0;
       lengthOfV = indexStorage.size();
       if (validInt) {

          for (int i = 0; i < length; i++)
          {
              if (i == indexStorage[indexS])
              {
                  nums[i] = h;
                  indexS++;
              }
          }

          result++;
          std::cout << "Output: " << result << std::endl;
          indexStorage.clear();
          print(nums, length);
          std::cout << "Enter another value for h: ";
          std::cin >> h;
       } else {
           result = -1;
           std::cout << "Output: " << result << std::endl;
       }

    } while (result != -1);

    return 0;
}
