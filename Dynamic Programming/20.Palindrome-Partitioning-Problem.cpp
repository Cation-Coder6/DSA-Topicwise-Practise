int t[502][502];
// just a function to check if the given part of a string is a palindrome or not.
bool isPalindrome(string s, int start, int end)
{
    int j = end;

    for (int i = start; i < j; i++, j--)
        if (s[i] != s[j])
            return false;

    return true;
}

int mcm(string str, int i, int j)
{
    if (i >= j) // this is the first invalid input.
        return t[i][j] = 0;
    if (isPalindrome(str, i, j)) // we need to find the minimum number of cuts thus if a string is a palindrome then need 0 cuts to turn it into a palindrome.
        return t[i][j] = 0;
    if (t[i][j] != -1)
        return t[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        if (t[i][k] == -1)
            t[i][k] = mcm(str, i, k);
        if (t[k + 1][j] == -1)
            t[k + 1][j] = mcm(str, k + 1, j);

        int temp = t[i][k] + t[k + 1][j] + 1; // standard mcm code. Here single characters in a string like "a" , "b" and so on are palindromic sequences. Thus we add 1 to the number of cuts.
        ans = min(temp, ans);                 // we need minimum number of cuts.
    }
    return t[i][j] = ans;
}

int palindromicPartition(string str)
{
    memset(t, -1, sizeof(t));
    return mcm(str, 0, str.length() - 1);
}