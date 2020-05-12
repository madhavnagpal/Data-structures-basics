#include<bits/stdc++.h>
using namespace std;

int tree[]={8,3,1,-1,-1,6,4,-1,-1,7,-1,-1,10,-1,14,13,-1,-1,-1},counter=0;
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

node* createBT()
{
    int data;
    data = tree[counter];
    counter++;
    if(data==-1)
        return NULL;
    node *n=new node(data);
    n->left = createBT();
    n->right = createBT();
    return n;
}

void preOrder(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}
void postOrder(node* root)
{
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    return;
}
void inOrder(node* root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    return;
}

int countNodes(node* root)
{
    if(root==0)
        return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}

int height(node* root)
{
    if(root==NULL)
        return 0;
    return max(height(root->left),height(root->right))+1;
}

int main()
{
    node *root= createBT();
    counter=0;
    //preOrder
    cout<<"Pre order"<<endl;
    preOrder(root);
    cout<<"\n Post order"<<endl;
    postOrder(root);
    cout<<"\n In order"<<endl;
    inOrder(root);
    cout<<"\n \n Number of nodes = ";
    cout<<countNodes(root)<<endl;
    cout<<"\n Depth/Height of tree : ";
    cout<<height(root)<<endl;

    return 0;
}
