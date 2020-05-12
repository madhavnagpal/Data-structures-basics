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

node* findMid(node* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* mergeSort(node* head)
{
    //base
    if(head==NULL ||head->next==NULL)
        return head;
    //recursive
    //divide
    node* mid=findMid(head);
    node* n=mid->next;
    mid->next=NULL;
    node* a=mergeSort(head);
    node* b=mergeSort(n);

    return mergeLL(a,b);

}

int main()
{
    node *head=NULL,*tail=NULL;
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insertAtEnd(head,tail,data);
    }

    head = mergeSort(head);
    printLL(head);
    return 0;
}
