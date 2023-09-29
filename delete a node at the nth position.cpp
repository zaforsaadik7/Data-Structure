#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    node* next;
};

node* head;
void insert(int data) // inserts the value at the  end of the list
{
    node* temp= new node();
    temp->data= data;
    temp->next=NULL;
    if(head == NULL)
    {
        head= temp;
        return;
    }
    node* temp1;
    temp1= head;
    while(temp1->next != NULL)
    {
        temp1= temp1->next;
    }
    temp1->next=temp;

}

void print()
{
    node* temp= head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";

}

void Delete(int n)
{
    if(n==1)
    {
        node* temp = head;
        head= head->next;
        delete temp;
        return;
    }

    node* temp1=head;
    for(int i=0; i<n-2;i++)
    {
        temp1=temp1->next;

    }

    node* temp2=temp1->next;
    temp1->next= temp2->next;
    delete temp2;

}

int main()
{
    head= NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    int n;
    cout<<"Enter a position:";
    cin>>n;
    Delete(n);
    print();

}
