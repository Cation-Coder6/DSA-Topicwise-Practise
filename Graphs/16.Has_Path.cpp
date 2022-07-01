#include <iostream>
#include <queue>
using namespace std;

bool has_Path(int **edges, int s, int e, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        if (temp == e)
            return true;
        for (int i = 0; i < n; i++)
        {
            if (edges[temp][i] == 1 && !visited[i] && i != temp)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int start, end;
    cin >> start >> end;
    cout << has_Path(edges, 1, 2, n);
}