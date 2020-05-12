#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void printLinkedList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->left != NULL)
        {
            cout << "Left pointer for node with data=" << temp->data << " is changed to NULL" << endl;
        }
        cout << temp->data << " ";
        temp = temp->right;
    }
}









int main()
{
    node *root = buildTree();

    LinkedList l = BtToLl(root);


    printLinkedList(l.head);

    return 0;
}
