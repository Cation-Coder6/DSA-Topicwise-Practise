#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> list[n];
    for (int i = 0; i < e; i++)
    {
        int wt, v1, v2;
        cin >> v1 >> v2 >> wt;
        list[v1].push_back(make_pair(v2, wt));
        list[v2].push_back(make_pair(v1, wt));
    }

    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);

    key[0] = 0;
    parent[0] = -1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    minHeap.push({0, 0});

    while (!minHeap.empty())
    {
        int u = minHeap.top().second;
        minHeap.pop();

        mst[u] = true;
        for (auto x : list[u])
        {
            int v = x.first;
            int w = x.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
                minHeap.push({key[v], v});
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i << "  --->" << key[i] << "\n";
    }
}
