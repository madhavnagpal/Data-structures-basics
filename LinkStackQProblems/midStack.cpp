#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prev,*next;
    node(int d)
    {
        data =d;
        prev=next=NULL;
    }
};

class Stack
{
    private:
    node *head,*mid;
    int cs=0;
    public:
        Stack()
        {
            head=NULL;
            mid=NULL;
        }
        void push(int data)
        {
            node *n=new node(data);
            if(head==NULL)
            {
                head=mid=n;
                cs++;
                return;
            }

            head->prev=n;
            head=n;
            cs++;
            if(cs%2!=0)
            {
                mid=mid->prev;
            }
            return;

        }
        node* middle()
        {
            return mid;
        }

};

int main()
{
    int n,data;
    cin>>n;
    Stack s;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        s.push(data);
    }
    cout<<s.middle()->data<<endl;
}
