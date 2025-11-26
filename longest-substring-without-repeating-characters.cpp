//Suboptimal: Processes subsequences
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

std::string removeDuplicates(const std::string s)
{
    std::unordered_set<char> seen;
    std::string result;
    for (char c : s) {
        if (!seen.count(c)) {
            seen.insert(c);
            result += c;
        }
    }
    return result;
}

int lengthOfLongestSubstring(std::string s) {

   std::string stringWithoutRep = "";
   bool containsDuplicate = false;

   if (s.empty()) {
      return 0;
   }

   if (removeDuplicates(s).length() == 1) {
       return removeDuplicates(s).length();
   } else {
       for (int i = 0; i < s.size(); i++) {
           if (s[i] != s[i+1]) {
               stringWithoutRep += s[i];
           } else {
               if ((i+1) != (s.length()-1)) {
                  if ((i+2) != (s.length()-1)) {
                      stringWithoutRep = "";
                  }
               }
           }
        }
   }

   s = removeDuplicates(stringWithoutRep);

   return s.length();
}

int main()
{
    //Empty string
    std::string s = "";
    std::cout << lengthOfLongestSubstring(s) << std::endl;

    //Single character
    s = "a";
    std::cout << lengthOfLongestSubstring(s) << std::endl;

    //All unique
    s = "abcdef";
    std::cout << lengthOfLongestSubstring(s) << std::endl;

    //All repeating
    s = "aaaaaa";
    std::cout << lengthOfLongestSubstring(s) << std::endl;

    //Simple mixed
    s = "abcabcbb";
    std::cout << lengthOfLongestSubstring(s) << std::endl;

    //Overlap repetition
    s = "pwwkew";
    std::cout << lengthOfLongestSubstring(s) << std::endl;

    //Repetition at end
    s = "dvdf";
    std::cout << lengthOfLongestSubstring(s) << std::endl;

    //Non-contiguous repeats
    s = "abba";
    std::cout << lengthOfLongestSubstring(s) << std::endl;

    //Mixed characters
    s = "aA1!aA1!";
    std::cout << lengthOfLongestSubstring(s) << std::endl;

    //Spaces included
    s = "a b c a b";
    std::cout << lengthOfLongestSubstring(s);

    return 0;
}
