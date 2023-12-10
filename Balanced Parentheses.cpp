#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

bool CheckParentheses(char *a)
{
    int n= strlen(a);
    stack <char> S;

    for(int i=0; i<n; i++)
    {
        if(a[i]=='('|| a[i]=='{'||a[i]=='[')
            S.push(a[i]);
        else if(a[i]==')'|| a[i]=='}'||a[i]==']')
        {
            if(S.empty() ||
              (a[i]==')' && S.top()!='(') ||
              (a[i]=='}' && S.top()!='{') ||
              (a[i]==']' && S.top()!='['))
                return false;
            else
                S.pop();
        }
    }
    return S.empty();
}

int main()
{
    int n=1;
    while(n)
    {
    char A[100];
    cout<<"Enter a Parentheses string: "<<endl;
    cin.getline(A, 100);
    if(CheckParentheses(A))
        cout<<"The parentheses are balanced."<<endl;
    else
        cout<<"The parentheses are not balanced."<<endl;

    cout<<"enter 0 to break: ";
    cin>>n;
    cin.ignore();
    }
    return 0;

}
