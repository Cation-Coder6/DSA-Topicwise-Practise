#include <iostream>
#include <vector>
using namespace std;

bool color_marker(int node, vector<int> list, vector<int> &color)
{
    if (color[node] == -1)
        color[node] = 1;

    for (auto x : list[node])
    {
        if (color[x] == -1)
        {
            color[x] = 1 - color[node];
            if(!color_maker(x , list , color)
            return false;
        }
        else if (color[node] == color[x])
            return false;
    }
    color[node] = -1;
    return true;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> list[n];
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        list[v1].push_back(v2);
        list[v2].push_back(v1);
    }

    vector<int> color(n, -1);

    bool bipartate = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (color_marker(i, list, color))
                bipartate = true;
        }
    }

    if (bipartate)
        cout << "\nThe graph is bipartate\n";
    else
        cout << "\nThe graph is not bipartate\n";
}