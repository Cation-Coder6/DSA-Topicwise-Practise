#include <iostream>
#include <vector>

using namespace std;

int find_parent(int v, vector<int> &parent, vector<int> &size)
{
    if (v == parent[v])
        return v;

    return parent[v] = find_parent(parent[v], parent, size);
}

void find_union(int a, int b, vector<int> &parent, vector<int> &size)
{
    a = find_parent(a, parent, size);
    b = find_parent(b, parent, size);

    if (size[a] < size[b])
    {
        swap(a, b);
    }
    parent[b] = a;
    size[a] += size[b];
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> list[n];
    vector<int> parent(n, 0);
    vector<int> size(n, 0);
    vector<vector<int>> edge;

    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        list[v1].push_back(v2);
        list[v2].push_back(v1);

        edge.push_back({v1, v2});
    }

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
    bool cycle = false;
    for (auto x : edge)
    {
        int v1 = x[0];
        int v2 = x[1];

        int a = find_parent(v1, parent, size);
        int b = find_parent(v2, parent, size);

        if (a == b)
        {
            cycle = true;
        }
        else
            find_union(v1, v2, parent, size);
    }

    if (cycle)
        cout << "\nCycle Found in Graph\n";
    else
        cout << "\nCycle Not Found in Graph\n";
}