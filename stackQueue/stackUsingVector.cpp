#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Stack
{
    vector<T> s;
public:
    void push(T data)
    {
        s.push_back(data);
    }
    void pop()
    {
        s.pop_back();
    }
    T top()
    {
        return s[s.size()-1];
    }
    bool Empty()
    {
        return s.empty();
    }
};
int main()
{
    Stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.Empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
