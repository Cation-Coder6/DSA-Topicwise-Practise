#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> k = {1, 3, 2, 4};

    stack<int> s;
    vector<int> v;

    for (int i = k.size() - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }
        else if (!s.empty())
        {
            while (!s.empty() && s.top() >= k.at(i))
            {
                s.pop();
            }
            if (s.empty())
            {
                v.push_back(-1);
            }
            else if (s.top() < k.at(i))
            {
                v.push_back(s.top());
            }
        }
        s.push(k.at(i));
    }

    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    return 0;
}