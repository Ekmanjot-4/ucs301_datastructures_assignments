# include <iostream>
using namespace std;
void add( int sparse1[][3],int nz1,int sparse2[][3],int nz2,int row,int col)
{
    int res[nz1+nz2][3];
    int count =0;
    int i=0;
    int j=0;
    while(i<nz1 && j<nz2)
    {
            if(sparse1[i][0]<sparse2[j][0]||(sparse1[i][0]==sparse2[j][0]&& sparse1[i][1]<sparse2[j][1]))
            {
                res[count][0]=sparse1[i][0];
                res[count][1]=sparse1[i][1];
                res[count][2]=sparse1[i][2];
                count ++;
                i++;
            }
            else if(sparse2[j][0]<sparse1[i][0]||(sparse1[i][0]==sparse2[j][0]&& sparse1[i][1]>sparse2[j][1]))
            {
                res[count][0]=sparse2[j][0];
                res[count][1]=sparse2[j][1];
                res[count][2]=sparse2[j][2];
                count ++;
                j++;
            }
            else{
                res[count][0]=sparse1[i][0];
                res[count][1]=sparse1[i][1];
                res[count][2]=sparse1[i][2]+sparse2[j][2];
                i++;
                j++;
                count++;
            }
        }
        while (i < nz1) 
 {
    res[count][0] = sparse1[i][0];
    res[count][1] = sparse1[i][1];
    res[count][2] = sparse1[i][2];
    i++;
    count++;
}
    
    while (j < nz2)
    {
       res[count][0] = sparse2[j][0];
       res[count][1] = sparse2[j][1];
       res[count][2] = sparse2[j][2];
       j++;
       count++;
    }
        


    cout<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            bool found =false;
            for(int k=0;k<count;k++)
            {
                if(res[k][0]==i && res[k][1]==j)
                {
                    cout<<res[k][2]<<" ";
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
    int row,col;
    cout<<"Enter the number of rows and columns of the matrices:";
    cin>>row>>col;
    int nz1,nz2;
    cout<<"Enter the number of non zero elements of matrix 1 and matrix 2:";
    cin>>nz1>>nz2; 
    int sparse1[nz1][3];
    int sparse2[nz2][3];
    cout<<"Enter the row, column and value of elements for the first matrix:"<<endl;
    for(int i=0;i<nz1;i++)
    {
        cout<<"Row    Column   Value:";
        cin>>sparse1[i][0]>>sparse1[i][1]>>sparse1[i][2];
    }
     cout<<"Enter the row, column and value of elements for the second matrix:"<<endl;
    for(int i=0;i<nz2;i++)
    {
        cout<<"Row    Column   Value:";
        cin>>sparse2[i][0]>>sparse2[i][1]>>sparse2[i][2];
    }
    add(sparse1,nz1,sparse2,nz2,row,col);
    return 0;
}