#include <iostream>
using namespace std;

int maxi = INT_MIN;
int mini = INT_MAX;

void exp(int *a, int n, int key)
{
    if (n == 0)
    {
        return;
    }
    if (a[n - 1] == key)
    {
        if (maxi < n - 1)
            maxi = n - 1;
        if (mini > n - 1)
            mini = n - 1;
        exp(a, n - 1, key);
    }

    else
        exp(a, n - 1, key);
}

int main()
{
    int a[] = {1, 4, 2, 1, 6, 1, 5};
    exp(a, 7, 1);
    cout << "Minimum index :- " << mini;
    cout << "Maximum index :- " << maxi;
}
