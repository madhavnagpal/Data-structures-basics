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

int height(node* root)
{
    if(root==NULL)
        return 0;
    return max(height(root->left),height(root->right))+1;
}

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

int diameter(node *root)
{
    if(root==NULL)
        return 0;
    int op1 = height(root->left)+height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1,max(op2,op3));
}
class Pair
{
    public:
    int height,diameter;
};

Pair* fastDiameter(node* root)
{
    Pair* n =new Pair;
    if(root==NULL)
    {
        n->height=n->diameter=0;
        return n;
    }
    Pair* left = fastDiameter(root->left);
    Pair* right = fastDiameter(root->right);
    n->height = max(left->height,right->height)+1;
    int op1 = left->height + right->height;
    int op2 =left->diameter;
    int op3 =right->diameter;
    n->diameter = max(op1,max(op2,op3));
    return n;
}

int main()
{
    node *root= createBT();
    counter=0;
    cout<<"Diameter of Bt = ";
    cout<<diameter(root)<<endl;

    cout<<"\n Fasr Diameter of Bt = ";
    Pair* n =fastDiameter(root);
    cout<<n->diameter<<endl;

    return 0;
}
