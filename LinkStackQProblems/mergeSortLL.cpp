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

void insertAtEnd(node* &head,int data)
{
    node* n=new node(data);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node *prev=NULL,*curr=head;
    while(curr)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=n;
    return;
}
node* mergeLL(node* first,node* second)
{
    //base
    if(first==NULL && second==NULL)
        return first;
    if(first==NULL)
        return second;
    if(second==NULL)
        return first;
    //recursive
    if(first->data < second->data)
    {
        node *n=first;
        n->next = mergeLL(first->next,second);
        return n;
    }else
    {
        node *n=second;
        n->next = mergeLL(first,second->next);
        return n;
    }
}

node* findMid(node* head)
{
    node *slow=head,*fast=head->next;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* mergeSort(node* head)
{
    //base
    if(head==NULL || head->next==NULL)
        return head;
    node* middy=findMid(head);
    node* midNxt=middy->next;
    middy->next=NULL;

    node *first =mergeSort(head);
    node *second =mergeSort(midNxt);
    return mergeLL(first,second);
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
int main()
{
    node *head=NULL;
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insertAtEnd(head,data);
    }
    head = mergeSort(head);
    printLL(head);
    return 0;
}
