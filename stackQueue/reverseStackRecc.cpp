#include<bits/stdc++.h>
using namespace std;

void toBottom(stack<int> &s,int top)
{
    if(s.empty())
    {
        s.push(top);
        return;
    }
    int tmp = s.top();
    s.pop();
    toBottom(s,top);
    s.push(tmp);
    return;
}

void reverseStack(stack<int> &s)
{
    if(s.empty())
        return;
    int top=s.top();
    s.pop();
    reverseStack(s);
    toBottom(s,top);
}

void printStack(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main()
{
    stack<int> s;
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        s.push(data);
    }
    reverseStack(s);
    printStack(s);

}
