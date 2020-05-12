#include<bits/stdc++.h>
using namespace std;

int elephant(int n,int m)
{
    //base case
    if(n==0 && m==0)
        return 1;

    //recursive
    int sum = 0;
    for(int i=m-1;i>=0;i--)
        sum+= elephant(n,i);
    for(int i=n-1;i>=0;i--)
        sum+= elephant(i,m);
    return sum;
}

int main()
{
    cout<<elephant(3,3)<<endl;
    return 0;
}

