#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int top;
    int size;

public:
    int arr[];
    Stack(int);
    void push(int x);
    void pop();
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

void Stack::pop()
{
    if (top != -1)
    {
        int x = arr[top--];
    }
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

int parenthesisMatch(string exp)
{
    int x = exp.length();
    Stack s((x / 2) + 1);
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(')
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
        if (exp[i] == ')')
        {
            if (s.isEmpty())
            {
                return 0;
            }
            else
            {
                s.pop();
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
    if (parenthesisMatch(exp))
    {
        cout<<"Matched"<<endl;
    }
    else
    {
        cout<<"Not Matched"<<endl;
    }
    return 0;
}