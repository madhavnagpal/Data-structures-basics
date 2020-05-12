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



void printLL(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

bool searchRec(node* head,int data)
{
    if(head==NULL)
        return false;
    if(head->data==data)
        return true;
    return searchRec(head->next,data);

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
    printLL(head);
    if(searchRec(head,5))
        cout<<"Node Found"<<endl;
    else
        cout<<"Node not found"<<endl;
    return 0;
}

