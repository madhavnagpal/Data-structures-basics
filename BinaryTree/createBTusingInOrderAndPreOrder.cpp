#include<bits/stdc++.h>
using namespace std;

int pre[]={8,3,1,6,4,7,10,14,13};
int in[]={1,3,4,6,7,8,10,13,14};
int countPre=0;
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

node* createBT(int s,int e)
{
    //base
    if(s>e)
        return NULL;
    int data =pre[countPre++];
    node *root=new node(data);
    //recc
    int j=-1;
    for(int i=s;i<=e;i++)
    {
        if(in[i]==data)
        {
            j=i;
            break;
        }
    }
    root->left=createBT(s,j-1);
    root->right=createBT(j+1,e);

    return root;
}

void printLevelOrder(node *root)
{
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *first=q.front();
        q.pop();

        if(first==NULL)
        {
            if(q.empty())
            {
                cout<<endl;
               break;
            }else
            {
                cout<<endl;
                q.push(NULL);
            }
        }else
        {
            cout<<first->data<<" ";
            if(first->left!=NULL)
                q.push(first->left);
            if(first->right!=NULL)
                q.push(first->right);
        }
    }

}
int main()
{
    node *root=createBT(0,8);
    cout<<"Our tree is"<<endl;
    printLevelOrder(root);
    return 0;
}
