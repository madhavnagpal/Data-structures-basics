#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
void insertAtEnd(node* &head,int data)
{
    node* n=new node(data);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* curr=head;
    while(curr->next)
    {
        curr=curr->next;
    }
    curr->next=n;
    return;
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

void selectionSort(node* &head,int N)
{
    if(N<=1)
        return;
    node *curr=head,*prev=NULL;
    node *mini=curr,*prevMini=NULL;
    node *n=NULL;
    for(int i=1;i<N;i++)
    {
        node *tmp=curr;
        mini=curr;
        prevMini=prev;
        while(tmp && tmp->next)
        {
            n=tmp->next;
            if(n->data < mini->data)
            {
                mini=n;
                prevMini=tmp;
            }
            tmp=tmp->next;
        }

        if(mini!=curr)
        {
            //swapp mini and curr
            if(curr==head)
            {
                head=mini;
                if(curr->next==mini)
                {
                    curr->next=mini->next;
                    mini->next=curr;

                }else
                {
                    node *curNxt=curr->next;
                    curr->next=mini->next;
                    mini->next=curNxt;
                    prevMini->next=curr;
                }
            }else
            {
                if(curr->next==mini)
                {
                    curr->next=mini->next;
                    mini->next=curr;
                    prev->next=mini;

                }else
                {
                    node* curN=curr->next;
                    curr->next=mini->next;
                    mini->next=curN;
                    prev->next=mini;
                    prevMini->next=curr;
                }
            }
           curr=mini;
        }

        prev=curr;
        curr=curr->next;
    }
}

int main()
{
    node* head=NULL;
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insertAtEnd(head,data);
    }
    selectionSort(head,n);
    printLL(head);
    return 0;
}
