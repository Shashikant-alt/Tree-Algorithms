#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* CreateNode(int data)
{
    Node* NewNode = new Node(data);
    if(!NewNode)
    {
        cout << "\n Error.";
    }
    return NewNode;
}

void Inorder(Node* root)
{
    Node* temp = root;
    stack<Node*>s;
    while(temp != NULL || s.empty() == false)
    {
        while(temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
}

int main()
{
    Node* root = CreateNode(10);
    root->left = CreateNode(11);
    root->right = CreateNode(16);
    root->left->left = CreateNode(2);
    root->left->right = CreateNode(-1);
    root->right->left = CreateNode(10);
    root->right->left->left = CreateNode(9);
    root->right->left->right = CreateNode(11);
    cout << "\n Inorder traversal of tree : ";
    Inorder(root);
    return 0;
}