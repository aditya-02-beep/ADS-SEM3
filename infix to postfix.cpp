#include <iostream>
#include <stack>
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

int main()
{
    string infix, postfix = "";
    stack<char> s;

    cout << "Enter infix expression: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix expression: " << postfix;

    return 0;
}