#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adjacency_list[100];

void BFS(int *visited, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        cout << temp << " ";
        for (auto x : adjacency_list[temp])
        {
            if (visited[x] == 0)
            {
                q.push(x);
                visited[x] = 1;
            }
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter the number of nodes and edges in the Graph:-";
    cin >> n >> e;

    bool visited[n + 1];
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        adjacency_list[v1].push_back(v2);
        adjacency_list[v2].push_back(v1);
    }

    cout << "The Adjacency List of the Graph is as follows:-\n";
    for (int i = 0; i < n + 1; i++)
    {
        cout << i << " -> ";

        for (auto x : adjacency_list[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    cout << "\nThe BFS Traversal for the Graph :-";

    return 0;
}
