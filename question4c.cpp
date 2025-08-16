# include <iostream>
using namespace std;
int main()
{
    int row,col;
    cout<<"Enter the no. of rows and columns of the array:";
    cin>>row>>col;

    int arr[row][col];
    cout<<"Enter the elements of the array!";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }
    int transpose[col][row];
    //for transpose of matrix
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            transpose[j][i]=arr[i][j];
        }
    }
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
    
}