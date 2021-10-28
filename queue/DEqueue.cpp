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
    void enqueueRear(int element)
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
            cout << element << " pushed to the back of queue" << endl;
        }
    }

    void enqueueFront(int element)
    {
        int n = sizeof(arr);
        if (back == n - 1)
        {
            cout << "Queue overflow" << endl;
        }
        else
        {
            back++;
            int i=back;
            while(i){
                arr[i]=arr[i-1];
                i--;
            }
            if (front == -1)
            {
                front++;
            }
            arr[front]=element;
            cout << element << " pushed to the front of queue" << endl;
        }
    }

    void dequeueFront()
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

    void dequeueRear()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue Underflow" << endl;
        }
        else
        {
            cout << arr[back] << " is popped from queue" << endl;
            --back;
        }
    }

    int peekFront()
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

    int peekRear()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue Underflow" << endl;
            return NULL;
        }
        else
        {
            return arr[back];
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
    q.enqueueFront(1);
    cout<<q.isEmpty()<<endl;
    q.enqueueFront(2);
    q.enqueueRear(3);
    q.enqueueRear(4);
    q.enqueueRear(5);
    q.dequeueRear();
    q.dequeueRear();
    q.dequeueFront();
    cout<<q.peekRear()<<endl;
    cout<<q.peekFront()<<endl;
    return 0;
}