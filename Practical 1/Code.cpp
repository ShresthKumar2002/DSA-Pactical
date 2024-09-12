#include <iostream>
using namespace std;

void cdia(int a);   //1

int main()
{
    int a=0;
    RETRY:cout<<"Enter the number of Stars in the longest row : ";
    cin>>a;
    if(a>=2)
    {
        cdia(a);  //2
        return 0;
    }
    else
    {
        cout<<"Invalid input\n";
        goto RETRY;  //3
    }
}

void cdia(int a)
{    
    int t=2*a-1;
    char arr[30][30];
    
    //4
    for(int i=0; i<=t;i++)
    {
        for(int j=0; j<t;j++)
        {
            arr[i][j] =' ';
        }
    }

    //5
    for(int i=0; i<=a;i++)
    {
        if(i!=a)
        {
            //6
            for(int j=a-i;j<a+i;)
            {
              arr[i][j]='*';
              j=j+2;
            }
        
            strcpy(arr[t-i+1],arr[i]);  //7
        }
        else
        {
            //8
            for(int j=0;j<t;j=j+2)
            {
                arr[a][j]='*';
            }
        }

    }

    //9
    for(int i=0; i<=t;i++)
    {
        for(int j=0; j<t;j++)
        {
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}