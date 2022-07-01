int t[10001];
int solver(int n, int x, int y, int z)
{
    if (n == 0)
        return 0; // if n = 0 it cannot be cut anymore.
    else if (t[n] != -1)
        return t[n]; // memoization

    int a = INT_MIN, b = INT_MIN, c = INT_MIN;

    if (n >= x)
        a = solver(n - x, x, y, z);
    if (n >= y)
        b = solver(n - y, x, y, z);
    if (n >= z)
        c = solver(n - z, x, y, z);

    return t[n] = max({a, b, c}) + 1; // we check and cut what we can on n and add 1 to account for the current cut.
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    // Your code here
    memset(t, -1, sizeof(t));
    return solver(n, x, y, z) < 0 ? 0 : solver(n, x, y, z); // just in case we get a INT_MIN in a case where n!=0 we return 0
}