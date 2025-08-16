# include <iostream>
using namespace std;
int main()
{
    int row,col;
    cout<<"Enter the number of rows and columns of matrix:"<<endl;
    cin>>row>>col;
    int arr[row][col];
    cout<<"Enter the elements of the array:";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }
    //for sum of rows 
    int sumRows[row];
    for(int i=0;i<row;i++)
    {
        sumRows[i]=0;
        for(int j=0;j<col;j++)
        {
            sumRows[i]+=arr[i][j];
        }
    }
    //for sum of columns
    int sumCols[col];
    for(int i=0;i<col;i++)
    {
        sumCols[i]=0;
        for(int j=0;j<row;j++)
        {
            sumCols[i]+=arr[j][i];
        }
    }
    cout<<"The sum of rows are:"<<endl;
    for(int i=0;i<row;i++)
    {
        cout<<"The sum of row "<<i+1<<" is: "<<sumRows[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<col;i++)
    {
        cout<<"The sum of column "<<i+1<<" is: "<<sumCols[i]<<endl;
    }

    return 0;
}