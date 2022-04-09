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

void inorder(BinaryTreenode<int>*root){
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(BinaryTreenode<int>*root){
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(BinaryTreenode<int>*root){
    if (root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
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
    // printBinaryTree(root);
    // printBTlevelWise(root);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    delete root;
    return 0;
}