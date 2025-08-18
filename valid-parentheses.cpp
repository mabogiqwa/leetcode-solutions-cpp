#include <iostream>
#include <iostream>
#include <string>

bool isValid(std::string input);

int main()
{
    std::cout << isValid("()()");
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
        if (input[index] == '(') {
            index++;
            if (input[index] == ')') {
                evenParentheses = true;
            } else {
                evenParentheses = false;
            }
            if (index >= input.length())
                break;
        } else if (input[index] == ')') {
            evenParentheses = false;
        }

        if (input[index] == '[') {
            index++;
            if (input[index] == ']') {
                evenSquareBrackets = true;
            } else {
                evenSquareBrackets = false;
            }
            if (index >= input.length())
                break;
        } else if (input[index] == ']') {
            evenSquareBrackets = false;
        }

        if (input[index] == '{') {
            index++;
            if (input[index] == '}') {
                evenCurlyBraces = true;
            } else {
                evenCurlyBraces = false;
            }
            if (index >= input.length())
                break;
        } else if (input[index] == '}') {
            evenCurlyBraces = false;
        }

        index++;
    }

    if (evenParentheses && evenCurlyBraces && evenSquareBrackets) {
        return true;
    } else {
        return false;
    }
}
