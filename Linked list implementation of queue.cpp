#include<iostream>
using namespace std;
struct Node
{
int data;
Node* next;
};
Node* front=NULL;
Node* rear= NULL;

void Enqueue(int x)
{
Node* temp= new Node;
temp-> data= x;
temp->next= NULL;//NULL is a macro to the address zero
if(front==NULL && rear== NULL) //To check if the linked is empty
{
front= rear= temp;
return;
}
else
{
rear->next= temp; //setting the address part of the rear as the address of the newly created node
rear= temp; //pointing the rear to the newly created node as it is the tail of the current linked list
}
}

void Dequeue()
{
Node* temp= front;
if(front==NULL)
{
cout<<"The queue is empty."<<endl;
return;
}

if(front==NULL && rear== NULL)
{
front= rear= NULL;//the front and rear will be same only when there is just one element in the queue. so when we dequeue the element from the queue it will be empty that's why we are setting both front and rear to NULL
}
else
{
front= front->next;
}
free(temp);
}

int Front()
{
return front->data;
}

bool isEmpty()
{
if(front==NULL && rear== NULL)
return 1;
else
return 0;
}

int main()
{
   int choice;
    int input;
    while(1)
    {
        cout<<"1.Enqueue"<<endl;
        cout<<"2.Dequeue"<<endl;
        cout<<"3.Front"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter integer to input:";
                cin>>input;
                Enqueue(input);
                break;

            case 2:
                Dequeue();
                cout<<"Element is removed."<<endl;
                break;

            case 3:
                cout<<"Front of the queue: "<<Front()<<endl;
                break;

            case 4:
                exit(0);

            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
return 0;
}
