#include <iostream>
using namespace std;

class SpMatrix{
    private:
    int size;
    int r1[100],c1[100],y1[100];

    public:
    void input(int a);
    void output();
    int rt(int i)
    {
        if(i==0)
        {return(r1[0]);}
        else if(i==1)
        {return(c1[0]);}
        else if(i==2)
        {return(y1[0]);}
    };
    void transp();
    void Adding(SpMatrix A,SpMatrix B);
};


void main()
{
    SpMatrix A,B,C;
    int a,b;
    cout<<"Enter the number of non-zero terms in the First Matrix : ";
    cin>>a;
    A.input(a);
    cout<<"Enter the number of non-zero terms in the Second Matrix : ";
    cin>>b;
    B.input(b);
    int r1=A.rt(0);
    int r2=B.rt(0);
    if(r1!=r2)
    {
        cout<<"Addition Impossible \n";
    }
    else
    {
        int c1=A.rt(1);
        int c2=B.rt(1);
        if(r1!=r2)
        {
            cout<<"Addition Impossible \n";
        }
        else
        {
            C.Adding(A,B);
            C.output();
        }   
    }
}

void SpMatrix::input(int a)
{
    size=a;
    cout<<"Enter number of rows :";
    cin>>r1[0];
    cout<<"Enter number of columns :";
    cin>>c1[0];
    y1[0]=a;
    for(int i=1;i<=size;i++)
    {
        if(i==1)
        {
        cout<<"Enter the values of "<<i<<"st non-zero term one by one :";
        cin>>r1[i]>>c1[i]>>y1[i];
        cout<<"\n";
        }
        else if(i==2)
        {
        cout<<"Enter the values of "<<i<<"nd non-zero term one by one :";
        cin>>r1[i]>>c1[i]>>y1[i];
        cout<<"\n";
        }
        else if(i==3)
        {
        cout<<"Enter the values of "<<i<<"rd non-zero term one by one :";
        cin>>r1[i]>>c1[i]>>y1[i];
        cout<<"\n";
        }
        else
        {
        cout<<"Enter the values of "<<i<<"th non-zero term one by one :";
        cin>>r1[i]>>c1[i]>>y1[i];
        cout<<"\n";
        }
    }
}

void SpMatrix::output()
{
    for(int i=1;i<=y1[0];i++)
    {
        if(i==1)
        {
            cout<<"\nThe values of "<<i<<"st non-zero term are : "<<r1[i]<<" "<<c1[i]<<" "<<y1[i]<<"\n";
        }
        else if (i==2)
        {
            cout<<"The values of "<<i<<"nd non-zero term are : "<<r1[i]<<" "<<c1[i]<<" "<<y1[i]<<"\n";
        }
        else if (i==3)
        {
            cout<<"The values of "<<i<<"rd non-zero term are : "<<r1[i]<<" "<<c1[i]<<" "<<y1[i]<<"\n";
        }
        else 
        {
            cout<<"The values of "<<i<<"th non-zero term are : "<<r1[i]<<" "<<c1[i]<<" "<<y1[i]<<"\n";
        }
    }
}


void SpMatrix::Adding(SpMatrix A,SpMatrix B)
{
    int m=A.rt(2);
    int n=B.rt(2);

    int i,j,k;
    i=j=k=1;

    while((i<=m)&&(j<=n))
    {
        if((A.r1[i]==B.r1[j])&&(A.c1[i]==B.c1[j]))
        {
            r1[k]=A.r1[i];
            c1[k]=A.c1[i];
            y1[k]=A.y1[i]+B.y1[j];
            i++;j++;k++;
        }
        else if((A.r1[i]<B.r1[j])||((A.r1[i]==B.r1[j])&&(A.c1[i]<B.c1[j])))
        {
            r1[k]=A.r1[i];
            c1[k]=A.c1[i];
            y1[k]=A.y1[i];
            i++;k++;
        }
        else
        {
           r1[k]=B.r1[j];
           c1[k]=B.c1[j];
           y1[k]=B.y1[j];
           j++;k++; 
        }
    }
    while(i<=m)
    {
        r1[k]=A.r1[i];
        c1[k]=A.c1[i];
        y1[k]=A.y1[i];
        i++;k++;
    }
    while(j<=n)
    {
        r1[k]=B.r1[j];
        c1[k]=B.c1[j];
        y1[k]=B.y1[j];
        j++;k++;
    }
    r1[0]=A.r1[0];
    c1[0]=A.c1[0];
    y1[0]=k-1;

};