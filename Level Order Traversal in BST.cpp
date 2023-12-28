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
    Node* NewNode= new Node();
    NewNode->data= data;
    NewNode->left=NULL;
    NewNode->right=NULL;
    return NewNode;
}

Node* Insert(Node* root, char data)
{
    if(root==NULL)
    {
        root=GetNewNode(data);
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

struct Queue
{
    Node* address;
    Queue* next;
    Queue* Head;
    Queue* rear;

    Queue()
    {
        Head=NULL;
        rear= NULL;
    }
    void Enqueue(Node* x)
{
    Queue* temp = new Queue();
    temp->address = x;
    temp->next = NULL;
    temp->Head = NULL;
    temp->rear = NULL;
    if(Head == NULL && rear == NULL)
    {
        Head = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}



    void Dequeue()
{
    if(Head == NULL)
    {
        cout << "The queue is empty." << endl;
        return;
    }
    Queue* temp = Head;
    if(Head == rear)
    {
        Head = rear = NULL;
    }
    else
    {
        Head = Head->next;
    }
    delete temp;
}


    Node* Front()
    {
        return Head->address;
    }

    bool Empty()
    {
        if(Head==NULL && rear== NULL)
            return true;
        else
            return false;
    }
};

void LevelOrderPrint(Node* root)
{
    if(root==NULL)
    {
        return ;
    }
    Queue Q;
    Q.Enqueue(root);
    while(!Q.Empty())
    {
        Node* current= Q.Front();
        cout<<current->data<<", ";
        if(current->left!=NULL)
        {
            Q.Enqueue(current->left);
        }
        if(current->right!=NULL)
        {
            Q.Enqueue(current->right);
        }
        Q.Dequeue();
    }

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
    LevelOrderPrint(root);
    cout<<"\nthe Program is teminated."<<endl;
    return 0;
}
