#include <vector>
#include <algorithm>
#include <list>
using namespace std;

// add an edge to a graph
void addEdge(int &p, int &q, vector<vector<int> > &adj);

// print the graph adjacency list
void printGraph(vector<vector<int> > adj, int v);

// take input for a graph
vector<vector<int> > create_graph();
