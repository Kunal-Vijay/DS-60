#include "../binaryTreenode.h"
#include <bits/stdc++.h>
using namespace std;

class BST
{
    BinaryTreenode<int> *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    BinaryTreenode<int> *deleteData(int data, BinaryTreenode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (data < node->data)
        {
            node->left = deleteData(data, node->left);
            return node;
        }
        else if (data > node->data)
        {
            node->right = deleteData(data, node->right);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreenode<int> *temp = node->right;
                node->right == NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreenode<int> *temp = node->left;
                node->right == NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreenode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(rightMin, node->right);
                return node;
            }
        }
        return node;
    }

public:
    void deleteData(int data)
    {
        root = deleteData(data, root);
    }

private:
    BinaryTreenode<int> *insert(int data, BinaryTreenode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreenode<int> *newNode = new BinaryTreenode<int>(data);
            return newNode;
        }
        if (data < node->data)
        {
            node->left = insert(data, node->left);
        }
        else
        {
            node->right = insert(data, node->right);
        }
        return node;
    }

public:
    void insertData(int data)
    {
        this->root = insert(data, this->root);
    }

private:
    bool hasData(int data, BinaryTreenode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if (data < node->data)
        {
            return hasData(data, node->left);
        }
        else if (data > node->data)
        {
            return hasData(data, node->right);
        }
    }

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }

private:
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

public:
    void printBT()
    {
        printBTlevelWise(this->root);
    }
};