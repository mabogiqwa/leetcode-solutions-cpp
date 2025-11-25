//Suboptimal: Processes subsequences
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

std::string removeDuplicates(const std::string& s)
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
   for (int i = 0; i < s.size()-1; i++) {
       if (s[i] != s[i+1]) {
           stringWithoutRep += s[i];
       }
   }
   s = removeDuplicates(stringWithoutRep);
   //std::cout << s << std::endl;

   return s.length();
}

int main()
{
    std::string s = "abcabcbb";

    std::cout << lengthOfLongestSubstring(s);

    return 0;
}
