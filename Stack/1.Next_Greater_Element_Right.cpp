#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> k = {2, 3, 6, 2};
    int n = k.size();
    stack<int> s;
    vector<int> v;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }
        else if (!s.empty())
        {
            while (s.top() <= k[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                v.push_back(-1);
            }
            else if (s.top() > k[i])
            {
                v.push_back(s.top());
            }
        }
        s.push(k[i]);
    }

    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}