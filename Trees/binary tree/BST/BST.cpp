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

int main()
{
    BinaryTreenode<int> *root = takeInputLevelWise();
    // int x, y;
    // cin >> x >> y;
    // cout << searchBST(root, x) << endl;
    // PrintInRange(root, x, y);
    cout << checkBST(root);
    cout << checkBST2(root);
    return 0;
}
