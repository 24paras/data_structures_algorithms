#include <iostream>
#include "graph_helper.h"
using namespace std;

//TODO: Current DFS doesn't print out all nodes. 
//Disconnected nodes will not be printed.

vector<bool> visited(100000, false);
void DFS(vector<vector<int> > g1, int s)
{
    if(visited[s] != true)
    {
        cout << s << "->";
        visited[s] = true;
    }
    for(vector<int>::iterator it = g1[s].begin(); it != g1[s].end(); it++)
    {
        if(visited[*it] != true)
        {
            DFS(g1, *it);
        }
    }

}

int main()
{
    vector<vector<int> > g1;
    memset(&g1, 0, sizeof(g1));
    g1 = create_graph();
    int start;
    cout << "enter start vertex: ";
    cin >> start;
    DFS(g1, start);
}