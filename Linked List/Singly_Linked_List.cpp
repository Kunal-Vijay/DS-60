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
    //insertion at beginning==O(1)
    if (index == 0)
    {
        newNode->next = startNode;
        startNode = newNode;
        return startNode;
    }
    //insertion at end== omega(n) -O(n)
    else if (index == -1)
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        return startNode;
    }
    //insertion in between== omega(1) - O(n)
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

//insertion after a node== omega(1) - O(n)
Node *insertAfter(Node *startNode)
{
    Node *newNode = new Node();
    Node *ptr = startNode;

    int value, nodebefore;
    cout << "Enter the value and value of node after which you want to insert the node:";
    cin >> value >> nodebefore;
    newNode->data = value;

    while (ptr->data != nodebefore && ptr != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        cout << "Node does not exist! can't insert" << endl;
        return startNode;
    }
    else
    {
        newNode->next = ptr->next;
        ptr->next = newNode;
        return startNode;
    }
}

//Deletion in a linked list
Node *deletion(Node *startNode)
{
    Node *ptr = startNode;

    int index;
    cout << "Enter the index of node to delete:";
    cin >> index;
    //deletion at beginning==O(1)
    if (index == 0)
    {
        startNode = startNode->next;
        delete ptr;
        return startNode;
    }
    //deletion at end== omega(n) -O(n)
    else if (index == -1)
    {
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        Node *temp = ptr->next;
        ptr->next = NULL;
        delete temp;
        return startNode;
    }
    //deletion in between== omega(1) - O(n)
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
        Node *temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
        return startNode;
    }
}

//deletion by value
Node *deleteByValue(Node *startNode)
{
    Node *ptr = startNode;

    int value;
    cout << "Enter the value of node  you want to delete:";
    cin >> value;
    if (startNode->data == value)
    {
        startNode = startNode->next;
        delete ptr;
        return startNode;
    }

    while (ptr->next->data != value && ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        cout << "Node does not exist!" << endl;
    }
    else
    {
        Node *temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    }
    return startNode;
}

//replace node
Node *replace(Node *startNode)
{
    int index, newValue;
    cout << "Enter the index of node and new value:";
    cin >> index >> newValue;
    Node *ptr = startNode;
    for (int i = 0; i < index && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        cout << "Entered Index exceeds the range! no chages occured" << endl;
    }
    else
    {
        ptr->data = newValue;
    }
    return startNode;
}

//searching in linked list
Node *search(Node *startNode)
{
    int value;
    cout << "Enter the value to search : ";
    cin >> value;
    Node *ptr = startNode;
    int count = 0;
    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            cout << "Node exist at index :" << count << endl;
            return startNode;
        }
        ptr = ptr->next;
        count++;
    }
    cout << "Linked list don't have node :" << value << endl;
    return startNode;
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
    // head = insertAfter(head);
    // print(head);
    // head = deletion(head);
    // print(head);
    // head = deletion(head);
    // print(head);
    // head = deletion(head);
    // print(head);
    head = deleteByValue(head);
    print(head);
    // head = replace(head);
    // print(head);
    // head = search(head);
    // print(head);
    return 0;
}