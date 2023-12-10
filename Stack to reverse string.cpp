#include<iostream>
#include<cstring>
#include<stack>// stack from the standard template library(STL). This gives us a stack class without manually creating a class.
using namespace std;
void Reverse(char c[], int n)
{
//to use the stack class we need to write: stack<data type of the stack> (space)name/ identifier
    stack<char> S;
    for(int i=0; i<n; i++)
    {
        S.push(c[i]);
    }

    for(int i=0; i<n; i++)
    {
        c[i]=S.top();//overwrites the character at the index i
        S.pop();

    }
}
int main()
    {
    char c[51];
        cout<<"Enter a string:"<<endl;
        gets(c);
        Reverse(c, strlen(c));
        cout<<c<<endl;
        return 0;
    }
