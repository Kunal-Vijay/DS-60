#include <bits/stdc++.h>
#include "binaryTreenode.h"
using namespace std;

void printBinaryTree(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << " L:" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << " R:" << root->right->data;
    }
    cout << endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

BinaryTreenode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreenode<int> *root = new BinaryTreenode<int>(rootData);
    BinaryTreenode<int> *leftChild = takeInput();
    BinaryTreenode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

BinaryTreenode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
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
        cout << "Enter left child of" << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreenode<int> *child = new BinaryTreenode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of" << front->data << endl;
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

int main()
{
    // BinaryTreenode<int> *root = new BinaryTreenode<int>(1);
    // BinaryTreenode<int> *node1 = new BinaryTreenode<int>(2);
    // BinaryTreenode<int> *node2 = new BinaryTreenode<int>(3);
    // root->left = node1;
    // root->right = node2;
    // BinaryTreenode<int> *root = takeInput();
    BinaryTreenode<int> *root = takeInputLevelWise();
    printBinaryTree(root);
    delete root;
    return 0;
}