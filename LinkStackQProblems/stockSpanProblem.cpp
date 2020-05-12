#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,prices[100001]={0};
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>prices[i];
        int spans[100001]={0};
        for(int i=1;i<=n;i++)
        {
            int counter=0;
            for(int j=1;j<=i;j++)
            {
                if(prices[j]<=prices[i])
                    counter++;
                else
                    counter=0;
            }
            spans[i]=counter;
        }
        for(int i=1;i<=n;i++)
            cout<<spans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
