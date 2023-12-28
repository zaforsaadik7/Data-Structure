#include<iostream>
using namespace std;
struct Node
{
char data;
Node* left;
Node* right;
};

Node* GetNewNode(char data)
{
    Node* NewNode= new Node;
    NewNode->data= data;
    NewNode->left=NULL;
    NewNode->right=NULL;
}

Node* Insert(Node* root, char data)
{
    if(root==NULL)
    {
        root=GetNewNode(data);
    }
    else if(data<= root->data)
    {
        root->left= Insert(root->left, data);
    }
    else
        root->right= Insert(root->right, data);
    return root;
}

void Preorder(Node* root)
{
if(root==NULL)
return;
cout<<root->data<<" ";
Preorder(root->left);
Preorder(root->right);
}

void Inorder(Node* root)
{
    if(root==NULL)
        return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node* root=NULL;
    root= Insert(root, 'F');
    root= Insert(root, 'D');
    root= Insert(root, 'J');
    root= Insert(root, 'B');
    root= Insert(root, 'E');
    root= Insert(root, 'G');
    root= Insert(root, 'K');
    root= Insert(root, 'A');
    root= Insert(root, 'C');
    root= Insert(root, 'I');
    root= Insert(root, 'H');
    cout<<"Preorder: ";
    Preorder(root);
    cout<<"\nInorder: ";
    Inorder(root);
    cout<<"\nPostorder: ";
    Postorder(root);
    return 0;
}
