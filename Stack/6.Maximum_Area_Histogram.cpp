#include <iostream>
#include <stack>
#include <vector>
#include <utility>
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
int main()
{
    vector<int> v = {2, 3, 3, 2};

    cout << "The maximum area of the given histogram is :- " << maximum_area_histogram(v);
}