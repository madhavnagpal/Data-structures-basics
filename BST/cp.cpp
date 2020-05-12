#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a[100000]={0};
    int n,m;
    cin>>n>>m;
    n=n*m;

    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
