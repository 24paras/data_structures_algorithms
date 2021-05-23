#include <iostream>
#include "graph_helper.h"
using namespace std;

void BFS(vector<vector<int> > g1, int start)
{
    int V = g1.size()-1;
    vector<bool> visited(V+1, false);
    list<int> queue;
    queue.push_back(start);
    visited[start] = true;
    while(!queue.empty())
    {   
        // printf("hi\n");
        int s = queue.front();
        cout << s << "->\n";
        visited[s] = true;
        queue.pop_front();
        // printf("\nhi\n");
        for(vector<int>::iterator it = g1[s].begin(); it != g1[s].end(); it++)
        {
            // cout << "*it is " << *it << endl;
            // printf(visited[*it] ? "true\n" : "false\n");
            if(visited[*it] != true)
            {
                queue.push_back(*it);
                visited[*it] = true;
            }
        }
    }
}

int main()
{
    vector<vector<int> > g1;
    memset(&g1, 0, sizeof(g1));
    int start;
    g1 = create_graph();
    cout << "Enter start vertex: ";
    cin >> start;
    BFS(g1, start);
}