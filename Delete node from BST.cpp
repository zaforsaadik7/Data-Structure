#include<iostream>
using namespace std;
struct Node
{
    Node* left;
    Node* right;
    int data;
};

Node* FindMin(Node* root)
{
    if(root == NULL)
        return NULL;
    else if(root->left == NULL)
        return root;
    else
        return FindMin(root->left);
}


Node* Delete(Node* root, int data) //this function is returning pointer to root node because the root node might change after the deletion
{
//To delete a given node, we first need to find it
    if(root==NULL)
        return root;

    else if(data< root->data)
        root->left= Delete(root->left, data); //Here we are setting the value of the left child because the left child of this node may change after the deletion. But as the Delete function returns the address we can set the value of the left child with the new address.

    else if(data> root->data)
        root->right= Delete(root->right, data);

    else //found the data
    {
//Case 1: No child or leaf node
        if(root->left==NULL && root->right==NULL)
        {
            delete root; //We need to return the address of the root to the parent node but as we have deleted it if we return this it'll become a dangling pointer so we need to set the address of root to null.
            root=NULL;
            return root;
        }

//Case 2: One child
        else if(root->left==NULL)
        {
//Store the address of the current node that we are going to delete
            Node* temp= root;
            root= root->right; //setting the value of the right child to the root
            delete temp;
            return root;
        }

        else if(root->right==NULL)
        {
            Node* temp= root;
            root= root->left;
            delete temp;
            return root;
        }
//If you have any confusion about why we moved the root to the left or right child, look at the case 2 explanation above and you'll understand.

//Case 3: Two children
        else
        {
//search for the minimum element of the right subtree
            Node* temp= FindMin(root->right);
            root->data= temp->data;
            root->right= Delete(root->right, temp->data); //deleting the duplicate from the right subtree.
            return root;
        }
    }
//Instead of returning the root after every condition we can just return the root at the end
//return root;
}

Node* GetNewNode(int data)
{
    Node* NewNode= new Node;
    NewNode->data= data;
    NewNode->left= NULL;
    NewNode->right= NULL;
    return NewNode;
}

Node* Insert(Node* root, int data)
{
    if(root==NULL)
        root= GetNewNode(data);

    else if(data<= root->data)
        root->left= Insert(root->left, data);

    else
        root->right= Insert(root->right, data);

    return root;
}

void Inorder(Node* root)
{
    if(root==NULL)
        return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int main()
{
    Node* root=NULL;
    root= Insert(root, 12);
    root= Insert(root, 5);
    root= Insert(root, 15);
    root= Insert(root, 3);
    root= Insert(root, 7);
    root= Insert(root, 13);
    root= Insert(root, 17);
    root= Insert(root, 1);
    root= Insert(root, 9);
    root= Insert(root, 14);
    root= Insert(root, 20);
    root= Insert(root, 8);
    root= Insert(root, 11);
    root= Insert(root, 18);
    cout<<"\nInorder: ";
    Inorder(root);
    Delete(root, 15);
    cout<<"\nAfter deleting node 15: ";
    Inorder(root);

    Delete(root, 8);
    cout<<"\nAfter deleting node 8: ";
    Inorder(root);

    Delete(root, 7);
    cout<<"\nAfter deleting node 7: ";
    Inorder(root);
    return 0;
}
