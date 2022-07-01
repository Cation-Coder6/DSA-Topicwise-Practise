#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int maximum_area_histogram(vector<int> v)
{
    vector<int> left, right;
    stack<int> s;

    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
        {
            left.push_back(-1);
        }
        else if (!s.empty())
        {
            while (s.size() != 0 && v.at(s.top()) >= v.at(i))
            {
                s.pop();
            }
            if (s.empty())
                left.push_back(-1);
            else
                left.push_back(s.top());
        }
        s.push(i);
    }
    while (!s.empty())
    {
        s.pop();
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            right.push_back(v.size());
        }
        else if (!s.empty())
        {
            while (!s.empty() && v.at(s.top()) >= v.at(i))
            {
                s.pop();
            }
            if (s.empty())
            {
                right.push_back(v.size());
            }
            else
                right.push_back(s.top());
        }
        s.push(i);
    }
    vector<int> ans;
    reverse(right.begin(), right.end());
    for (int i = 0; i < v.size(); i++)
    {
        ans.push_back((right.at(i) - left.at(i) - 1) * v.at(i));
    }

    sort(ans.begin(), ans.end());
    return ans.at(ans.size() - 1);
}

int max_area(int **a, int m, int n)
{
    vector<int> v = {0, 0, 0, 0};
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                v.at(j) += a[i][j];
            }
            if (a[i][j] == 0)
            {
                v.at(j) = 0;
            }
        }

        ans.push_back(maximum_area_histogram(v));
    }
    sort(ans.begin(), ans.end());
    return ans.at(ans.size() - 1);
}

int main()
{
    int n, m;
    cout << "Enter the number of rows and columns of the 2-D Binary matrix :-";
    cin >> n >> m;
    int **a = new int *[n];

    cout << "Enter the elements of the binary matrix :-\n";
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[m];
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    cout << "The maximum area of the Binary Matrix is :- " << max_area(a, 4, 4);
}