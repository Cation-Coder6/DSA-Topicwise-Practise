int lcs(int x, int y, string s1, string s2)
{
    int t[x + 1][y + 1];
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0; // if length of any one of the substrings is 0 then there are no common elements between them thus initialization is false for these cases.
            else if (s1[i - 1] == s2[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1; // if the elements are the same then we add it to our list and never check it again.
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]); // if the elements do not match we take the largest common subsequence from the two strings
        }
    }
    return t[x][y];
}