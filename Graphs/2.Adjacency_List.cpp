#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v[n];
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    cout << "The adjacecy list of the graph is :-\n";

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto x : v[i])
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}