#include<iostream>
using namespace std;

#define max 101

class Stack
{
    public:
    int a[max];
    int tos= -1;
    void push(int x)
    {
        if(tos== max-1)
        {
            cout<<"Error: stack overflow."<<endl;
            return;
        }
        a[++tos]=x;
    }

    void pop()
    {
        if(tos== -1)
        {
            cout<<"Error: Empty stack."<<endl;
            return;
        }
        tos--;
    }

    int top()
    {
        return a[tos];
    }

    int IsEmpty()
    {
        if(tos== -1)
        {
            return 1;
        }
        else
            return 0;
    }

    void print()
    {
        cout<<"Stack: "<<endl;
        for(int i=0; i<tos; i++)
        {
            cout<<a[i]<<endl;
        }
    }


};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    s.top();
    s.pop();
    s.pop();
    s.pop();
    if(s.IsEmpty())
        cout<<"Empty stack."<<endl;
    else
        cout<<"Not empty stack."<<endl;
    s.pop();
    s.pop();
    if(s.IsEmpty())
        cout<<"Empty stack."<<endl;


return 0;
}
