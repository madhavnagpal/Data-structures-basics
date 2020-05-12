#include<bits/stdc++.h>
using namespace std;

int counter=0;
void toh(int n,string source,string destination,string helper)
{
    if(n==0)
    {
        return;
    }
    //recursive
    toh(n-1,source,helper,destination);
    cout<<"Move "<<n<<"th disc from "<<source<<" to "<<destination<<endl;
    counter++;
    toh(n-1,helper,destination,source);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    toh(n,"T1","T2","T3");
    cout<<counter<<endl;
    return 0;
}
