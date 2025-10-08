#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperand(char s)
{
    return isalnum(s);
}

string postfixToInfix(string postfix)
{
    stack<string> st;

    for (int i = 0; i < postfix.size(); i++)
    {
        char ch = postfix[i];

        if (isOperand(ch))
        {
            string op(1, ch);
            st.push(op);
        }
        else
        {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            string exp = "(" + op1 + ch + op2 + ")";
            st.push(exp);
        }
    }

    return st.top();
}

int main()
{
    string postfix;
    cout << "Enter the postfix expression" << endl;
    getline(cin, postfix);

    string infix = postfixToInfix(postfix);
    cout << "Infix Expression: " << infix << endl;

    return 0;
}
