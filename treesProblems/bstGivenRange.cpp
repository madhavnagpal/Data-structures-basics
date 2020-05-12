#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* left,*right;
    node(int d)
    {
        data=d;
        left=right=NULL;
    }
};

node* insertInBst(node *root,int data)
{
    if(root==NULL)
    {
        root=new node(data);
        return root;
    }
    if(data<=root->data)
    {
        root->left=insertInBst(root->left,data);
        return root;
    }
    root->right=insertInBst(root->right,data);
    return root;

}
int a[100]={0};

void preOrder(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}
void pp(node* root,int mini ,int maxi)
{
    if(root==NULL)
        return;
    pp(root->left,mini,maxi);
    if(root->data>=mini  && root->data<=maxi)
        cout<<root->data<<" ";
    pp(root->right,mini,maxi);
}



int main()
{
    int ti;
    cin>>ti;
    while(ti--)
    {
        int n,k1,k2;
        cin>>n;
        node* root=NULL;
        for(int i=0;i<n;i++)
            {
                cin>>a[i];
                root = insertInBst(root,a[i]);
            }
        cin>>k1>>k2;
        cout<<"# Preorder : ";
        preOrder(root);
        cout<<"\n# Nodes within range are : ";
        pp(root,k1,k2);
        cout<<endl;
    }
}

