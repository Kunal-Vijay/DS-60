#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Treenode{
    public:
    T data;
    //vector for storing the address of child nodes 
    vector <Treenode <T>*> children;

    //constructor
    Treenode(T data){
        this->data=data;
    }
};