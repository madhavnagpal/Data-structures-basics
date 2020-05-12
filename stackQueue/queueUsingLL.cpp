#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};

class Queue
{
    node* head;
public:
    Queue()
    {
        head=NULL;
    }
    void push(int data)
    {
        node* n=new node(data);
        if(head==NULL)
            head=n;
        else
        {
            node *prev=NULL,*curr=head;
            while(curr)
            {
                prev =curr;
                curr=curr->next;
            }
            prev->next=n;
        }
    }
    void pop()
    {
        if(head==NULL)
            return;
        node* n=head;
        head=head->next;
        delete n;
    }
    int Front()
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
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while(!q.Empty())
    {
        cout<<q.Front()<<" ";
        q.pop();
    }

    return 0;
}
