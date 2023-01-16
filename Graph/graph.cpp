#include <bits/stdc++.h>
using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited) // sv = starting vertex
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
            {
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

// for disconnected graph
void DFSdisconnected(int **edges, int n)
{
    bool *visited = new bool[n];
    // initializing all nodes univisited
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}
void BFSdisconnected(int **edges, int n)
{
    bool *visited = new bool[n];
    // initializing all nodes univisited
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

bool hasPath(int **edges, int n, int sv, int ev)
{
    queue<int> pendingVertices;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        if (currentVertex == ev)
        {
            delete[] visited;
            return true;
        }
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
            {
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n]; // edge matrix
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s; // first and second vertices
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    // cout << "DFS" << endl;
    // printDFS(edges, n, 0, visited);
    // cout << "BFS" << endl;
    // printBFS(edges, n, 0, visited);

    // // disconnected graphs
    // cout << "DFS" << endl;
    // DFSdisconnected(edges, n);
    // cout << "BFS" << endl;
    // BFSdisconnected(edges, n);

    cout << "has path from 0 to 7:- " << hasPath(edges, n, 0, 7);

    return 0;
}

//           0
//          / \      
//         4   5
//        /     \    
//       3-------6
//     /  \       \  
//    2----1       7

// input : 8
//  9
//  0 4
//  0 5
//  4 3
//  3 2
//  2 1
//  1 3
//  5 6
//  3 6
//  6 7

// DFS = 0 4 3 1 2 6 5 7
// BFS = 0 4 5 3 6 1 2 7

// Disconnected Graph
//       0           1       5
//     /  \         /       /
//    2----3       4       6
//
// input:-
// 7
// 5
// 0 2
// 0 3
// 2 3
// 1 4
// 5 6
//
//  DFS = 0 2 3 1 4 5 6
//  BFS = 0 2 3 1 4 5 6
