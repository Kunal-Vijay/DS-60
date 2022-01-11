#include <bits/stdc++.h>
#include "treenode.h"
using namespace std;

Treenode<int> *takeinput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    Treenode<int> *root = new Treenode<int>(rootData);

    int n;
    cout << "Enter number of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Treenode<int> *child = takeinput();
        root->children.push_back(child);
    }
    return root;
}

Treenode<int> *takeInputLevelwise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    Treenode<int> *root = new Treenode<int>(rootData);

    queue<Treenode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        Treenode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th of child of " << front->data << endl;
            cin >> childData;
            Treenode<int> *child = new Treenode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(Treenode<int> *root)
{
    //edge case if someone passes NULL pointer in the argument
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

//count number of nodes in tree
int numNodes(Treenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

//height of the tree
int heightOfTree(Treenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        if ((heightOfTree(root->children[i]) + 1) > ans)
        {
            ans = heightOfTree(root->children[i]) + 1;
        }
    }
    return ans;
}

//print all nodes at level K
void printLevelK(Treenode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printLevelK(root->children[i], k - 1);
    }
}
//count leaf nodes
void leafNodes(Treenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->children.size() == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        leafNodes(root->children[i]);
    }
}

//preorder tree traversal
void preorder(Treenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

//postorder tree traversal
void postorder(Treenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}

//deleting dynamically allocated tree (same as post order)
void deleteTree(Treenode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}
int main()
{
    Treenode<int> *root = new Treenode<int>(1);
    Treenode<int> *node1 = new Treenode<int>(2);
    Treenode<int> *node2 = new Treenode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    // Treenode<int> *root = takeinput();
    // Treenode<int> *root = takeInputLevelwise();
    cout << "Number of nodes:" << numNodes(root) << endl;
    cout << "Height of tree:" << heightOfTree(root) << endl;
    int k = 1;
    cout << "Nodes at level " << k << ":-" << endl;
    cout << "leaf nodes:-" << endl;
    leafNodes(root);
    cout << endl;
    printLevelK(root, k);
    printTree(root);
    cout << "\nPreorder traversal" << endl;
    preorder(root);
    cout << "\nPostorder traversal" << endl;
    postorder(root);
    deleteTree(root);
    return 0;
}