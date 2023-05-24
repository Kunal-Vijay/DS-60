#include <bits/stdc++.h>
using namespace std;

// using adjecency list
class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    graph(int n, int e)
    {
        for (int i = 0; i < e; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            addEdge(u, v, w);
        }
    }
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
    }
    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << ")"
                     << ",";
            }
            cout << endl;
        }
    }

    // dfs
    void dfs(int node, vector<bool> &visited, stack<int> &topo)
    {
        visited[node] = true;
        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                dfs(i.first, visited, topo);
            }
        }
        topo.push(node);
    }

    void getShortestPath(int src, vector<int> &distance, stack<int> &topo)
    {
        distance[src] = 0;
        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();
            if (distance[top] != INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if (distance[top] + i.second < distance[i.first])
                    {
                        distance[i.first] = distance[top] + i.second;
                    }
                }
            }
        }
    }
};

int main()
{
    int n; // nodes
    cin >> n;
    int e; // edges
    cin >> e;
    graph g(n, e);

    g.printAdjList();

    // topological sort
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, st);
        }
    }
    int src = 1;
    vector<int> distance(n, INT_MAX);

    g.getShortestPath(src,distance,st);

    cout<<"Solution"<<endl;
    for(auto i:distance){
        if(i==INT_MAX)cout<<"# ";
        else cout<<i<<" ";
    }
    return 0;
}

/*
sample input        
6
9
0 1 5
0 2 3
1 2 2
1 3 6
2 3 7
2 4 4
2 5 2
3 4 -1
4 5 -2

sample output
4->(5,-2),
3->(4,-1),
2->(3,7),(4,4),(5,2),
1->(2,2),(3,6),
0->(1,5),(2,3),
Solution
# 0 2 6 5 3
*/