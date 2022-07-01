#include <iostream>
using namespace std;

int Subset(int ar[], int n, int sum, int** dp)
{
    if(n == 0 && sum != 0)
        return dp[n][sum] = 0;

    else if(sum == 0)
        return dp[n][sum] = 1;
        
    else if(dp[n][sum] != -1)
        return dp[n][sum];

    else if(sum >= ar[n - 1]) {
        return dp[n][sum] = (Subset(ar, n - 1, sum - ar[n - 1], dp) + Subset(ar, n - 1, sum, dp));
    } 
    else
        return dp[n][sum] = Subset(ar, n - 1, sum, dp);
}
int Subset(int ar[], int n, int sum)
{
    int** dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[sum + 1];
        for(int j = 0; j <= sum; j++){
            dp[i][j] = -1;
        }
    }
    return Subset(ar , n , sum , dp);
}

int main()
{
    int ar[] = { 2, 3, 5, 6, 8, 10 };
    int n = 6;
    int sum = 10;
    cout << Subset(ar, n, sum);
}