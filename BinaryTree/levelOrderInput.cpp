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

node* createBTLevelOrderInput(node *root)
{
    int data;
    cin>>data;
    if(data==-1)
        return NULL;
    root = new node(data);
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node *curr=q.front();
        q.pop();
        //input two childrens
        int c1,c2;
        cout<<"enter childrens of "<<curr->data<<":\t";
        cin>>c1>>c2;
        if(c1!=-1)
        {
            curr->left = new node(c1);
            q.push(curr->left);
        }
        if(c2!=-1)
        {
            curr->right = new node(c2);
            q.push(curr->right);
        }
    }
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

node* mirrorImage(node *root)
{
    if(root==NULL)
        return NULL;
    swap(root->left,root->right);
    root ->left = mirrorImage(root->left);
    root ->right = mirrorImage(root->right);
    return root;
}


int main()
{
    node *root=NULL;
    root =createBTLevelOrderInput(root);
    cout<<"level order output"<<endl;
    printLevelOrder(root);
    root = mirrorImage(root);
    printLevelOrder(root);
    return 0;
}
