# include <iostream>
# include <string>
# include <stack>
using namespace std;
int main()
{
    string str;
    cout<<"Enter the string"<<endl;
    getline(cin,str);
    stack<char> st;
    for(int i=0;i<str.size();i++)
    {
        st.push(str[i]);
    }
    string strrev;
    while(!st.empty())
    {
        strrev.push_back(st.top());
        st.pop();
    }
    cout<<"The reversed string is: "<<strrev<<endl;
    return 0;
}