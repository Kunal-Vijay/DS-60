#include <bits/stdc++.h>

template <class T>
class BinaryTreenode
{
public:
    T data;
    BinaryTreenode *left;
    BinaryTreenode *right;

    BinaryTreenode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreenode(){
        delete left;
        delete right;
    }
};
