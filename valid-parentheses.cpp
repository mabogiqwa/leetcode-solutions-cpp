//Passes 80/100 test cases
//Doesn't pass the test case {[]}
#include <iostream>
#include <iostream>
#include <string>

bool isValid(std::string input);

int main()
{
    std::cout << isValid("{[]}");
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
            if (!evenParentheses)
                evenParentheses = true;
            else
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
            if (!evenSquareBrackets)
                evenSquareBrackets = true;
            else
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
            if (!evenCurlyBraces)
                evenCurlyBraces = true;
            else
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
