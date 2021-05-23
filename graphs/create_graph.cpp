#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TODO: Take care of undirected and directed graphs.

void addEdge(int p, int q, vector<int>adj[])
{
    adj[p].push_back(q);
    adj[q].push_back(p);
}

void printGraph(vector<int>adj[], int v)
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


int main()
{
    int v, e;
    cout << "enter no. of vertices and edges: ";
    cin >> v >> e;
    vector<int> adj[v+1];
    int p,q; 
    
    for(int i=1; i<=e; i++)
    {
        cout << "enter nodes of edge " << i << " : ";
        cin >> p >> q;
        addEdge(p, q, adj);
    }

    printGraph(adj, v);

    return  0;
}