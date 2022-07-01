int knapSack(int n, int w, int val[], int wt[])
{
    int t[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0; // if max weight = 0 then no profit is possible and similarly if no element in the array then profit is impossible
            else if (j >= wt[i - 1])
                t[i][j] = max(t[i][j - wt[i - 1]] + val[i - 1], t[i - 1][j]); // if can include the current element in the knapsack then we check the max profit by either taking it or not taking it.
            // if we take it then we can come back to it again as repetition is allowed hence t[i][j-wt[i-1]] + val[i-1](here we write i instead of i-1 as we can come back to it)
            // if we deciede to not take it then the element is processed and we will not consider it ever thus we write t[i-1][j]
            else if (j < wt[i - 1])
                t[i][j] = t[i - 1][j]; // in this case the current element exceeds the weight left in the knapsack thus we discard the element and never check it again . Hence t[i-1][j]
        }
    }
    return t[n][w];
}