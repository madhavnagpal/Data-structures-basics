#include<bits/stdc++.h>
//#include<stack>
using namespace std;

int main()
{
    stack<char> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
