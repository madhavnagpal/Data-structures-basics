#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

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



void printLinkedList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->left != NULL)
        {
            cout << "Left pointer for node with data=" << temp->data << " is changed to NULL" << endl;
        }
        cout << temp->data << " ";
        temp = temp->right;
    }
}


node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main()
{
    node *root = buildTree();

    LinkedList l = BstToLl(root);


    printLinkedList(l.head);

    return 0;
}

