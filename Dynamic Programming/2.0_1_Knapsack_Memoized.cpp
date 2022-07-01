#include <iostream>
using namespace std;

int Knapsack(int wt[], int val[], int wt_lft, int n, int** dp)
{
    if(n == 0 || wt_lft == 0) {
        return dp[n][wt_lft] = 0;
    }
    if(dp[n][wt_lft] != -1)
        return dp[n][wt_lft];
    if(wt_lft >= wt[n - 1]) {
        return dp[n][wt_lft] = max(
                   Knapsack(wt, val, wt_lft, n - 1, dp), Knapsack(wt, val, wt_lft - wt[n - 1], n - 1, dp) + val[n - 1]);
    }
    return dp[n][wt_lft] = Knapsack(wt, val, wt_lft, n - 1, dp);
}

int Knapsack(int wt[], int val[], int wt_lft, int n)
{
    int** dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[wt_lft + 1];
        for(int j = 0; j <= wt_lft; j++) {
            dp[i][j] = -1;
        }
    }

    return Knapsack(wt, val, wt_lft, n, dp);
}

int main()
{

    int wt[] = { 1, 3, 4, 5 };
    int val[] = { 1, 4, 5, 7 };
    int n = 4;
    int w = 10;
    int max = Knapsack(wt, val, w, n);
    cout << max;

    return 0;
}