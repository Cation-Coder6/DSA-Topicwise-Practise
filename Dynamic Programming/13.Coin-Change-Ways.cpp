int change(int amount, vector<int> &coins)
{
    int length = coins.size();
    int t[length + 1][amount + 1];
    for (int i = 0; i < length + 1; i++)
    {
        for (int j = 0; j < amount + 1; j++)
        {
            if (i == 0 && j != 0)
                t[i][j] = 0; // if we have amount>0 but no coins i.e length = 0 thus false
            else if (j == 0)
                t[i][j] = 1; // if amount = 0 then empty set will work as well thus true
            else if (j >= coins[i - 1])
                t[i][j] = t[i - 1][j] + t[i][j - coins[i - 1]]; // if current coin is lesser than amount we can select it and come back to it or not select it at all(because it is unbounded cause no of coins is unlimited).

            else
                t[i][j] = t[i - 1][j]; // the current coin is larger than the amount and thus we dont consider it
        }
    }
    return t[length][amount];
}