#include <bits/stdc++.h>
#include "../binaryTreenode.h"
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

int main()
{
    BinaryTreenode<int> *root = takeInputLevelWise();
    int x;
    cin >> x;
    cout << searchBST(root, x) << endl;
    return 0;
}