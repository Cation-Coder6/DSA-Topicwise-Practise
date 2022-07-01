#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> list[n];
    for (int i = 0; i < e; i++)
    {
        int w, v1, v2;
        cin >> v1 >> v2 >> w;
        list[v1].push_back(make_pair(v2, wt));
        list[v2].push_back(make_pair(v1, wt));
    }

    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n - 1; i++)
    {
        int mini = INT_MAX, u;
        for (int j = 0; j < n; j++)
        {
            if (mst[j] == false && key[j] < mini)
                mini = key[j], u = j;
        }
        mst[u] = true;
        for (auto x : list[u])
        {
            int v = x.first;
            int w = x.second;
            if (mst[v] == false && w < key[v])
                parent[v] = u, key[v] = weight;
        }
    }
}
