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

// BT Traversals
void inorder(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(BinaryTreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// construct tree from inorder and preorder
BinaryTreenode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int lPreS = preS + 1;
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;
    BinaryTreenode<int> *root = new BinaryTreenode<int>(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

BinaryTreenode<int> *buildTree(int *in, int *pre, int size)
{
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

// construct tree from post order and in order
BinaryTreenode<int> *buildTreeHelper2(int *in, int *post, int inS, int inE, int postS, int postE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = post[postS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int lPostS = postS;
    int lInS = inS;
    int lInE = rootIndex - 1;
    int rPostE = postE - 1;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int lPostE = lInE - lInS + lPostS;
    int rPostS = lPostE + 1;
    BinaryTreenode<int> *root = new BinaryTreenode<int>(rootData);
    root->left = buildTreeHelper2(in, post, lInS, lInE, lPostS, lPostE);
    root->right = buildTreeHelper2(in, post, rInS, rInE, rPostS, rPostE);
    return root;
}

BinaryTreenode<int> *buildTree2(int *in, int *post, int size)
{
    return buildTreeHelper2(in, post, 0, size - 1, 0, size - 1);
}
int main()
{
    // BinaryTreenode<int> *root = new BinaryTreenode<int>(1);
    // BinaryTreenode<int> *node1 = new BinaryTreenode<int>(2);
    // BinaryTreenode<int> *node2 = new BinaryTreenode<int>(3);
    // root->left = node1;
    // root->right = node2;
    // BinaryTreenode<int> *root = takeInput();
    // BinaryTreenode<int> *root = takeInputLevelWise();
    // printBinaryTree(root);
    // int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    // int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    // printBTlevelWise(buildTree(in, pre, 9));

    int post[] = {4, 5, 2, 6, 7, 3, 1};
    int in[] = {4, 2, 5, 1, 6, 3, 7};
    printBTlevelWise(buildTree2(in, post, 7));
    // inorder(root);
    // cout << endl;
    // preorder(root);
    // cout << endl;
    // postorder(root);
    // delete root;
    return 0;
}