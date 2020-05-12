#include<bits/stdc++.h>
#include"node.h"
using namespace std;


template<typename T>
class Stack
{
    node<T> *head;
    public:
    Stack()
    {
        head=NULL;
    }
    void push(T data)
    {
        node<T> *n=new node<T>(data);
        if(head==NULL)
        {
            head=n;
            return;
        }
        n->next=head;
        head=n;
    }
    void pop()
    {
        if(head==NULL)
            return ;
        node<T> *n=head;
        head=head->next;
        delete n;
    }
    T top()
    {
        return head->data;
    }
    bool Empty()
    {
        return head==NULL;
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

