int t[101][101];
int solver(int ar[], int i, int j)
{
    if (i >= j)
        return t[i][j] = 0;
    if (t[i][j] != -1)
        return t[i][j];
    int ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        if (t[i][k] == -1)
            t[i][k] = solver(ar, i, k);
        if (t[k + 1][j] == -1)
            t[k + 1][j] = solver(ar, k + 1, j);

        int temp = t[i][k] + t[k + 1][j] + ar[i - 1] * ar[k] * ar[j];
        ans = min(temp, ans);
    }
    return t[i][j] = ans;
}

int matrixMultiplication(int N, int arr[])
{
    memset(t, -1, sizeof(t));
    return solver(arr, 1, N - 1);
}