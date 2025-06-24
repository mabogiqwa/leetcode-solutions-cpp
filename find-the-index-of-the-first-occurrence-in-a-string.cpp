#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle)
{
    if (needle.empty()) return 0;  // Edge case

    int hLen = haystack.length();
    int nLen = needle.length();

    for (int i = 0; i <= hLen - nLen; i++) {
        int j = 0;
        while (j < nLen && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == nLen) {
            return i;  // Found match at index i
        }
    }

    return -1;  // Not found
}

int main()
{
    std::string input = "mississippi";
    std::string id = "issip";

    std::cout << strStr(input, id) << std::endl;

    return 0;
}
