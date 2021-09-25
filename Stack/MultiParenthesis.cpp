#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int top;
    int size;

public:
    char arr[];
    Stack(int);
    void push(int x);
    char pop();
    bool isEmpty();
    bool isFull();
};

Stack::Stack(int length)
{
    size = length;
    arr[size];
    top = -1;
}

void Stack::push(int x)
{
    if (top < size - 1)
    {
        arr[++top] = x;
    }
}

char Stack::pop()
{
    if (top != -1)
    {
        char x = arr[top--];
        return x;
    }
    return 'z';
}

bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isFull()
{
    if (top == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int multiParenthesisMatch(string exp)
{
    int x = exp.length();
    Stack s((x / 2) + 1);
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '('||exp[i] == '['||exp[i] == '{')
        {
            if (s.isFull())
            {
                return 0;
            }
            else
            {
                s.push(exp[i]);
            }
        }
        if (exp[i] == ']'||exp[i] == ')'||exp[i] == '}')
        {
            if (s.isEmpty())
            {
                return 0;
            }
            else
            {
                char pop=s.pop();
                if(exp[i]==')'&&pop=='('||exp[i]=='}'&&pop=='{'||exp[i]==']'&&pop=='['){
                    
                }else{
                    return 0;
                }
            }
        }
    }
    if(s.isEmpty()){
        return 1;
    }
    return 0;
}

int main()
{
    string exp;
    cout<<"Enter the expression:";
    cin>>exp;
    if (multiParenthesisMatch(exp))
    {
        cout<<"Matched"<<endl;
    }
    else
    {
        cout<<"Not Matched"<<endl;
    }
    return 0;
}