# include <iostream>
# include<stack>
# include <string>
using namespace std;
bool isValid(string str)
{
    stack<char> st;
    for(int i=0;i<str.size();i++)
    {
        char ch=str[i];
        if(ch=='{'||ch=='['||ch=='(')
        {
            st.push(ch);
        }
        else{
            if(ch==']' && !st.empty()&& st.top()=='[')
            {
                st.pop();
            }
            else if(ch=='}' && !st.empty()&& st.top()=='{')
            {
                st.pop();
            }
            else if(ch==')' && !st.empty()&& st.top()=='(')
            {
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}
int main()
{
    string str;
    cout<<"Enter the expression"<<endl;
    getline(cin,str);
    
    if(isValid(str))
    {
        cout<<"Valid"<<endl;
    }
    else{
        cout<<"Invalid"<<endl;
    }
    return 0;
}