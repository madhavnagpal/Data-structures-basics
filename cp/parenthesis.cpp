#include<bits/stdc++.h>
using namespace std;

string parenthesis(string str)
{
    int open=0;
    stack<char> s;

    for(int i=0; str[i]!='\0';i++)
    {
        int digit = str[i]-'0';
        if(open<digit)
        {
            while(digit-open)
            {
                s.push('(');
                open++;
            }
            s.push(str[i]);
        }else if(open == digit)
        {
            s.push(str[i]);
        }else if(open > digit)
        {
            while(open-digit)
            {
                s.push(')');
                open--;
            }
            s.push(str[i]);
        }
    }
    while(open)
    {
        s.push(')');
        open--;
    }
    string temp="";
    while(!s.empty())
    {
        temp.push_back(s.top());
        s.pop();
    }
    return temp;


}

int main()
{
    int t;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        string s;
        cin>>s;

        string rev = parenthesis(s);
        reverse(rev.begin(),rev.end());
        cout<<"Case #"<<test<<": "<<rev<<endl;

    }//test case end
    return 0;
}
