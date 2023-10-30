#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* head;
Node* GetNewNode(int x)
{
    Node* newNode= new Node;
    newNode-> data= x;
    newNode->prev= NULL;
    newNode-> next= NULL;
    return newNode;
}

void InsertAtHead(int x)
{
    Node* newNode= GetNewNode(x);
    if(head==NULL)
    {
        head= newNode;
        return;
    }

    head->prev=newNode;
    newNode->next=head;
    head= newNode;
}

void InsertAtTail(int x)
{
   Node* newNode=GetNewNode(x);
    if(head==NULL)
    {
        head= newNode;
    }
    Node* temp= head;
    while(temp->next!=NULL)
    {
        temp= temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void Print()
{
    Node* temp= head;
    cout<<"Forward printing:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<"\n";
}

void ReversePrint()
{
    Node* temp= head;
    if(temp== NULL)
        return;
    while(temp->next!=NULL)
    {
        temp= temp->next;
    }
    cout<<"Printing reverse:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->prev;
    }
    cout<<"\n";
}

int main()
{
    head=NULL;

    InsertAtHead(2);
    InsertAtHead(4);
    InsertAtHead(6);
    InsertAtHead(8);
    InsertAtHead(10);
    Print();
    ReversePrint();


    InsertAtTail(1);
    InsertAtTail(3);
    InsertAtTail(5);
    InsertAtTail(7);
    InsertAtTail(9);
    Print();
    ReversePrint();
    return 0;
}
