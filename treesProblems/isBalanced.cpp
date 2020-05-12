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

node* buildBT(string s)
{
    if(s=="true")
    {
        int data;
        cin>>data;
        node* root=new node(data);
        string tmp;
        cin>>tmp;
        if(tmp=="true")
        {
            root->left=buildBT(tmp);
        }
        cin>>tmp;
        if(tmp=="true")
        {
            root->right=buildBT(tmp);
        }
        return root;
    }
    return NULL;
}

pair<int,bool> isBal(node *root)
{
    if(root==NULL)
        return make_pair(0,true);

    pair<int,bool> p,left,right;
    left=isBal(root->left);
    right=isBal(root->right);
    p.first= 1+ max(left.first,right.first);

    int diff=abs(left.first-right.first);
    if(diff<=1 && left.second && right.second )
        p.second=true;
    else
        p.second=false;
    return p;

}

int main()
{
    node *root=buildBT("true");
    pair<int,bool> p= isBal(root);
    if(p.second)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
