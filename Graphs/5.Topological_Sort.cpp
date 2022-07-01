#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> indegree(n, 0);
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        int v1, v2;
        adj[v1].push_back(v2);
        indegree[v2]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
    }
}