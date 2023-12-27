
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


 BstNode* Search(BstNode* root, int data)

{
    if(root==NULL)
        return NULL;

    if(root->data==data)
        return root;
    else
    {
        if(data<= root-> data)
        {
           return Search(root->left, data);
        }
        else
        {
           return Search(root->right, data);
        }
    }

}


int height(BstNode* root)
{
    if(root== NULL)
    {
        return -1;
    }

    else
        return max(height(root->left), height(root->right))+1;
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
    cout<<"Height of the tree is: "<<height(root)<<endl;
    cout<<"Enter a node's value to find the height of it: ";
    int n;
    cin>>n;
    BstNode* node= Search(root, n);
    if(node!=NULL)
    {
        cout<<"Height of node "<<n<<" is: "<<height(node)<<endl;
    }
    else
        cout<<"Error: Node not found"<<endl;
    return 0;
}

