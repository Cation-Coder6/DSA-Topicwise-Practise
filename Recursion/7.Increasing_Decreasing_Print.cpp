#include <iostream>
using namespace std;

void increasing(int *a, int n)
{
    if (n == 0)
    {
        return;
    }
    increasing(a, n - 1);
    cout << a[n - 1] << " ";
}

void decreasing(int *a, int n)
{
    if (n == 0)
    {
        return;
    }
    cout << a[n - 1] << " ";
    decreasing(a, n - 1);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    decreasing(a, 7);
}