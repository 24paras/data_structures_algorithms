#include <iostream>
#include <vector>
#include <algorithm>
#include "graph_helper.h"

// add an edge to a graph
void addEdge(int &p, int &q, vector<vector<int> > &adj)
{
    if(p != q)
    {
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    else
    {
        adj[p].push_back(q);
    }
}

// print the graph adjacency list
void printGraph(vector<vector<int> > adj, int v)
{
    for(int j=1; j<=v; j++)
    {
        vector<int>::iterator it;
        cout << j;
        for(it = adj[j].begin(); it <adj[j].end(); it++)
        {
            cout << " ->" << *it; 
        }
        cout << endl;
    }
}

// take input for a graph
vector<vector<int> > create_graph()
{
    int v, e;
    cout << "enter no. of vertices and edges: ";
    cin >> v >> e;
    vector<vector<int> > adj(v+1);
    int p,q; 
    
    for(int i=1; i<=e; i++)
    {
        cout << "enter nodes of edge " << i << " : ";
        cin >> p >> q;
        addEdge(p, q, adj);
    }

    printGraph(adj, v);
    return adj;
}