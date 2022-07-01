#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {3, 4, 6, 2, 8};
    stack<int> s;
    int min_ele = v.at(0);
    for (int i = 0; i < v.size(); i++)
    {
        s.push(v.at(i));
        if (s.top() < min_ele)
        {
            int temp = s.top();
            s.pop();
            s.push(2 * temp - min_ele);
            min_ele = v.at(i);
        }
    }

    cout << min_ele << " ";

    for (int i = 0; i < v.size(); i++)
    {
        if (s.top() < min_ele)
        {
            min_ele = 2 * min_ele - s.top();
        }
        cout << min_ele << " ";
        s.pop();
    }
}