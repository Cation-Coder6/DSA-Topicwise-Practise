int longestCommonSubstr(string s1, string s2, int n, int m)
{
    int t[n + 1][m + 1];
    int maxLength = INT_MIN;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0; // if length of any one of the substrings is 0 then there are no common elements between them thus initialization is false for these cases.
            else if (s1[i - 1] == s2[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1; // if the elements are the same then we add it to our list and never check it again.
            else
                t[i][j] = 0;                     // if the elements do not match we make it zero as they have to be consequtive as this is substring.
            maxLength = max(maxLength, t[i][j]); // to return the largest common substring we have to store the value as the last block of the matrix may not have the ans.
        }
    }
    return maxLength;
}