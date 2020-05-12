#include<bits/stdc++.h>
using namespace std;

bool isBalanced(char *str)
{
    stack<char> s;
    for(int i=0; str[i]!='\0'; i++)
    {
        switch(str[i])
        {
            case '{':
            case '[':
            case '(':
                    s.push(str[i]);
                    break;
            case ')':
                if(!s.empty() && s.top()=='(')
                    s.pop();
                else
                    return false;
                    break;
            case ']':
                if(!s.empty() && s.top()=='[')
                    s.pop();
                else
                    return false;
                    break;
            case '}':
                if(!s.empty() && s.top()=='{')
                    s.pop();
                else
                    return false;
                    break;
            default:
                return false;
                break;
        }
    }
    if(s.empty())
        return true;
    return false;
}

int main()
{
    char str[100000];
    cin>>str;
    if(isBalanced(str))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
