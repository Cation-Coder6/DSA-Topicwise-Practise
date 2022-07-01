#include <iostream>
using namespace std;

bool check_sorted(int *a, int n)
{
    if (n == 1)
    {
        return true;
    }

    return (a[n - 1] > a[n - 2] && check_sorted(a, n - 1));
}

int main()
{
    int ar[] = {1};

    cout << check_sorted(ar, 1);
}