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
        head=tail=n;
    else
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

void appendLL(node* &head,node* &tail,int k)
{
    node* slow=head,*fast=head,*prev=NULL;
    for(int i=0;i<k;i++)
    {
        fast=fast->next;
    }
    while(fast!=NULL)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next;
    }
    tail->next=head;
    tail=prev;
    tail->next=NULL;
    head=slow;
}

int main()
{
    node* head=NULL,*tail=NULL;
    int n;
    cin>>n;
    int data;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insertAtEnd(head,tail,data);
    }
    int k;
    cin>>k;
    k=k%n;
    if(k>0)
    {
        appendLL(head,tail,k);
    }
    printLL(head);
}
