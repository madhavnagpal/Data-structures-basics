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

class Pair
{
public:
    int height;
    bool balanced;
};

Pair isBalanced(node *root)
{
    Pair curr;
    if(root==NULL)
    {
        curr.height=0;
        curr.balanced=true;
        return curr;
    }
    Pair left,right;
    left = isBalanced(root->left);
    right = isBalanced(root->right);
    curr.height = max(left.height,right.height)+1;
    int tmp = abs(left.height-right.height);
    if(tmp<=1 && right.balanced && left.balanced)
        curr.balanced=true;
    else
        curr.balanced=false;
    return curr;
}

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

node* createBST(node *root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root = insertInBST(root,data);
        cin>>data;
    }
    return root;
}

void printLevelOrder(node *root)
{
    if(root==NULL)
        return ;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            if(q.empty())
                {
                    cout<<endl;
                    break;
                }
            else
            {
                cout<<endl;
                q.push(NULL);
            }
        }else
        {
            cout<<curr->data<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
}

int main()
{
    node *root=NULL;
    root=createBST(root);
    printLevelOrder(root);
    Pair curr = isBalanced(root);
    if(curr.balanced)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}

