#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle)
{
    std::string emptyString = "";
    bool needleExists = false;
    int iter = 0;

    for (int i = 0; i < haystack.length(); i++) {
        if (haystack[i] == needle[iter]) {
            emptyString += haystack[i];
            if (emptyString == needle) {
                needleExists = true;
                break;
            }
            iter++;
        } else {
            emptyString = "";
            iter = 0;
        }
    }
    if(needleExists) {
        for (int j = 0; j < haystack.length(); j++) {
            if (haystack[j] == needle[0]) {
                return j;
            }
        }
    }

    return -1;
}

int main()
{
    std::string input = "happybutsad";
    std::string id = "sad";

    std::cout << strStr(input, id);

    return 0;
}
