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

node* reverseRec(node* head,node* prev)
{
    //base
    if(head==NULL || head->next==NULL)
    {
        head->next=prev;
        return head;
    }
    //recursive
    node* n =head->next;
    head->next=prev;
   // n->next=head;
    return reverseRec(n,head);
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
    head = reverseRec(head,NULL);
    printLL(head);
    return 0;
}
