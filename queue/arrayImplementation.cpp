#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int front;
    int back;

public:
    Queue(int n=100)
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void enqueue(int element)
    {
        int n = sizeof(arr);
        if (back == n - 1)
        {
            cout << "Queue overflow" << endl;
        }
        else
        {
            back++;
            arr[back] = element;
            if (front == -1)
            {
                front++;
            }
            cout << element << " pushed to queue" << endl;
        }
    }

    void dequeue()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue Underflow" << endl;
        }
        else
        {
            cout << arr[front] << " is popped from queue" << endl;
            ++front;
        }
    }
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue Underflow" << endl;
            return NULL;
        }
        else
        {
            return arr[front];
        }
    }
    bool isEmpty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    
    Queue q;
    cout<<q.isEmpty()<<endl;
    q.enqueue(1);
    cout<<q.isEmpty()<<endl;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.peek()<<endl;
    return 0;
}