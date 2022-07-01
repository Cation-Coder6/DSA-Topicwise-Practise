#include <iostream>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> NGEL(vector<int> v, int k)
{

    for (int i = k; i >= 0; i--)
    {
        if (v.at(i) > v.at(k))
            return make_pair(v.at(i), i);
    }
    return make_pair(-1, -1);
}

int main()
{
    vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    stack<pair<int, int>> s;
    vector<int> ans;

    for (int i = 0; i < v.size(); i++)
    {
        s.push(NGEL(v, i));
        pair<int, int> p = s.top();
        if (p.second == -1)
        {
            ans.push_back(1);
        }
        else
            ans.push_back(i - p.second);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << " ";
    }

    return 0;
}