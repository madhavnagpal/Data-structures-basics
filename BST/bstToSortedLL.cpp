#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left,*right;
    node(int d)
    {
        data=d;
        left=right=NULL;
    }
};

node* insertInBST(node* root,int data)
{
    if(root==NULL)
    {
        root=new node(data);
        return root;
    }
    if(data <= root->data)
    {
        root->left = insertInBST(root->left,data);
        return root;
    }else
    {
        root->right = insertInBST(root->right,data);
        return root;
    }
}
int inp[]={8,3,10,1,6,7,4,14,13,-1};
node* createBST(node *root)
{
    int i=0;
    int data=inp[i++];
    while(data!=-1)
    {
        root = insertInBST(root,data);
        data=inp[i++];
    }
    return root;
}

class LinkedList
{
public:
    node *head,*tail;
    LinkedList()
    {
        head=tail=NULL;
    }
};

LinkedList BstToLl(node *root)
{
    LinkedList l;
    if(root==NULL)
        return l;
    if(root->left==NULL && root->right==NULL)
    {
        l.head=l.tail=root;
        return l;
    }else if(root->left!=NULL && root->right==NULL)
    {
        LinkedList left=BstToLl(root->left);
        left.tail->right=root;
        l.head=left.head;
        l.tail=root;
        return l;
    }else if(root->left==NULL && root->right!=NULL)
    {
        LinkedList right=BstToLl(root->right);
        root->right=right.head;
        l.head=root;
        l.tail=right.tail;
        return l;
    }else
    {
        LinkedList left=BstToLl(root->left);
        LinkedList right=BstToLl(root->right);
        left.tail->right=root;
        root->right=right.head;
        l.head=left.head;
        l.tail=right.tail;
        return l;
    }
}

void printll(node *head)
{
    cout<<"printing linked list"<<endl;
    while(head)
    {
        cout<<head->data<<" ";
        head=head->right;
    }
    cout<<endl;
}

int main()
{
    node *root=NULL;
    root=createBST(root);
    LinkedList ll = BstToLl(root);
    printll(ll.head);
    return 0;
}


