#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

};

void insertAtEnd(node* &head,node* &tail,int data)
{
    node* n=new node(data);
    if(head==NULL)
    {
        head=tail=n;
    }else
    {
        tail->next=n;
        tail=n;
    }
}

void printLL(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int lengthLL(node *head)
{
     node* n=head;
    int length=0;
    while(n)
    {
        n=n->next;
        length++;
    }
    return length;
}

void deleteFromStart(node* &head,node* &tail)
{
    if(head==NULL)
        return;
    if(head->next==NULL)
    {
        head=tail=NULL;
        return;
    }
    node* n=head;
    head=head->next;
    delete n;
    return;
}

void deleteFromEnd(node* &head,node* &tail)
{
    if(head==NULL)
        return;
    if(head->next==NULL)
    {
        delete head;
        head=tail=NULL;
        return;
    }
    node* n=head;
    while(n->next!=tail)
    {
        n=n->next;
    }
    delete tail;
    tail=n;
    tail->next=NULL;
    return;
}

void deleteFromPos(node* &head,node* &tail,int pos)
{
    if(head==NULL)
        return;
    if(pos<=0)
    {
        deleteFromStart(head,tail);
    }else if(pos>=lengthLL(head)-1)
    {
        deleteFromEnd(head,tail);
    }else
    {
        node *n=head;
        int counter=0;
        while(counter<pos-1)
        {
            n=n->next;
            counter++;
        }
        node* tmp=n->next;
        n->next=tmp->next;
        delete tmp;
    }
    return;
}

int main()
{
    int n,q;
    cin>>n>>q;
    node* head=NULL;
    node* tail=NULL;
    int data;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insertAtEnd(head,tail,data);
    }
    int pos;
    while(q--)
    {
       cin>>pos;
       deleteFromPos(head,tail,pos);
       printLL(head);
    }

    return 0;
}
