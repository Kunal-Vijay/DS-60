#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
public:
    Node *top;
    Stack() { top = NULL; }
    void push(int x);
    void pop();
    void peek();
    void show();
};

void Stack::push(int x)
{
    Node *ptr = new Node();
    if (ptr == NULL)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        ptr->data = x;
        ptr->next = top;
        top = ptr;
        cout << top->data << " is pushed successfully in the stack" << endl;
    }
}

void Stack::pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        Node *ptr = new Node();
        ptr = top;
        top = top->next;
        cout << ptr->data << " is popped from the stack" << endl;
    }
}

void Stack::peek()
{
    cout << top->data << endl;
}

void Stack::show()
{
    cout << "Stack:";
    Node *ptr = new Node();
    ptr = top;
    for (int i = 1; ptr != NULL; i++)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    s.pop();
    s.peek();
    s.pop();
    s.pop();
    s.peek();
    s.show();
    return 0;
}