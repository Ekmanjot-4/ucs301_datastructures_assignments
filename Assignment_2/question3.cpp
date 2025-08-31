# include <iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    int arr[size-1];
    cout<<"Enter the elements of the array in sorted manner:"<<endl;
    for(int i=0;i<size-1;i++)
    {
        cin>>arr[i];
    }
    int actualSum=0;
    for(int i=0;i<size-1;i++)
    {
        actualSum+=arr[i];
    }
    int first=arr[0];
    int last=first+size-1;
    int expectedSum=(first+last)*size/2;
    int number=expectedSum-actualSum;
    cout<<"The missing number is "<<number<<endl;
    return 0;

}