int numberOfSubstrings(string s)
{
    int len = s.size();
    vector<int> pref0(len);
    vector<int> pref1(len);
    pref0[0] = s[0] == '0';
    pref1[0] = s[0] == '1';
    for (int i = 1; i < len; i++)
    {
        pref0[i] = pref0[i - 1] + (s[i] == '0');
        pref1[i] = pref1[i - 1] + (s[i] == '1');
    }

    int count = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len;)
        {
            int zeros = pref0[j] - (i ? pref0[i - 1] : 0);
            int ones = pref1[j] - (i ? pref1[i - 1] : 0);

            int skip = zeros * zeros - ones;

            if (ones >= zeros * zeros)
            {
                skip = max((int)sqrt(ones) - zeros, 1); // max, so it doesnt go negative
                count += min(skip, len - j);            // min, so it doenst go above remaining length
            }

            j += skip;
        }
    }
    return count;
}