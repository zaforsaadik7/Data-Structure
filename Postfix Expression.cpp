#include<iostream>
#include<stack>
#include<cstring>
#include<cmath>
using namespace std;

int EvaluatePostfix(char *a)
{
    int n= strlen(a);
    stack <int> S;
    for (int i=0;i< n;i++)
    {
        if(a[i]== ' '||a[i]==',')
            continue;

        else if(isdigit(a[i]))
        {

            S.push(((int)a[i])-48);
        }
        else
        {
            int var2= S.top();
            S.pop();
            int var1=(int)S.top();
            S.pop();
            switch(a[i])
            {
                case'+': S.push(var1+var2); break;
                case'-': S.push(var1-var2);break;
                case'*': S.push(var1*var2);break;
                case'/': S.push( var1/var2);break;
                case'%': S.push(var1%var2);break;
                 case'^': S.push((int)pow(var1, var2)); break;

            }

        }
    }
    return S.top();
}


int main()
{
    char a[100];
    cout<<"enter a postfix expression: ";
    cin.getline(a,100);
    cout<<EvaluatePostfix(a)<<endl;
    return 0;
}

