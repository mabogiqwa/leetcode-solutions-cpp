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
    int index = 0, secondIndex = 0;
    int length = sizeof(nums) / sizeof(nums[0]);
    int k = 4;
    int firstGValue, result = -1;
    bool validInt = false;
    std::vector<int> indexStorage;

   do
   {
       while(index < length)
       {
        if (nums[index] > k)
        {
            firstGValue = nums[index];
            //std::cout <<firstGValue << std::endl;
        }

        //Run a nested while loop that will check whether each value greater than
        //k is equal to firstGValue
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
           }
           secondIndex = secondIndex + 1;
        }
        index = index + 1;
       }
       //std::cout << validInt << std::endl;

       int lengthOfV = indexStorage.size();
       int indexS = 0;
       if (validInt) {
          for (int i = 0; i < length; i++)
          {
              if (i == indexStorage[indexS])
              {
                  nums[i] = k;
                  indexS++;
              }
          }
          indexStorage.clear();
          print(nums, length);
          std::cout << "Enter another value for k: ";
          std::cin >> k;
       } else {
           result = -1;
           std::cout << "Invalid integer -1" << std::endl;
       }

    } while (result != -1);
    return 0;
}
