#include <bits/stdc++.h>
// #include "../binaryTreenode.h"
#include "BSTclass.h"
using namespace std;

BinaryTreenode<int> *takeInputLevelWise()
{
    int rootData;
    // cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreenode<int> *root = new BinaryTreenode<int>(rootData);

    queue<BinaryTreenode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreenode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        // cout << "Enter left child of" << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreenode<int> *child = new BinaryTreenode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        // cout << "Enter right child of" << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreenode<int> *child = new BinaryTreenode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printBTlevelWise(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreenode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreenode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << " L:" << front->left->data;
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << " R:" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}

// Problem 1 - Search in BST
bool searchBST(BinaryTreenode<int> *root, int node)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == node)
    {
        return true;
    }
    else if (root->data > node && searchBST(root->left, node))
    {
        return searchBST(root->left, node);
    }
    else
    {
        return searchBST(root->right, node);
    }
}

// Problem 2 - Print in Range
void PrintInRange(BinaryTreenode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data < min)
    {
        PrintInRange(root->right, min, max);
    }
    if (root->data > max)
    {

        PrintInRange(root->left, min, max);
    }
    if (root->data >= min && root->data <= max)
    {
        cout << root->data << endl;
        PrintInRange(root->left, min, max);
        PrintInRange(root->right, min, max);
    }
}

// Problem 3 - Check BST  - O(nh)
int minimum(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool checkBST(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data > leftMax) && (root->data <= rightMin) && checkBST(root->left) && checkBST(root->right);
    return output;
}

// Check BST - better approach  - O(n)

bool checkBST2(BinaryTreenode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }
    bool isLeftOk = checkBST2(root->left, min, root->data - 1);
    bool isRightOk = checkBST2(root->right, root->data, max);
    return isLeftOk && isRightOk;
}

// Problem 4 - BST from sorted array
BinaryTreenode<int> *arrayBST(vector<int> arr, int startIndex, int endIndex)
{
    int mid = (startIndex + endIndex) / 2;
    BinaryTreenode<int> *root = new BinaryTreenode<int>(arr[mid]);
    if (startIndex == endIndex)
    {
        return root;
    }
    root->left = arrayBST(arr, startIndex, mid - 1);
    root->right = arrayBST(arr, mid + 1, endIndex);
    return root;
}

// Problem 5 - BST to LL
class Node
{
public:
    int data;
    Node *next;
};

Node *BSTtoLL(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *ptr = new Node;

    ptr->data = root->data;
    Node *left = BSTtoLL(root->left);
    Node *right = BSTtoLL(root->right);
    ptr->next = right;
    if (left == NULL)
    {
        return ptr;
    }
    Node *leftTail = left;
    while (leftTail->next != NULL)
    {
        leftTail = leftTail->next;
    }
    leftTail->next = ptr;
    return left;
}
void printLL(Node *ptr)
{
    for (int i = 1; ptr != NULL; i++)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Problem 6 - Root to Node Path
vector<int> *getRootToNodePath(BinaryTreenode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }
}

// BST assignment
// Problem 0 - Insert duplicate node
BinaryTreenode<int> *InsertDuplicateNode(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    BinaryTreenode<int> *leftNode = root->left;
    BinaryTreenode<int> *newNode = new BinaryTreenode<int>(root->data);
    root->left = newNode;
    newNode->right = NULL;
    newNode->left = InsertDuplicateNode(leftNode);
    root->right = InsertDuplicateNode(root->right);
    return root;
}

// Problem 1 - Pair sum BT
void pairSum(BinaryTreenode<int> *node, BinaryTreenode<int> *root, int s)
{
    if (node == NULL)
    {
        return;
    }
    if (searchBST(root, (s - node->data)))
    {
        cout << node->data << " " << (s - node->data) << endl;
        node->data = INT_MAX;
    };
    pairSum(node->left, root, s);
    pairSum(node->right, root, s);
}
int main()
{
    // BinaryTreenode<int> *root = takeInputLevelWise();
    // int x, y;
    // cin >> x >> y;
    // cout << searchBST(root, x) << endl;
    // PrintInRange(root, x, y);
    // cout << checkBST(root);
    // cout << checkBST2(root);
    // vector<int> arr{1, 2, 3, 4, 5, 6, 7};
    // BinaryTreenode<int> *root = arrayBST(arr, 0, 6);
    // printBTlevelWise(root);
    // printLL(BSTtoLL(root));
    // int data;
    // cin >> data;
    // vector<int> *output = getRootToNodePath(root, data);
    // for (int i = 0; i < output->size(); i++)
    // {
    //     cout << output->at(i) << " ";
    // }
    // BST b;
    // b.insertData(10);
    // b.insertData(5);
    // b.insertData(20);
    // b.insertData(7);
    // b.insertData(3);
    // b.printBT();
    // b.deleteData(3);
    // b.printBT();
    // cout << b.hasData(7) << endl;

    // BST assignments
    BinaryTreenode<int> *root = takeInputLevelWise();
    // printBTlevelWise(InsertDuplicateNode(root));
    pairSum(root, root, 15);

    return 0;
}
