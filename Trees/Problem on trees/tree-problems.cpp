#include <bits/stdc++.h>
#include "treenode.h"
using namespace std;

Treenode<int> *takeInputLevelwise()
{
    int rootData;
    cin >> rootData;
    Treenode<int> *root = new Treenode<int>(rootData);
    queue<Treenode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        Treenode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            Treenode<int> *child = new Treenode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

// Problem 1 - count nodes
int countNode(Treenode<int> *root, int x)
{
    int ans = 0;
    if (root->data > x)
    {
        ans = 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNode(root->children[i], x);
    }
    return ans;
}

// Problem 2 - Node with maximum child sum
int childSum(Treenode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }
    return sum;
}

int maximumChildSum(Treenode<int> *root)
{
    int ans = root->data;
    int maxsum = childSum(root);
    for (int i = 0; i < root->children.size(); i++)
    {
        if (childSum(root->children[i]) > maxsum)
        {
            maxsum = childSum(root->children[i]);
            ans = root->children[i]->data;
        }
    }
    return ans;
}

// Problem 3 - Structural identical
vector<int> preorder(Treenode<int> *root)
{
    vector<int> p;
    p.push_back(root->data);
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
    return p;
}

void structuralIdentical(Treenode<int> *root1, Treenode<int> *root2)
{
    vector<int> t1 = preorder(root1);
    vector<int> t2 = preorder(root2);
    if (t1.size() == t2.size())
    {
        for (int i = 0; i < t1.size(); i++)
        {
            if (t1[i] != t2[i])
            {
                cout << "false" << endl;
                return;
            }
        }
        cout << "true" << endl;
        return;
    }
    else
    {
        cout << "false" << endl;
        return;
    }
}

// Problem 4 - next larger
int nextLarger(Treenode<int> *root, int n)
{
    int ans = NULL;
    if (root->data > n)
    {
        ans = root->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        int temp = nextLarger(root->children[i], n);
        if (temp < ans || ans == NULL)
        {
            ans = temp;
        }
    }
    return ans;
}

// Problem 5 -second largest element
class secondMax
{
public:
    int max1;
    int max2;
};

secondMax secondLargest(Treenode<int> *root)
{
    secondMax ans;
    ans.max1 = root->data;
    ans.max2 = NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        secondMax temp;
        temp.max1 = secondLargest(root->children[i]).max1;
        temp.max2 = secondLargest(root->children[i]).max2;
        if (temp.max1 > ans.max1)
        {
            if (temp.max2 > ans.max1 || temp.max2 == NULL)
            {
                ans.max2 = ans.max1;
            }
            else
            {
                ans.max2 = temp.max2;
            }
            ans.max1 = temp.max1;
        }
        else if (temp.max2 != NULL)
        {
            if (ans.max2 == NULL || temp.max2 > ans.max2)
            {
                ans.max2 = temp.max2;
            }
        }
    }
    return ans;
}

// Problem 6- replace with depth
void replaceDepth(Treenode<int> *root, int depth = 0)
{
    root->data = depth;
    for (int i = 0; i < root->children.size(); i++)
    {
        replaceDepth(root->children[i], depth + 1);
    }
}

void printTree(Treenode<int> *root)
{
    // edge case if someone passes NULL pointer in the argument
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

int main()
{
    // int x;
    // cin >> x;
    // cout << "Count nodes :" << countNode(root, x) << endl;
    // cout << "Maximum sum nodes:" << maximumChildSum(root) << endl;
    // Treenode<int> *root1 = takeInputLevelwise();
    // Treenode<int> *root2 = takeInputLevelwise();
    // structuralIdentical(root1, root2);
    // int n;
    // cin >> n;
    Treenode<int> *root = takeInputLevelwise();
    // cout << nextLarger(root, n) << endl;
    cout << secondLargest(root).max1 << endl;
    cout << secondLargest(root).max2 << endl;
    // replaceDepth(root);
    // printTree(root);
    return 0;
}