#include <iostream>
#include <vector>
#include <string>

int lengthOfLastWord(std::string s)
{
    int index = 0;
    std::vector<std::string> tokens;
    std::string sentence = "";
    int lastIndex;

    while (index < s.length())
    {
        if (s[index] != ' ') {
            sentence += s[index];
            if (s[index+1] == ' ' || (index + 1 == s.length())) {
                tokens.push_back(sentence);
                sentence = "";
            }
        }
        index++;
    }
    std::cout << sentence << std::endl;
    lastIndex = tokens.size() - 1;

    for (auto& sen : tokens) {
        std::cout << sen << " ";
    }
    std::cout << std::endl;

    return (tokens[lastIndex].length());
}

int main()
{
    std::cout << lengthOfLastWord("luffy is still joyboy");

    return 0;
}
