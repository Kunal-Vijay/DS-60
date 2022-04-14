#include <bits/stdc++.h>
#include "../binaryTreenode.h"
using namespace std;

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

// Problem 1 - Count Nodes
int countNodes(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Problem 2 - Node present
bool nodePresent(BinaryTreenode<int> *root, int node)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == node)
    {
        return true;
    }
    else if (nodePresent(root->left, node))
    {
        return nodePresent(root->left, node);
    }
    else
    {
        return nodePresent(root->right, node);
    }
}

//  Problem 3 - height of tree
int height(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->left));
}

// Problem 4 - diameter of BT
int diameter(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left) + height(root->right), max(height(root->left), height(root->right)));
}

// Problem 4 - Better approach
pair<int, int> heightDiameter(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
int main()
{
    BinaryTreenode<int> *root = takeInputLevelWise();
    // printBinaryTree(root);
    // cout << "Number of nodes:" << countNodes(root) << endl;
    // printBTlevelWise(root);
    // cout<<nodePresent(root,7)<<endl;
    // cout << height(root) << endl;
    // cout << diameter(root) << endl;
    pair<int, int> p = heightDiameter(root);
    cout << "Height:" << p.first << endl;
    cout << "Diameter:" << p.second << endl;
    delete root;
    return 0;
}