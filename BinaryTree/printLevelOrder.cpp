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

void printLevelOrder(node *root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *n = q.front();
        q.pop();
        if(n==NULL)
        {
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }else
        {
            cout<<n->data<<" ";
            node *left=n->left;
            node *right=n->right;
            if(left)
                q.push(left);
            if(right)
                q.push(right);
        }
    }
}

int main()
{
    node *root= createBT();
    counter=0;
    printLevelOrder(root);
    return 0;
}
