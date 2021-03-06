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

// Problem 5 - min max of BT
pair<int, int> maxMin(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = maxMin(root->left);
    pair<int, int> rightAns = maxMin(root->right);
    int lmax = leftAns.first;
    int lmin = leftAns.second;
    int rmax = rightAns.first;
    int rmin = rightAns.second;

    int maximum = max(lmax, rmax);
    int minimum = min(lmin, rmin);
    if (root->data > maximum)
    {
        maximum = root->data;
    }
    if (root->data < minimum || minimum == 0)
    {
        minimum = root->data;
    }
    pair<int, int> p;
    p.first = maximum;
    p.second = minimum;
    return p;
}

// Problem 6 - Sum of Nodes
int sumOfNodes(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sumOfNodes(root->left) + sumOfNodes(root->right) + (root->data);
}

// Problem 7 - Balanced Tree - error
bool isBalanced(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (((lh - rh) <= 1 || (lh - rh) >= -1) && (isBalanced(root->left) && isBalanced(root->right)))
    {
        return 1;
    }
    return 0;
}

// Problem 8 - level order printing
void levelOrder(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreenode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while (pendingNodes.size() != 0)
    {
        BinaryTreenode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front == NULL)
        {
            if (pendingNodes.empty())
            {
                break;
            }
            else
            {
                pendingNodes.push(NULL);
                cout << endl;
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
        }
    }
}

// Problem 9 - remove leaf node
BinaryTreenode<int> *removeLeaf(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {

        return root;
    }
    if (root->left == NULL && root->right == NULL)
    {
        root = NULL;
        return root;
    }
    root->left = removeLeaf(root->left);
    root->right = removeLeaf(root->right);
    return root;
}

// Problem 11 - Mirror BT
void mirrorBT(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreenode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while (pendingNodes.size() != 0)
    {
        BinaryTreenode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front == NULL)
        {
            if (pendingNodes.empty())
            {
                break;
            }
            else
            {
                pendingNodes.push(NULL);
                cout << endl;
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
        }
    }
}

// Problem 12 - Zig zag tree
void zigZagBT(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<BinaryTreenode<int> *> s1;
    stack<BinaryTreenode<int> *> s2;
    s1.push(root);

    while (!(s1.empty() && s2.empty()))
    {
        while (!(s1.empty()))
        {
            BinaryTreenode<int> *current = s1.top();
            s1.pop();

            cout << current->data << " ";
            if (current->left != NULL)
            {
                s2.push(current->left);
            }
            if (current->right != NULL)
            {
                s2.push(current->right);
            }
        }
        cout << endl;
        while (!(s2.empty()))
        {
            BinaryTreenode<int> *current = s2.top();
            s2.pop();

            cout << current->data << " ";
            if (current->right != NULL)
            {
                s1.push(current->right);
            }
            if (current->left != NULL)
            {
                s1.push(current->left);
            }
        }
        cout << endl;
    }
}

void nodeWithoutSiblings(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right != NULL)
    {
        cout << root->right->data << " ";
    }
    if (root->left != NULL && root->right == NULL)
    {
        cout << root->left->data << " ";
    }
    nodeWithoutSiblings(root->left);
    nodeWithoutSiblings(root->right);
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
    // pair<int, int> p = heightDiameter(root);
    // cout << "Height:" << p.first << endl;
    // cout << "Diameter:" << p.second << endl;
    // pair<int, int> p = maxMin(root);
    // cout << "Max:" << p.first << endl;
    // cout << "Min:" << p.second << endl;
    // cout << sumOfNodes(root) << endl;
    // cout << isBalanced(root) << endl;
    // removeLeaf(root);
    // levelOrder(root);
    // mirrorBT(root);
    // zigZagBT(root);
    nodeWithoutSiblings(root);
    delete root;
    return 0;
}