// to delete duplicate elements from an array 
# include<iostream>
using namespace std;
void dltDuplicate(int arr[],int &n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                for( int k=j;k<n;k++)
                {
                    arr[k]=arr[k+1];
                    
                }
                n--;
            }
        }
    }
    cout<<"The modified array is:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array:";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    //to remove duplicates
    dltDuplicate(arr,size);

    return 0;
}