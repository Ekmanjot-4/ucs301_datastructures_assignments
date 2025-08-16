// to reverse elements of an array
# include <iostream>
using namespace std;
void reverse(int arr[],int n)
{
    int left_ptr=0;
    int right_ptr=n-1;
    while(left_ptr<right_ptr)
    {
        int temp=arr[left_ptr];
        arr[left_ptr]=arr[right_ptr];
        arr[right_ptr]=temp;
        left_ptr++;
        right_ptr--;
    }
    cout<<"The reversed array is:\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int size;
    cout<<"Enter size of the array:";
    cin>>size;
    int arr[size];
    cout<<"Enter elements of the array:";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    reverse(arr,size);
    return 0;
    
}