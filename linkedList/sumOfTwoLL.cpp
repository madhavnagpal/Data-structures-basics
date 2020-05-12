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

void insertAtFront(node* &head,node* &tail,int data)
{
    node* n=new node(data);
    if(head==NULL)
    {
        head=tail=n;
    }else
    {
        n->next=head;
        head=n;
    }
}

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

int lengthLL(node* head)
{
    int counter=0;
    while(head)
    {
        counter++;
        head=head->next;
    }
    return counter;
}

node* sumll(node* h1,node* h2)
{
    //base
    if(h1==NULL && h2==NULL)
        return NULL;
    if(h1==NULL)
    {
        return h2;
    }
    if(h2==NULL)
    {
        return h1;
    }
    if(h1->next==NULL && h2->next==NULL)
    {
        int a=h1->data+h2->data;
        node* tmp1=new node(a%10);
        node* tmp2=new node(a/10);
        tmp2->next=tmp1;
        return tmp2;
    }

    //recursive
    int l1=lengthLL(h1);
    int l2=lengthLL(h2);
    if(l1==l2)
    {
         node* smaller = sumll(h1->next,h2->next);
        int data=h1->data+h2->data+smaller->data;
        smaller->data=data%10;
        node* tmp3=new node(data/10);
        tmp3->next=smaller;
        return tmp3;
    }else if(l1>l2)
    {
        node* smaller = sumll(h1->next,h2);
        int data=h1->data+smaller->data;
        smaller->data=data%10;
        node* tmp3=new node(data/10);
        tmp3->next=smaller;
        return tmp3;
    }else
    {
        node* smaller = sumll(h1,h2->next);
        int data=h2->data+smaller->data;
        smaller->data=data%10;
        node* tmp3=new node(data/10);
        tmp3->next=smaller;
        return tmp3;
    }

}

void printLL(node* head)
{
    if(head)
    {
        if(head->data>0)
        {
            cout<<head->data<<" ";
        }
        head=head->next;
    }
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    node *head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL;
    node* head3=NULL,*tail3=NULL;
    int n,m;
    cin>>n>>m;
    int data;
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
    head3=sumll(head1,head2);
    printLL(head3);
    return 0;
}
