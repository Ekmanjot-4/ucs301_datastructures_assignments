# include <iostream>
using namespace std;
void transpose(int sparse[][3],int nz,int row, int col)
{
    for(int i=0;i<nz;i++)
    {
        int temp=sparse[i][0];
        sparse[i][0]=sparse[i][1];
        sparse[i][1]=temp;
       
    }
    for(int i=0;i<nz;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<sparse[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            bool found =false;
            for(int k=0;k<nz;k++)
            {
                if(sparse[k][0]==i && sparse[k][1]==j)
                {
                    cout<<sparse[k][2]<<" ";
                    found=true;
                    break;
                }
            }
            if(!found)
            {
                cout<<"0"<<" ";
            }
            
        }
        cout<<endl;
    }
    
}
int main()
{
    int rows;
    cout<<"Enter the number of rows:";
    cin>>rows;
    int cols;
    cout<<"Enter the number of columns:";
    cin>>cols;
    int nonZero;
    cout<<"Enter the number of non zero elements:";
    cin>>nonZero;
    int triplet[nonZero][3];
    for(int i=0;i<nonZero;i++)
    {
        cout<<"Enter the row, column ,value for each element";
        cin>>triplet[i][0]>>triplet[i][1]>>triplet[i][2];
    }
    cout<<"Your triplet matrix is:"<<endl;
    cout<<"Row Column  Value"<<endl;
    for(int i=0;i<nonZero;i++)
    {
        cout<<triplet[i][0]<<"\t";
        cout<<triplet[i][1]<<"\t";
        cout<<triplet[i][2]<<"\n";
    }
    transpose(triplet,nonZero,rows,cols);
    return 0;
}