#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[100000]={0};
    for(int i=0;i<n;i++)
        cin>>a[i];

    long long int maxArea=INT_MIN;
    for(int i=0;i<n;i++)
    {
        long long int area;
        int counter=0;
        //left
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]<a[i])
                break;
            counter++;
        }
        //right
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[i])
                break;
            counter++;
        }
        area=counter*a[i];
        if(area>maxArea)
            maxArea=area;
    }
    cout<<maxArea<<endl;

    return 0;
}
