#include <iostream>
#include <vector>
using namespace std;

void component_counter(int node, vector<int> list[], int &count, vector<int> &visited)
{
    visited[node] = 1;
    count++;
    for (auto x : list[node])
    {
        if (visited[x] == 0)
            component_counter(x, list, count, visited);
    }
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
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            int counter = 0;
            component_counter(i, v, counter, visited);
            ans.push_back(counter);
        }
    }
    int answer = 0;
    for (auto x : ans)
        answer += x * (n - x);

    cout << "\n"
         << answer / 2;
}