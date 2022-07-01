int LongestRepeatingSubsequence(string s1)
{
    // here we use the same string as the 2 strings in the lcs function
    // the question asks us to find the longest repeating subsequence
    // that means that we have to find the longest subsequence appearing more than once in the string
    int n = s1.length();
    int t[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;                           // if there are no elements in the strings then there is no repeating subsequence in the string.
            else if (s1[i - 1] == s1[j - 1] && i != j) // we check if the elements are same and in sequence in the string.
                // we passed the same string in the lcs function twice so if we dont check for i!=j then the ans we get back will be the length of the string given.
                t[i][j] = t[i - 1][j - 1] + 1; // standard lcs.
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]); // standard lcs.
        }
    }
    return t[n][n];
}