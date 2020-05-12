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
void printLL(node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

node* mergeLL(node* head1,node* head2)
{
    //base
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;

    //recursive
    node* newHead;
    if(head1->data<=head2->data)
    {
        newHead=head1;
        newHead->next = mergeLL(head1->next,head2);

    }else
    {
        newHead=head2;
        newHead->next = mergeLL(head1,head2->next);
    }
    return newHead;
}

int main()
{
    node *head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL;
    int n,m,data;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insertAtEnd(head1,tail1,data);
    }
    for(int i=0;i<m;i++)
    {
        cin>>data;
        insertAtEnd(head2,tail2,data);
    }

    head1 = mergeLL(head1,head2);
    printLL(head1);
    return 0;
}
