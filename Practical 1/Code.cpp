#include <iostream>
using namespace std;

void cdia(int a);   //Creating a declaration for the function to apply the operation.

int main()
{
    int a=0;
    RETRY:cout<<"Enter the number of Stars in the longest row : ";
    cin>>a;
    if(a>=2)
    {
        cdia(a);  //Function Call
        return 0;
    }
    else
    {
        cout<<"Invalid input\n";
        goto RETRY;  //Reset
    }
}

void cdia(int a)
{    
    int t=2*a-1;
    char arr[30][30];
    
    // A loop to set the 2D array for the Diamond
    for(int i=0; i<=t;i++)
    {
        for(int j=0; j<t;j++)
        {
            arr[i][j] =' ';
        }
    }

    // A Loop to parse from 1st row to n-1 th row
    for(int i=0; i<=a;i++)
    {
        if(i!=a)
        {
            // A loop to add stars as per the row number
            for(int j=a-i;j<a+i;)
            {
              arr[i][j]='*';
              j=j+2;
            }
        
            strcpy(arr[t-i+1],arr[i]);  // Copying the i th row from the top in the i th row from bottom
        }
        else
        {
            // A loop to print the center row 
            for(int j=0;j<t;j=j+2)
            {
                arr[a][j]='*';
            }
        }

    }

    // Loop to print the Matrix
    for(int i=0; i<=t;i++)
    {
        for(int j=0; j<t;j++)
        {
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}