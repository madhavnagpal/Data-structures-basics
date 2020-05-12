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
    node* n= new node(data);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node *curr=head;
    while(curr->next)
    {
        curr=curr->next;
    }
    curr->next=n;
    return;
}
void printLL(node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

node* selectionSort(node *head)
{
    //base
    if(head->next==NULL)
        return head;
    //recc
    //solve for 1
    node *mini=head,*prevMini=NULL;
    node *tmp=head,*n=NULL;
    while(tmp && tmp->next)
    {
        n=tmp->next;
        if(n->data < mini->data)
        {
            mini=n;
            prevMini=tmp;
        }
        tmp=tmp->next;
    }
    if(head!=mini)
    {
        if(head->next==mini)
        {
            n=head;
            head=mini;
            n->next=mini->next;
            head->next=n;
        }else
        {
            n=head;
            tmp=n->next;
            head=mini;
            n->next=mini->next;
            head->next=tmp;
            prevMini->next=n;
        }
    }
    //ask recursion to solve for n-1
    head->next = selectionSort(head->next);
    return head;
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
    head = selectionSort(head);
    printLL(head);
}
