#include <bits/stdc++.h>
using namespace std;

// using adjecency list
class graph{
public:
    unordered_map<int,list<int>>adj;
    void addEdge(int u,int v,bool directed){
        adj[u].push_back(v);
        if(!directed)adj[v].push_back(u);
    }
    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

};

int main(){
    int n;   //nodes
    cin>>n;
    int m;  //edges
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,false);
    }

    g.printAdjList();
    
    return 0;
}