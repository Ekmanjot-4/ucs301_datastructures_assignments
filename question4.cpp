# include <bits/stdc++.h>
# include<algorithm>
# include <cctype>
using namespace std;
void concatStrings()
{
    string s1,s2;
    cout<<"Enter the first string:";
    getline(cin,s1);
    cout<<"Enter the second string:";
    getline(cin,s2);
    s1+=s2;
    cout<<"The concatenated strings are:"<<s1<<endl;
}
void reverseString()
{
    string s1;
    cout<<"Enter the string:";
    getline(cin,s1);
    int left_ptr=0;
    int right_ptr=s1.size()-1;
    while(left_ptr<right_ptr)
    {
        char temp=s1[left_ptr];
        s1[left_ptr]=s1[right_ptr];
        s1[right_ptr]=temp;
        left_ptr++;
        right_ptr--;
    }
    cout<<"The reversed string is: "<<s1<<endl;
}
void dltVowels()
{
    string s1;
    cout<<"Enter the string:";
    getline(cin,s1);
    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
    for(int j=0;j<s1.size();)
    {
        if(s1[j]=='a'||s1[j]=='e'||s1[j]=='i'||s1[j]=='o'|| s1[j]=='u')
        {
            s1.erase(j,1);
            
        }
        else{
            j++;
        }
        
    }
    cout<<"The modified string is:"<<s1<<endl;
    
}
void alphabeticalSort()
{
    string s1;
    cout<<"Enter the string:";
    getline(cin,s1);
    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
    sort(s1.begin(),s1.end());
    cout<<"The sorted string is:"<<s1<<endl;
    
}
void lowercase()
{
    string s1;
    cout<<"Enter the string:";
    getline(cin,s1);
    char a;
    cout<<"Enter the character you want to be turned to lowercase:";
    cin>>a;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]==a)
        {
            s1[i]=tolower(s1[i]);
        }
    }

    cout<<"The modified string is:"<<s1<<endl;
    
}
int main()
{
    int choice;
    cout<<"            MENU            "<<endl;
    cout<<"1.Concatenate two strings"<<endl;
    cout<<"2.Reverse a string"<<endl;
    cout<<"3.Delete vowels from string"<<endl;
    cout<<"4.Sort string in alphabetical order"<<endl;
    cout<<"5.Convert a character from uppercase to lowercase"<<endl;
    cout<<"Enter the operation you want to perform:";
    cin>>choice;
    cin.ignore();
    switch(choice)
    {
        case 1:
        concatStrings();
        break;
        case 2:
        reverseString();
        break;
        case 3:
        dltVowels();
        break;
        case 4:
        alphabeticalSort();
        break;
        case 5:
        lowercase();
        break;

    }

    return 0;
   
}