#include <bits/stdc++.h>
#include "binaryTreenode.h"
using namespace std;

int main(){
    BinaryTreenode<int>*root=new BinaryTreenode<int>(1);
    BinaryTreenode<int>*node1=new BinaryTreenode<int>(2);
    BinaryTreenode<int>*node2=new BinaryTreenode<int>(3);
    root->left=node1;
    root->right=node2;
    return 0;
}