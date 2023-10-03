#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    node* next;

};
void Print(node* head)
{
    if(head==NULL)
        return;
    cout<<head->data<<" ";
    Print(head->next);
}

void ReversedPrint(node* head)
{
    if(head==NULL)
    {
        return;
    }

    ReversedPrint(head->next);
    cout<<head->data<<" ";
}

node* Insert(node* head, int data)
{
    node* temp= new node();
    temp->data= data;
    temp->next= NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node* temp1=head;
        while(temp1->next!= NULL)
        {
            temp1=temp1->next;
        }
        temp1->next= temp;

    }
    return head;
}

int main()
{
    node* head= NULL;
        head=Insert(head, 1);
        head=Insert(head, 2);
        head=Insert(head, 3);
        head=Insert(head, 4);
        head=Insert(head, 5);
        Print(head);
        cout<<"\n";
        ReversedPrint(head);
        return 0;
}
