#include<bits/stdc++.h>
using namespace std;

bool isPal(string s)
{
    int start=0,last=s.length()-1;
    while(start<=last)
    {
        if(s[start]!=s[last])
            return false;
        start++;
        last--;
    }
    return true;
}

bool isStrong(string s)
{
    if(!isPal(s))
        return false;
    int l=s.length();
    int x=(l-1)/2;
    string start = s.substr(0,x);
    if(!isPal(start))
        return false;

    string last = s.substr(x+1,l);
    if(!isPal(start))
        return false;
    return true;
}

int main()
{
    string s;
    cin>>s;
    if(isStrong(s))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
