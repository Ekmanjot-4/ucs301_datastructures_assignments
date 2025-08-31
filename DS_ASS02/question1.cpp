# include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                        
            }
        }
    }
    cout<<"The sorted array is:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
            low=mid+1;
        }
        else if(arr[mid]>target)
        {
            high=mid-1;
        }
        else{
            return -1;
        }
    }
}
int main()
{
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the element to be found:"<<endl;
    cin>>target;

    int index=binarySearch(arr, size, target);
    if(index!=(-1))
    {
        cout<<"The element is found at "<<index<<" index and "<<index+1<<" position!"<<endl;
    }
    else
    {
        cout<<"Element not found in the array!"<<endl;
 
    }
    return 0;
}
