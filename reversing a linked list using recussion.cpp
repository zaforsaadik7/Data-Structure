#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    node* next;
};

node* head = NULL;

void Print()
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void Reverse(node* p)
{
    if(p->next == NULL)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    node* q = p->next;
    q->next = p;
    p->next = NULL;
}

void Insert(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        return;
    }
    node* temp1 = head;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

int main()
{
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    
    Print();
    
    Reverse(head);
    
    Print();
    
    return 0;
}
