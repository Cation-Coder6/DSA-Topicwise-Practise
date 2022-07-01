#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int find_parent(int v, vector<int> &parent)
{
    if (v == parent[v])
        return parent[v];

    else
        parent[v] = find_parent(parent[v], parent);
}

void union_set(int a, int b, vector<int> &parent, vector<int> &size)
{
    a = find_parent(a, parent);
    b = find_parent(b, parent);

    if (size[a] < size[b])
    {
        swap(a, b);
    }
    parent[b] = a;
    size[a] += size[b];
}

void make_set(int a, vector<int> &parent, vector<int> &size)
{
    parent[a] = a;
    size[a] = 1;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> edge_list;
    vector<int> parent(n, 0);
    vector<int> size(n, 0);
    for (int i = 0; i < n; i++)
    {
        make_set(i, parent, size);
    }
    for (int i = 0; i < e; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;

        edge_list.push_back({w, v1, v2});
    }

    sort(edge_list.begin(), edge_list.end());
    int cost = 0;
    vector<vector<int>> mst;
    for (auto x : edge_list)
    {
        int weight = x[0];
        int v1 = x[1];
        int v2 = x[2];

        int a = find_parent(v1, parent);
        int b = find_parent(v2, parent);

        if (a == b)
            ;
        else
        {
            union_set(v1, v2, parent, size);
            cout << v1 << " " << v2 << "\n";
            cost += weight;
        }
    }

    cout << "Cost of the Minimum Spanning Tree is :- " << cost;
}