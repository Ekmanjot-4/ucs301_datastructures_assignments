#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperand(char s)
{
    if (isalnum(s))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    string str;
    cout << "Enter the string" << endl;
    getline(cin, str);
    string res;

    stack<char> st;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (isOperand(ch))
        {
            res.push_back(ch);
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res.push_back(st.top());
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else//this is where the operator handling without parantheses takes place
        {
            while (!st.empty() && precedence(st.top()) >= precedence(ch) && st.top() != '(')
            {
                res.push_back(st.top());
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    cout << "Postfix Expression: " << res << endl;
    return 0;
}
