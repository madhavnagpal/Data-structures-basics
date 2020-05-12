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

void insertAtEnd(node* &head , node* &tail , int data)
{
    node* n= new node(data);
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
int lengthLL(node *head)
{
    int counter=0;
    while(head)
    {
        counter++;
        head=head->next;
    }
    return counter;
}
void bubbleSort(node* &head,node* &tail)
{
    int N=lengthLL(head);
    node *curr,*prev,*n;
    for(int i=0;i<N-1;i++)
    {
        curr=head;
        prev=NULL;

        for(int j=0;j<N-1-i;j++)
        {
            n=curr->next;
            if(curr->data>n->data)
            {
                //swap req
                if(curr==head)
                {
                    curr->next=n->next;
                    n->next=curr;
                    prev=head=n;
                }else
                {
                    curr->next=n->next;
                    n->next=curr;
                    prev->next=n;
                    prev=n;
                }
            }else
            {
                prev=curr;
                curr=curr->next;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    node *head=NULL,*tail=NULL;
    int data;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insertAtEnd(head,tail,data);
    }
    bubbleSort(head,tail);
    printLL(head);
    return 0;
}

