#include <iostream>
#include <vector>

void lengthOfLongestSubstring(std::string s) {

   std::string stringWithoutRep = "";
   for (int i = 0; i < s.size()-1; i++) {
       if (s[i] != s[i+1]) {
           stringWithoutRep += s[i];
       }
   }

}

int main()
{
    std::string s = "abcabcbb";

    lengthOfLongestSubstring(s);

    return 0;
}
