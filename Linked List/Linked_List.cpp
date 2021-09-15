#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void createList(Node *startNode)
{
    Node *newNode;
    Node *tempNode;
    int n;
    cout<<"Enter number of nodes:";
    cin>>n;
    cout<<"Enter nodes:";
    cin>>startNode->data;
    startNode->next = NULL;
    tempNode = startNode;

    for (int i=1; i < n; i++)
    {
        newNode=new Node();

        cin>>newNode->data;
        newNode->next = NULL;

        tempNode->next = newNode;
        tempNode = tempNode->next;
    }
}

void print(Node *ptr)
{
    cout << "List:";
    for (int i = 1; ptr != NULL; i++)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    Node *head;
    head = new Node();

    createList(head);
    print(head);
    return 0;
}