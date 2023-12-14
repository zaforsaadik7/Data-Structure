#include<iostream>
#include<cstring>
#include<stack>
#include <cctype> // to check digits and letters for operand
using namespace std;



bool isoperand(char a)
{
    return isdigit(a)||islower(a)||isupper(a);
}


bool IsOpeningParentheses(char b)
{
    if(b=='('||b=='{'||b=='[')
        return 1;
    else
        return 0;
}


bool IsClosingParentheses(char d)
{
    if(d==')'||d==']'||d=='}')
        return 1;
    else
        return 0;
}


bool HasHigherPrec(char top, char c)
{
    if(top=='*'&&c=='+'||c=='-')
        return 1;
    else if(top=='/'&& c=='*'||c=='+'||c=='-')
        return 1;
    else if(top=='+'&&c=='-')
        return 1;
    else
        return 0;
}

bool IsOperator(char c)
{
    if(c=='+'||c=='-'||c=='/'||c=='*')
        return 1;

    else
    return 0;
}

string InfixToPostfix(string exp)
{
    stack <char> s;
    string result;

    for(int i=0; i<exp.length(); i++)
    {
        if(isoperand(exp[i]))
            result+=exp[i];
        else if(IsOperator(exp[i]))
        {

            while(!s.empty()&& !IsOpeningParentheses(s.top()) &&HasHigherPrec(s.top(), exp[i]) )
            {
                result+=s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
        else if (IsOpeningParentheses(exp[i]))
            s.push(exp[i]);

        else if (IsClosingParentheses(exp[i]))
        {
            while(!s.empty()&&!IsOpeningParentheses(s.top()))
            {
                result+=s.top();
                s.pop();
            }
            s.pop();
        }


    }
    while(!s.empty())
    {
        result+=s.top();
        s.pop();
    }

    return result;
}



int main()
{
    string infix;
    cout<<"Enter an infix expression: ";
    getline(cin,infix);
    cout<<"Infix: "<<infix<<" Postfix: "<<InfixToPostfix(infix)<<endl;
    return 0;
}
