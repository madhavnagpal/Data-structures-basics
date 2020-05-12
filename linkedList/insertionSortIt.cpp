#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next=NULL;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
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
node* insSort(node* head,int N)
{
    //base
    if(N==1)
    {
        return head;
    }
    // reccursive
    head = insSort(head,N-1);
    node* curr=head,*prev=NULL,*n=NULL;

    for(int i=1;i<N;i++)
    {
        prev=curr;
        curr=curr->next;
    }
    n=curr->next;
    prev->next=n;
    n=head;
    prev=NULL;

    for(int i=1;i<N;i++)
    {
        if(n->data>curr->data)
        {
            if(n==head)
            {
                curr->next=head;
                head=curr;
                return head;
            }else
            {
              prev->next=curr;
              curr->next=n;
              return head;
            }
        }
        prev=n;
        n=n->next;
    }
    prev->next=curr;
    curr->next=n;
    return head;
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
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insertAtEnd(head,tail,data);
    }
    int N=lengthLL(head);
    head = insSort(head,N);
    printLL(head);
    return 0;
}
