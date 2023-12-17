#include<iostream>
using namespace std;

class Queue
{
    int front=-1;
    int rear=-1;
    int A[10];
    int N=10;
public:

    bool isEmpty()
    {
        if(front==-1&&rear==-1)
            return 1;
        else
            return 0;
    }

    void Enqueue(int n)
    {
        if((rear+1)%N==front)
        {
            cout<<"Queue is full."<<endl;
            return;
        }
        else if(isEmpty())
        {
            front=rear=0;
        }
        else
            rear=(rear+1)%N;
            A[rear]=n;
    }

    int Dequeue()
    {
        int item;
        if(isEmpty())
            {
                cout<<"Error: The queue is empty."<<endl;
                exit;
            }

            else if(front == rear)
            {
                front=-1;
                rear=-1;
            }
            else
            {
                front= (front+1)%N;
                item=A[front];
            }
            return item;
    }

    int Front()
    {
        if(isEmpty())
            {
                cout<<"Error: The queue is empty."<<endl;
                exit;
            }
        else
            return A[front];
    }

};


int main()
{
    Queue queue;
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
                queue.Enqueue(input);
                break;

            case 2:
                cout<<"Removed value is: "<< queue.Dequeue()<<endl;
                break;

            case 3:
                cout<<"Front of the queue: "<<queue.Front()<<endl;
                break;

            case 4:
                exit(0);

            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}
