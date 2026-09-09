#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string infix)
{
    stack<char> st;
    string result = "";

    reverse(infix.begin(), infix.end());

    // Brackets swap
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';

        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Convert to postfix
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // Operand
        if (isalnum(ch))
        {
            result += ch;
        }

        // Opening bracket
        else if (ch == '(')
        {
            st.push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }

            st.pop();
        }

        // Operator
        else
        {
            while (!st.empty() &&
                   precedence(st.top()) >= precedence(ch))
            {
                result += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    // Remaining operators
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    // Reverse postfix to get prefix
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    string infix;

    cin >> infix;

    cout << infixToPrefix(infix);

    return 0;
}