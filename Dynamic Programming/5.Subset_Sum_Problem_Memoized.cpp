#include <iostream>
using namespace std;

int Subset(int a[], int sum, int n, int **dp)
{
    if (n == 0 && sum != 0)
    {
        return dp[n][sum] = 0;
    }
    else if (sum == 0)
    {
        return dp[n][sum] = 1;
    }
    else if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    else if (sum >= a[n - 1])
    {
        return dp[n][sum] = max(Subset(a, sum - a[n - 1], n - 1, dp), Subset(a, sum, n - 1, dp));
    }
    else
        return dp[n][sum] = Subset(a, sum, n - 1, dp);
}

int Subset(int *a, int sum, int n)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[sum + 1];
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = -1;
        }
    }
    return Subset(a, sum, n, dp);
}
int main()
{
    int a[] = {2, 3, 7, 8, 10};
    int sum = 11;
    int n = 5;
    cout << Subset(a, sum, n);
}