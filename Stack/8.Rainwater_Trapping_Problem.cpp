#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {3, 0, 0, 2, 0, 4};
    vector<int> greatest_left, greatest_right;
    int max_l = -1, max_r = -1;
    for (int i = 0, j = v.size() - 1; i < v.size(); i++, j--)
    {
        if (max_l < v[i])
        {
            max_l = v[i];
        }
        if (max_r < v[j])
        {
            max_r = v[j];
        }

        greatest_left.push_back(max_l);
        greatest_right.push_back(max_r);
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {

        sum += min(greatest_left[i], greatest_right[i]) - v[i];
    }

    cout << "The rainwater trapped in the array is :- " << sum;

    return 0;
}