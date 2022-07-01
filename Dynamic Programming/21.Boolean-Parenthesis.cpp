int modulo = 1003;
unordered_map<string, int> mp;

int solve(string s, int i, int j, bool isTrue)
{
    if (i > j)
        return 0; // smallest invalid case

    if (i == j)
    { // basic case evaluating t and f characters individually in the string
        if (isTrue == true)
            return s[i] == 'T'; // if we want true and char is T then we return true else false.
        else
            return s[i] == 'F'; // if we want false and char is F we return true else false.
    }

    string temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue); // our way of memoization using a string and putting it in a map.
    if (mp.find(temp) != mp.end())
        return mp[temp]; // if it exists in the map return it

    int ans = 0;
    for (int k = i + 1; k < j; k = k + 2)
    {
        // k falls only on operators while i and j always fall on the characters t and f
        //  we evaluate the left and right expressions as true and false.
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);
        int rt = solve(s, k + 1, j, true);
        int rf = solve(s, k + 1, j, false);

        if (s[k] == '|')
        { // or expression
            if (isTrue)
                ans += lt * rt + lt * rf + lf * rt; // conditions of getting true in or
            else
                ans += lf * rf; // conditions for getting false in or
        }
        else if (s[k] == '^')
        { // xor expression
            if (isTrue)
                ans += lt * rf + rt * lf; // conditions of getting true in xor
            else
                ans += lt * rt + lf * rf; // conditions for getting false in xor
        }
        else if (s[k] == '&')
        { // and expression
            if (isTrue)
                ans += lt * rt; // conditions of getting true in and
            else
                ans += lt * rf + rt * lf + lf * rf; // conditions for getting false in and
        }
    }
}

return mp[temp] = ans % modulo; // modulo required by question
}

int countWays(int N, string s)
{
    mp.clear(); // always do if declared map globally before using.
    return solve(s, 0, N - 1, true);
}