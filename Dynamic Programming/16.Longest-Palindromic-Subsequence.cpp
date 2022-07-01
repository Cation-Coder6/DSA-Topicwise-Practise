int lcs(string s1, string s2)
{
    int n = s1.length();
    int t[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0; // if either of the strings is empty there will be no common elements between them thus we store 0.
            else if (s1[i - 1] == s2[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1; // if the element of the 2 strings match we add 1 to our count storer and dont consider it anymore.
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]); // if the element of the 2 strings are not the same we check for longest common subsequence by considering the element of string 1 and 2 and returning the maximum of the 2 descisions.
        }
    }
    return t[n][n];
}
int longestPalinSubseq(string a)
{
    string a1 = a;
    reverse(a.begin(), a.end());
    return lcs(a1, a); // this is a longest common subsequence problem type question . pass the string and its reverse and check for the lcs length and that would be the ans.
}