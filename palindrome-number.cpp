#include <iostream>

bool isPalindrome(std::string input)
{
    bool isPalindrome = false;
    int j = input.size() - 1;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == input[j])
        {
            isPalindrome = true;
        } else {
            return false;
        }
        j--;
    }
    return isPalindrome;
}

int main()
{
    int input;
    std::string stringInput;

    std::cout << "Enter any number: ";
    std::cin >> input;

    stringInput = std::to_string(input);

    std::cout << isPalindrome(stringInput);

    return 0;
}
