#include<iostream>
#include<cstdlib>
using namespace std;


class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
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
};


int main()
{

    Node ob1;
    ob1.head=NULL;
    ob1.InsertAtHead(2);
    ob1.InsertAtHead(4);
    ob1.InsertAtHead(6);
    ob1.InsertAtHead(8);
    ob1.InsertAtHead(10);
    ob1.Print();
    ob1.ReversePrint();


    ob1.InsertAtTail(1);
    ob1.InsertAtTail(3);
    ob1.InsertAtTail(5);
    ob1.InsertAtTail(7);
    ob1.InsertAtTail(9);
    ob1.Print();
    ob1.ReversePrint();
    return 0;
}

