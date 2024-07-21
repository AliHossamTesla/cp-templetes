/*
 * description: Z-Algorithm - returns the Z-array containing the length of the longest substring
 * of s that begins at position k and is a prefix of s for each k = 0, 1, ..., n-1.
 * source: @Tesla.
 * verification: https://codeforces.com/contest/126/submission/271740441
 */
vector<int> Z(const string &s)
{
    int n = s.size();
    vector<int> z(n);
    int left = 0, right = 0;

    for (int i = 1; i < n; i++)
    {
        if (i <= right)
        {
            z[i] = min(right - i + 1, z[i - left]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] - 1 > right)
        {
            left = i;
            right = i + z[i] - 1;
        }
    }
    return z;
}