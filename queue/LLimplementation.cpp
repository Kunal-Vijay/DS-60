#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    node *front;
    node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    void enqueue(int val)
    {
        node *n = new node(val);
        if (front == NULL)
        {
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void dequeue()
    {
        node *n = front;
        if (front == back)
        {
            front = NULL;
            back = NULL;
        }
        else
        {
            front = front->next;
        }
        delete n;
    }
    int peek()
    {
        if (front != NULL)
            return front->data;
        else
            return NULL;
    }
    bool isEmpty(){
        if (front == NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    Queue q;
    cout<<q.isEmpty()<<endl;
    q.enqueue(1);
    cout<<q.isEmpty()<<endl;
    q.enqueue(2);
    cout<<q.peek()<<endl;
    q.enqueue(3);
    cout<<q.peek()<<endl;
    q.enqueue(4);
    cout<<q.peek()<<endl;
    q.enqueue(5);
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    return 0;
}