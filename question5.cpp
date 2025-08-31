#include<iostream>
using namespace std;
void diagonal(int arr[],int n)
{
    cout<<"Enter the order of the array:";
    cin>>n;
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++)
    {
            {
                cin>>arr[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                cout<<arr[i]<<" ";
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
}
void triDiagonal(int arr[],int n)
{
    cout<<"Enter the size of the array:";
    cin>>n;
    cout<<"Enter the elements of the array";
    for( int i=0;i<n-1;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr[n-1+i];
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>arr[2*n-1+i];
    }
    cout<<"The Tri-Diagonal matrix is:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-j==(-1))
            {
                cout<<arr[i]<<" ";
            }
            else if(i==j)
            {
                cout<<arr[n-1+i]<<" ";
            }
            else if(i-j==1)
            {
                cout<<arr[2*n-1+j]<<" ";
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
}
void lowerTriangular(int arr[],int n)
{
    cout<<"Enter the order of the matrix:";
    cin>>n;
    cout<<"Enter the elements of the matrix:";
    for(int i=0;i<(n*(n+1)/2);i++)
    {
        cin>>arr[i];
    }
    int k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=j)
            {
                cout<<arr[k++]<<" ";
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
}
void upperTriangular(int arr[],int n)
{
    cout<<"Enter the order of the matrix:";
    cin>>n;
    cout<<"Enter the elements of the matrix:";
    for(int i=0;i<(n*(n+1)/2);i++)
    {
        cin>>arr[i];
    }
    int k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<=j)
            {
                cout<<arr[k++]<<" ";
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
}
void symmetricMatrix(int arr[], int n) {
    cout << "Enter the order of the matrix: ";
    cin >> n;
    int size = n * (n + 1) / 2;
    cout << "Enter the elements of the lower triangular part:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "The Symmetric Matrix is:" << endl;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) 
            {
                cout << arr[i * (i + 1) / 2 + j] << " ";
            }
            else 
            {
                cout << arr[j * (j + 1) / 2 + i] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int arr[100];
    int n=0;
    int menu;
    cout<<"            MENU            "<<endl;
    cout<<"1.Diagonal Matrix"<<endl;
    cout<<"2.Tri-Diagonal Matrix"<<endl;
    cout<<"3.Lower Triangular Matrix"<<endl;
    cout<<"4.Upper Triangular Matrix"<<endl;
    cout<<"5.Symmetric Matrix"<<endl;
    cout<<"Enter the Matrix you want to choose:"<<endl;
    cin>>menu;
    switch(menu){
        case 1:
        diagonal(arr,n);
        break;
        case 2:
        triDiagonal(arr,n);
        break;
        case 3:
        lowerTriangular(arr,n);
        break;
        case 4:
        upperTriangular(arr,n);
        break;

    }

    return 0;
}