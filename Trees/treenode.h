#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Treenode{
    public:
    T data;
    vector <Treenode <T>*> children;
};