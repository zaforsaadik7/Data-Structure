#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* right;
    Node* left;
};

Node* FindMin(Node* root)
{
    if(root==NULL)
        return NULL;
    else
    {
        while(root->left!=NULL)
        {
            root=root->left;
        }
        return root;
    }

}

Node* Find(Node* root, int data)
{
    if(root==NULL)
        return NULL;
    else if(root->data==data)
    {
        return root;
    }
    else
    {
        if(root->data<data)
        {
            Find(root->right, data);
        }
        else
            Find(root->left, data);
    }
}

Node* Getsuccessor(Node* root, int data)
{
    Node* current= Find(root, data); //this function will take the root and traverse the tree to find the node with the data and returns it
    if(current==NULL)
        return NULL;

    //Case 1: Node has right subtree
    if(current->right!=NULL) //we need to go to the left most node in the right subtree which we are doing in the while loop
    {

        while(current->right!=NULL)
        {
            return FindMin(current->right); //This function will return the minimum value of the right child's subtree
        }


    }

    //Case 2: No right subtree
    //if there is no right subtree, we need to walk the tree from root node to the current node and we need to find the deepest ancestor for which the current node is at the left
    else
    {
        Node* successor= NULL;
        Node* ancestor= root;
        while(ancestor!=current) //when nodes comes to the while loop successor can be either NULL or a node. Not all nodes in the tree will have a successor. Nodes with maximum value will not have a successor
        {
            if(current->data< ancestor->data) //if the data of the ancestor is greater than the data of the current node then there might be a chance that it is the successor of the current node
            {
                successor= ancestor;
                ancestor= ancestor-> left;
            }
        // while traversing if we find a deeper node with the property that current node will be in it's left subtree then the successor will be updated. If the current nodes is at the right then we simply need to move right which is at at the else part
            else
            {
                ancestor= ancestor->right;
            }
            return successor;
        }

    }

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
    cout<<"\nOriginal Tree: ";
    Inorder(root);
    cout<<"\n";
    int n;
    cout<<"Enter value of a node: ";
    cin>>n;
    if(Getsuccessor(root, n))
        cout<<"Node Found. Address: "<<Getsuccessor(root, n)<<endl;
    else
        cout<<"Error: Node Not Found."<<endl;
    return 0;
}
