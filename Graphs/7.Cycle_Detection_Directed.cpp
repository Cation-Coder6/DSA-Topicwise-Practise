#include <iostream>
#include <queue>

#include <vector>
using namespace std;

bool isCycle(int currentNode, vector<int> adj[], vector<int> &visited, vector<int> &stack)
{
    stack[currentNode] = 1;
    visited[currentNode] = 1;

    for (auto x : adj[currentNode])
    {
        if (stack[x] == 1)
            return true;

        if (visited[x] == 0 && isCycle(x, adj, visited, stack))
        {
            return true;
        }
    }

    stack[currentNode] = 0;
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v[n + 1];
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        v[v1].push_back(v2);
    }

    cout << "The adjacecy list of the graph is :-\n";

    for (int i = 0; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto x : v[i])
            cout << x << " ";
        cout << "\n";
    }

    vector<int> visited(n, 0);
    bool cycle = false;

    vector<int> stack(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && isCycle(i, v, visited, stack))
            cycle = true;
    }
    if (cycle)
    {
        cout << "\nCycle is present in the given Graph\n";
    }
    else
        cout << "Cycle is not present in the given Graph\n";
}