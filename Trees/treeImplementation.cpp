#include <bits/stdc++.h>
#include "treenode.h"
using namespace std;

Treenode<int>*takeinput(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    Treenode<int>*root=new Treenode<int>(rootData);

    int n;
    cout<<"Enter number of children of "<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        Treenode<int>*child=takeinput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(Treenode<int> *root)
{
    //edge case if someone passes NULL pointer in the argument
    if (root==NULL)
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
    // Treenode<int> *root = new Treenode<int>(1);
    // Treenode<int> *node1 = new Treenode<int>(2);
    // Treenode<int> *node2 = new Treenode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    Treenode<int> *root = takeinput();
    printTree(root);
    return 0;
}