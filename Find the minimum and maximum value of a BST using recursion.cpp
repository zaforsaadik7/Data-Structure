#include<iostream>
using namespace std;
struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data)
{
    BstNode* NewNode= new BstNode();
    NewNode->data=data;
    NewNode->left=NULL;
    NewNode->right= NULL;
    return NewNode;
}

BstNode* Insert(BstNode* root, int data)
{
    if(root==NULL)
    {
        root= GetNewNode(data);
    }
    else if(data<=root->data)
    {
        root->left=Insert(root->left, data);
    }
    else
    {
        root->right=Insert(root->right, data);
    }
    return root;
}

int FindMin(BstNode* root)
{
    if(root==NULL)
    {
        cout<<"Error: tree is empty."<<endl;
        return -1;
    }

    else if(root->left==NULL)
    {
        return root-> data;
    }
    else
        return FindMin(root->left);
}
int FindMax(BstNode* root)
{
    if(root==NULL)
    {
        cout<<"Error: Tree is empty."<<endl;
        return -1;
    }
   else if(root->right==NULL)
    {
        return root-> data;
    }
    else
        return FindMin(root-> right);
}

int main()
{
    BstNode* root= NULL;
    root= Insert(root, 15);
    root= Insert(root, 10);
    root= Insert(root, 20);
    root= Insert(root, 25);
    root= Insert(root, 8);
    root= Insert(root, 12);
    cout<<"minimum value: "<<FindMin(root)<<endl;
    cout<<"maximum value: "<<FindMax(root)<<endl;
    return 0;
}

