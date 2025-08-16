# include <iostream>
using namespace std;
void createArr(int arr[],int &n)
{
    cout<<"Enter the size of the array:";
    cin>>n;
    cout<<"Enter the elements of the array:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
}
void display(int arr[],int n)
{
    cout<<"The elements of the array are:\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
}
void insertElement(int arr[],int &n,int value,int position)
{
    if(position >= 1 && position <= n+1){
    for (int i=n;i>=position;i--)
    {
        arr[i]=arr[i-1];
        
    }
    arr[position-1]=value;
    n++;}
    else{
        cout<<"Enter a valid position!";
    }
    cout<<"The modified array is:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
void deleteElement(int arr[],int &n,int position)
{
    if(position >= 1 && position <= n){
        for(int i=position-1;i<n;i++)
        {
           arr[i]=arr[i+1];
        }
        n--;
    }
    else{
        cout<<"Enter a valid position!";
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
void linearSearch(int arr[],int &n,int element)
{
    bool found=false;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
        {
            cout<<"Element found at "<<i<<" index"<<" and "<<i+1<<" position";
            found=true;
        }
    }
    if(!found){
    cout<<"Element not found!";
    }
    cout<<endl;
}

int main()
{
    int arr[100];
    int n=0;
    int menu;
    do{
        cout<<"            MENU            \n";
        cout<<"1.Creation\n";
        cout<<"2.Display\n";
        cout<<"3.Insertion\n";
        cout<<"4.Deletion\n";
        cout<<"5.Linear Search\n";
        cout<<"6.Exit\n";
        
        cout<<"Enter the option you want to choose:";
        cin>>menu;

        switch (menu){
        case 1:
        createArr(arr,n);
        break;
        case 2:
        if (n==0)
        {
            cout<<"Please create an array first!\n";
        }
        else{
            display(arr,n);
        }
        break;
        case 3:
        if (n==0)
        {
            cout<<"Please create an array first!\n";
        }
        else{
            int val, pos;
            cout<<"Enter the value to be inserted and the position:";
            cin>>val>>pos;
            insertElement(arr,n,val,pos);
        }
        break;
        case 4:
        if (n==0)
        {
            cout<<"Please create an array first!\n";
        
        }
        else{
            int pos;
            cout<<"Enter the position of element to be deleted:";
            cin>>pos;
            deleteElement(arr,n,pos);
        }
        break;
        case 5:
        if (n==0)
        {
            cout<<"Please create an array first!\n";
            cout<<endl;
        }
        else{
            int element;
            cout<<"Enter element to be found:";
            cin>>element;
            linearSearch(arr,n,element);
        }
        break;
        case 6:
        cout<<"Exiting menu!"<<endl;
        break;}
    }while(menu!=6);
    return 0;

}