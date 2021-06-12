#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// add an edge to a graph
void addEdge(int &p, int &q, int&r, vector<vector<pair<int, int> > > &adj)
{
    if(p != q)
    {
        adj[p].push_back(make_pair(q,r));
        adj[q].push_back(make_pair(p,r));
    }
    else
    {
        adj[p].push_back(make_pair(q,r));
    }
}

// print the graph adjacency list
void printGraph(vector<vector<pair<int, int> > > adj, int v)
{
    for(int j=1; j<=v; j++)
    {
        vector<pair<int, int> >::iterator it;
        cout << j;
        for(it = adj[j].begin(); it <adj[j].end(); it++)
        {
            cout << " ->" << it->first << ":" << it->second;
        }
        cout << endl;
    }
}

// take input for a graph
vector<vector<pair<int, int> > > create_graph()
{
    int v, e;
    cout << "enter no. of vertices and edges: ";
    cin >> v >> e;
    vector<vector<pair<int, int> > > adj(v+1);
    int p,q, r; 
    
    for(int i=1; i<=e; i++)
    {
        cout << "enter nodes of edge " << i << " and weight with spaces: ";
        cin >> p >> q >> r;
        addEdge(p, q, r, adj);
    }

    printGraph(adj, v);
    return adj;
}

void find_shortest_path(vector<vector<pair<int, int> > > adj, unordered_set<int> &visited, unordered_set<int> &unvisited, int start, vector<pair<int, int> > &result_table)
{
    // distance of start node from start node is 0 only
    result_table[start].first = 0;

    visited.insert(start);
    unvisited.erase(start);

    for(int i=0; i<adj[start].size(); i++){
        
        int dist = result_table[start].first + adj[start][i].second;
        cout << "dist is: " << dist << endl;
        if(dist < result_table[adj[start][i].first].first) {
            result_table[adj[start][i].first].first = dist;
            result_table[adj[start][i].first].second = start;
        }
    }

    
    while(!unvisited.empty()) {
        int min_dist = INT_MAX;
        int min_node = start;
        for(int i=1; i<result_table.size(); i++) {

            if(unvisited.find(i) != unvisited.end() && result_table[i].first < min_dist) {
                cout << " unvisited node: " << i << " dist is : " << result_table[i].first  << " unvisited size is: " << unvisited.size() << endl;
                min_node = i;
                min_dist = result_table[i].first;
            }
            
        }

        for(int j=0; j<adj[min_node].size(); j++) {
            int dist = result_table[min_node].first + adj[min_node][j].second;
            if(dist < result_table[adj[min_node][j].first].first) {
                result_table[adj[min_node][j].first].first = dist;
                result_table[adj[min_node][j].first].second = min_node;
            }
        }
        visited.insert(min_node);
        unvisited.erase(min_node);
        //printf("unvisited size is : %lu\n", unvisited.size());  
        //printf("hi\n");      
    }


}

int main()
{
    vector<vector<pair<int, int> > > g = create_graph();

    // vector to store the shortest dist and previous node.
    vector<pair<int, int> > result_table(g.size(), make_pair(INT_MAX, -1));

    //vector to store visited and unvisited nodes.
    unordered_set<int> visited, unvisited;
    for(int i=1; i<g.size(); i++)
    {
        unvisited.insert(i);
    }
    int start;
    cout << "enter the start node: ";
    cin >> start;

    find_shortest_path(g, visited, unvisited, start, result_table);
    for(int i=1; i<result_table.size(); i++){
        cout << "i: " << i << " dist: " << result_table[i].first << " prev_node: " << result_table[i].second << endl;
    }

    return 0;
}