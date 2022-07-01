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

    int source;
    cin >> source;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(n + 1, INT_MAX);

    distTo[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;

        pq.pop();

        for (auto x : list[prev])
        {
            int next = x.first;
            int nextDist = x.second;
            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    cout << "The distance from the source is :- ";
    for (auto x : distTo)
        cout << x << " ";
}