#include<iostream>
using namespace std;

struct node
{
    node* next;
    int data;
};

node* head;
node* Reverse(node* head)
{
    node* current, *prev, *next;
    current= head;
    prev= NULL;
    while(current!=NULL)
    {
        next= current->next;
        current->next=prev;
        prev=current;
        current= next;

    }
    head= prev;
    return head;
}
node* Insert(node* head, int data)
{
    node* temp= new node();
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node* temp1= head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    return head;
}


void Print(node* head)
{
    node* temp= head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;

    }
}


int main()
{
    node* head= NULL;
    head=Insert(head, 2);
    head=Insert(head, 4);
    head=Insert(head, 6);
    head=Insert(head, 8);
    Print(head);
    head= Reverse(head);
    cout<<"\n";
    Print(head);
    return 0;
}
