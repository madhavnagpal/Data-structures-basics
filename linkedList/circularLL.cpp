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

bool detectCycle(node* head)
{
    if(head==NULL ||head->next==NULL)
        return false;
    node* slow=head;
    node* fast=head;
    node* prev=NULL;
    while(fast)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
            return true;
    }
    return false;

}

node* removeCycle(node* head)
{
    node* slow=head;
    node* fast=head;
    node* prev=NULL;
    while(fast)
    {
        prev=fast;
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        {
            prev=prev->next;
            break;
        }
    }
    node* tmp=head;
    while(tmp->data!=fast->data)
    {
        tmp=tmp->next;
        fast=fast->next;
        prev=prev->next;
    }
    prev->next=NULL;
    return head;
}

int main()
{
    int a[100000]={0};
    int data,n=0;
    while(cin>>data)
    {
        if(data==-1)
            break;
        a[n++]=data;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                data=a[i++];
                n=j;
            }
        }
    }
    node* head=NULL,*tail=NULL;
    for(int i=0;i<n;i++)
        insertAtEnd(head,tail,a[i]);

    node* tmp=head;
    while(tmp->data!=data)
        tmp=tmp->next;
    tail->next=tmp;
    bool isCyclic = detectCycle(head);
    if(isCyclic)
    {
        head = removeCycle(head);
    }
    printLL(head);
    return 0;
}
