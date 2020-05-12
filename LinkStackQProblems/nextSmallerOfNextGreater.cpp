#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[100000]={0};
        for(int i=0;i<n;i++)
            cin>>a[i];
        int b[100000]={0};

        for(int i=0;i<n;i++)
        {
            int curr,small=-1,large,j=i;
            curr=a[j];
            j++;
            while(j<n)
            {
                if(a[j]>curr)
                {
                    large=a[j];
                    break;
                }
                j++;
            }
            j++;
            while(j<n)
            {
                if(a[j]<large)
                {
                    small=a[j];
                    break;
                }
                j++;
            }
            cout<<small<<" ";
        }
        cout<<endl;
    }
    return 0;
}
