#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isCycle(int currentNode, vector<int> list[], vector<int> &visited, int parent)
{
    visited[currentNode] = 1;
    for (auto x : list[currentNode])
    {
        if (x != currentNode)
        {
            if (visited[x])
                return true;
            if (visited[x] == 1 && isCycle(x, list, visited, currentNode))
            {
                return true;
            }
        }
    }
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
        v[v2].push_back(v1);
    }

    cout << "The adjacecy list of the graph is :-\n";

    for (int i = 0; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto x : v[i])
            cout << x << " ";
        cout << "\n";
    }

    vector<int> visited(n + 1, 0);

    bool cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1 && isCycle(i, v, visited, -1))
            cycle = true;
    }

    if (cycle)
    {
        cout << "\nCycle is present in the given Graph\n";
    }
    else
        cout << "Cycle is not present in the given Graph\n";
}