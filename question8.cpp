# include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the length of the array:";
    cin>>n;
    int count=0;
    int arr[n];
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        bool distinct=false;
        for(int j=0;j<i;j++)
        {
            if(arr[i]==arr[j])
            {
                distinct =true;
                break;
            }
        }
        if(!distinct)
        {
            count++;
        }
    }

    cout<<"The number of distinct elements in the array are:"<<count<<endl;
    return 0;
    
    
}