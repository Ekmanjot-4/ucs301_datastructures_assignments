# include<iostream>
using namespace std;
int main()
{
    int row1,colmn1;
    cout<<"Enter the rows and columns for first array"<<endl;
    cin>>row1>>colmn1;
    cout<<"Enter the elements of the array:"<<endl;
    int arr1[row1][colmn1];
    for( int i=0;i<row1;i++)
    {
        for (int j=0;j<colmn1;j++)
        {
            cin>>arr1[i][j];
        }
    }
    int row2,colmn2;
    cout<<"Enter the rows and columns for second array"<<endl;
    cin>>row2>>colmn2;
    cout<<"Enter the elements of the array:"<<endl;
    int arr2[row2][colmn2];
    for( int i=0;i<row2;i++)
    {
        for (int j=0;j<colmn2;j++)
        {
            cin>>arr2[i][j];
        }
    }
    if(colmn1!=row2)
    {
        cout<<"Order of matrices is not compatible!"<<endl;
    }
    int prod[row1][colmn2];
    if(colmn1==row2){
        int k=colmn1;
    
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<colmn2;j++)
        {
            prod[i][j]=0;
            for(int l=0;l<k;l++)
            {
                prod[i][j]+=arr1[i][l]*arr2[l][j];
            }
        }
    }
}
for(int i=0;i<row1;i++)
{
    for(int j=0;j<colmn2;j++)
    {
        cout<<prod[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
    

}