#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string x;
        cin>>x;
        stack<char> s;
        bool duplicate =false;
        char prev='a';

        for(int i=0;i<x.length();i++)
        {
            if(x[i]!=')')
                s.push(x[i]);
            else
            {
                int popped=0;
                while(s.top()!='(' && !s.empty())
                {
                    popped++;
                    s.pop();
                }
                s.pop();
                if(popped==0 && prev==')')
                {
                    duplicate=true;
                    break;
                }
            }
            prev=x[i];
        }
       if(duplicate)
            cout<<"Duplicate Found"<<endl;
       else
            cout<<"No Duplicate Found"<<endl;
    }
    return 0;
}
