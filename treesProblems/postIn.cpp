#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(int i=0;i<n;i++)

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

int post[1000]={0},in[1000]={0};
int counter;

node* createT(int s,int e)
{
    if(s>e)
        return NULL;
    int data=post[counter];
    int j=-1;
    for(int i=s;i<=e;i++)
    {
        if(in[i]==data)
        {
            j=i;
            counter--;
            break;
        }
    }
    if(j==-1)
        return NULL;
    node*root=new node(data);
    root->right=createT(j+1,e);
    root->left= createT(s,j-1);
    return root;
}

void printT(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    printT(root->left);
    printT(root->right);
    return;
}

int main()

{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        fo(i,n)
            cin>>in[i];
        fo(i,n)
            cin>>post[i];
        counter=n-1;
        node* root=NULL;
        root= createT(0,n-1);
        printT(root);
    }
    return 0;

}
