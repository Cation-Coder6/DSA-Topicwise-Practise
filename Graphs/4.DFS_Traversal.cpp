#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void dfs(vector<int> v, int *visited, int node)
{
    visited[node] = 1;

    for (int x : v[node])
    {
        if (visited[x] == 1)
            ;
        else
        {
            dfs(v, visited, x);
        }
    }

    cout << node << " ";
}

int main()
{

    int n, e;
    cout << "Enter the number of nodes and edges in the Graph :-";
    cin >> n >> e;

    vector<int> adjacency_list[n + 1];

    int visited[n + 1];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adjacency_list[v2].push_back(v1);
        adjacency_list[v1].push_back(v2);
    }

    cout << "The Adjacency List of the Graph:-\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto x : adjacency_list[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    dfs(adjacency_list, visited, 0);
}