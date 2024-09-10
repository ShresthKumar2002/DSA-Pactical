#include <iostream>
using namespace std;

void cdia(int a);

int main()
{
    int a=0;
    cin>>a;
    cout<<2*a-1;
    cdia(a);
    return 0;
}

void cdia(int a)
{
    int t=2*a-1;
    char arr[30][30];
    for(int i=0; i<=t;i++)
    {
        for(int j=0; j<t;j++)
        {
            arr[i][j] =' ';
        }
    }
    for(int i=0; i<a;i++)
    {
        for(int j=a-i;j<a+i;)
        {
            arr[i][j]='*';
            j=j+2;
        }
        strcpy(arr[t-i+1],arr[i]);
    }
    for(int j=0;j<t;j=j+2)
        {
            arr[a][j]='*';
        }
    for(int i=0; i<=t;i++)
    {
        for(int j=0; j<t;j++)
        {
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}