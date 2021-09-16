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
    cout << "Enter number of nodes:";
    cin >> n;
    cout << "Enter nodes:";
    cin >> startNode->data;
    startNode->next = NULL;
    tempNode = startNode;

    for (int i = 1; i < n; i++)
    {
        newNode = new Node();

        cin >> newNode->data;
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
    cout << endl;
}

//insertion in linked list by index
Node *insert(Node *startNode)
{
    Node *newNode = new Node();
    Node *ptr = startNode;

    int value, index;
    cout << "Enter the value and index of node:";
    cin >> value >> index;
    newNode->data = value;
    if (index == 0)
    {
        newNode->next = startNode;
        startNode = newNode;
        return startNode;
    }
    else if (index == -1)
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        return startNode;
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            if (ptr->next == NULL)
            {
                cout << "index exceeds last node!! Node not inserted" << endl;
                return startNode;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
        return startNode;
    }
}

//insertion after a node
Node * insertAfter(Node*startNode){
    Node *newNode = new Node();
    Node *ptr = startNode;

    int value, nodebefore;
    cout << "Enter the value and value of node after which you want to insert the node:";
    cin >> value >> nodebefore;
    newNode->data = value;

    while(ptr->data!=nodebefore&&ptr!=NULL){
        ptr=ptr->next;
    }
    if(ptr==NULL){
        cout << "Node does not exist! can't insert" << endl;
        return startNode;
    }else{
        newNode->next=ptr->next;
        ptr->next=newNode;
        return startNode;
    }
}
int main()
{
    Node *head;
    head = new Node();

    createList(head);
    print(head);
    // head = insert(head);
    // print(head);
    // head = insert(head);
    // print(head);
    // head = insert(head);
    // print(head);
    head = insertAfter(head);
    print(head);
    return 0;
}