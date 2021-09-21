#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int top;
    int size;

public:
    int arr[];
    Stack();
    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

Stack::Stack()
{
    cout << "Enter the size of stack:";
    cin >> size;
    arr[size];
    top = -1;
}

void Stack::push(int x)
{
    if (top==size-1)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        arr[++top] = x;
        cout << x << " is successfully pushed to stack" << endl;
    }
}

int Stack::pop()
{
    if (top==-1)
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else
    {
        int x = arr[top--];
        return x;
    }
}

int Stack::peek()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else
    {
        return arr[top];
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

int main()
{
    Stack s;
    int cmd;
    // do
    // {
    //     cout << ">";
    //     cin >> cmd;
        s.push(5);
        s.push(10);
        s.push(15);

        cout<<s.peek()<<endl;
        cout<<s.pop()<<endl;
    //     switch (cmd)
    //     {
    //     case 1:
    //         int x;
    //         cout << "Enter value to push:";
    //         cin >> x;
    //         s.push(x);
    //         break;

    //     case 2:
    //         cout << s.pop() << " is popped from the stack" << endl;
    //         break;

    //     case 3:
    //         cout << "Peeked element" << s.peek() << endl;
    //         break;
    //     case 4:
    //         cout << bool(s.isEmpty()) << endl;
    //         break;
    //     case 5:
    //         cout << s.isFull() << endl;
    //         break;

    //     case 0:
    //         exit(0);
    //         break;

    //     default:
    //         cout << "Invalid operation! Pls select the operation again" << endl;
    //         break;
    //     }

    // } while (cmd != 0);

    return 0;
}