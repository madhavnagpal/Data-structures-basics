//https://hack.codingblocks.com/app/contests/390/344/problem
#include<bits/stdc++.h>
using namespace std;

class grid
{
    public:
        int row,col;
        int r1,c1,r2,c2,r3,c3;
        bool check1,check2,check3;
        grid()
        {
            check1=false;
            check2=false;
            check3=false;
        }
};

bool allTraversed(int a[][8], grid x)
{
    for(int i=0;i<x.row;i++)
    {
        for(int j=0;j<x.col;j++)
        {
            if(i!=0 && j!=1 && a[i][j]==0)
                {
                    return false;
                }
        }
    }
    return true;
}

int tours(grid x,int i,int j, int a[][8])
{
    //base
    if( i==0 && j==1)
    {
        if( x.check1 && x.check2 && x.check3 && allTraversed(a, x)) //no spaces between and operators
           return 1;
        else
            return 0;
    }
    //stay in grid
    if(i>=x.row || i<0 || j<0 ||j>=x.col)
    {
         return 0;
    }
    //traverses once
    if(a[i][j]!=0)
    {
        return 0;
    }
    //recursive
    //solving for one

    if(i==x.r1 && j==x.c1)
    {
        if(!x.check2 && !x.check3)
        {
            a[i][j]=1;
            x.check1=true;
        }else
        {
            return 0;
        }
    }else if(i==x.r2 && j==x.c2)
    {
        if(x.check1 && !x.check3)
        {
            a[i][j]=1;
            x.check2=true;
        }else
        {
            return 0;
        }
    }else if(i==x.r3 && j==x.c3)
    {
        if(x.check1 && x.check2)
        {
            a[i][j]=1;
            x.check3=true;
        }else
        {
            return 0;
        }
    }else
    {
        a[i][j]=1;
    }
    return tours(x,i+1,j,a)+tours(x,i,j+1,a)+tours(x,i-1,j,a)+tours(x,i,j-1,a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcases;
    cin>>testcases;
    for(int i=1;i<=testcases;i++)
    {
        grid x;
        cin>>x.row>>x.col;
        cin>>x.r1>>x.c1>>x.r2>>x.c2>>x.r3>>x.c3;
        int a[8][8];
        for(int i=0;i<8;i++)
                for(int j=0;j<8;j++)
                    a[i][j]=0;
        int numTours = tours(x,0,0,a);
        cout<<"Case "<<i<<": "<<numTours<<endl; //no space brfore colon
    }
    return 0;
}

