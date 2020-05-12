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

bool isBST(node *root,int maxi=INT_MAX,int mini=INT_MIN)
{
    if(root==NULL)
        return true;
    if(root->data <=maxi && root->data>=mini)
    {
        bool left = isBST(root->left,root->data,mini);
        bool right = isBST(root->right,maxi,root->data);
        if(left && right)
            return true;
    }
    return false;
}

int main()
{
    node *root=NULL;
    root=createBST(root);
    printLevelOrder(root);
    bool bst = isBST(root);
    if(bst)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}

