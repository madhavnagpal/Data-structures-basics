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
    {
        head=tail=n;
    }else
    {
        tail->next=n;
        tail=n;
    }
}

node* kthElement(node* head,int k)
{
    node* fast=head,*slow=head;
    for(int i=0;i<k;i++)
    {
        if(fast==NULL)
            return NULL;
        fast=fast->next;
    }
    while(fast)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}

int main()
{
    node* head=NULL,*tail=NULL;
    int data;
    while(cin>>data)
    {
        if(data==-1)
            break;
        insertAtEnd(head,tail,data);
    }
    int k;
    cin>>k;
    node* tmp=kthElement(head,k);
    if(tmp==NULL)
        cout<<"Not Possible"<<endl;
    else
        cout<<tmp->data<<endl;
    return 0;
}
