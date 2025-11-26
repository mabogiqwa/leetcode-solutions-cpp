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

   if (removeDuplicates(s).length() == 1) {
       return removeDuplicates(s).length();
   } else {
       for (int i = 0; i < s.size()-1; i++) {
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
   //std::cout << s << std::endl;

   return s.length();
}

int main()
{
    std::string s = "pwwkew";

    std::cout << lengthOfLongestSubstring(s);

    return 0;
}
