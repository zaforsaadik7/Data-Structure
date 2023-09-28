#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
    int data;
    Node* next; //stores the address of the next node

};

Node* head;

void insert(int x)
{
    Node* temp= new Node();
    temp->data=x;
    temp->next=head;
    head=temp;
}

void print()
{
    Node* temp=head;
    cout<<"The list is:";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

int main()
{
    head=NULL;
    cout<<"How many numbers:";
    int n,x;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"enter the number:";
        cin>>x;
        insert(x);
        print();

    }
}
