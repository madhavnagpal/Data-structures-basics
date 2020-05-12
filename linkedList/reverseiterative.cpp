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
} ;

void insertAtEnd(node* &head,node* &tail,int data)
{
    node* n= new node(data);
    if(head==NULL)
    {
        head=tail=n;
    }else
    {
        tail->next=n;
        tail=n;
    }
}

node* reverseIt(node* head)
{
    node *prev=NULL;
    node* curr=head;
    while(curr)
    {
        node *n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    return prev;

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
    node* head=NULL,*tail=NULL;
    int n;
    cin>>n;
    int data;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insertAtEnd(head,tail,data);
    }
    head = reverseIt(head);
    printLL(head);
    return 0;
}

