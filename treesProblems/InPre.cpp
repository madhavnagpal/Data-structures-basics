#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data ;
    node* left,*right;
    node(int d)
    {
        data=d;
        left=right=NULL;
    }
};

int pre[10000]={0},in[10000]={0};
int preCounter=0;

node* createBt(int s,int e)
{
    if(s>e)
        return NULL;
    int data= pre[preCounter++];
    node *root=new node(data);
    //find j
    int j=-1;

    for(int i=s;i<=e;i++)
    {
        if(data == in[i])
        {
            j=i;
            break;
        }
    }

    root->left= createBt(s,j-1);
    root->right=createBt(j+1,e);
    return root;
}
void printT(node* root)
{
    if(root==NULL)
        return;
    if(root->left==NULL)
        cout<<"END => ";
    else
        cout<<root->left->data<<" => ";
    cout<<root->data<<" <= ";
    if(root->right==NULL)
        cout<<"END"<<endl;
    else
        cout<<root->right->data<<endl;

    printT(root->left);
    printT(root->right);

}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>pre[i];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>in[i];
    node* root= createBt(0,n-1);
    printT(root);
    return 0;
}
