//Doesn't work for test cases s.a: ")","]]"
#include <iostream>
#include <string>

bool isValid(std::string input);

int main()
{
    std::cout << isValid("(]");
    return 0;
}

bool isValid(std::string input)
{
    bool evenParentheses = true;
    bool evenCurlyBraces = true;
    bool evenSquareBrackets = true;
    int index = 0;

    while (index < input.length())
    {
        if (input[index] == '(')
            evenParentheses = false;
        else if (input[index] == ')')
            evenParentheses = true;

        if (input[index] == '[')
            evenSquareBrackets = false;
        else if (input[index] == ']')
            evenSquareBrackets = true;

        if (input[index] == '{')
            evenCurlyBraces = false;
        else if (input[index] == '}')
            evenCurlyBraces = true;

        index++;
    }

    if (evenParentheses && evenCurlyBraces && evenSquareBrackets) {
        return true;
    } else {
        return false;
    }
}
