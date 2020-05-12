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

int a[]={1,2,3,4,5,6,7,8,9};

node* arrayToBalancedBST(int first,int last)
{
    if(first>last)
        return NULL;
    int mid = (first+last)/2;
    node *root = new node(a[mid]);
    root->left = arrayToBalancedBST(first,mid-1);
    root->right = arrayToBalancedBST(mid+1,last);
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
    root = arrayToBalancedBST(0,8);
    printLevelOrder(root);
    return 0;
}
