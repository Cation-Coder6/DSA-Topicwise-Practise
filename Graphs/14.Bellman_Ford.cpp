#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> list;
    for (int i = 0; i < e; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        list.push_back({v1, v2, wt});
    }

    int source;
    cin >> source;

    vector<int> distance(n, 10000000);
    distance[source] = 0;
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {

        for (auto x : list)
        {
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            if (distance[v] > wt + distance[u])
                flag = 1;
            distance[v] = min(distance[v], distance[u] + wt);
        }
    }

    if (!flag)
    {
        for (auto x : distance)
        {
            cout << " " << x << " ";
        }
    }
}