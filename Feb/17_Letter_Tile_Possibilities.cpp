// 1079. Letter Tile Possibilities
// Solved
// Medium
// Topics
// Companies
// Hint
// You have n  tiles, where each tile has one letter tiles[i] printed on it.

// Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

 

// Example 1:

// Input: tiles = "AAB"
// Output: 8
// Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
// Example 2:

// Input: tiles = "AAABBC"
// Output: 188
// Example 3:

// Input: tiles = "V"
// Output: 1
 

// Constraints:

// 1 <= tiles.length <= 7
// tiles consists of uppercase English letters.

class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        int n = tiles.length();
        vector<int> counts(26, 0);
        vector<int> fac(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            fac[i] = i * fac[i - 1];
        }
        for (char c : tiles)
        {
            counts[c - 'A']++;
        }
        vector<int> lengthcounts(n + 1, 0);
        lengthcounts[0] = 1;
        for (int i = 0; i < 26; i++)
        {
            if (counts[i] > 0)
            {
                vector<int> temp(n + 1, 0);
                for (int j = 0; j <= n && lengthcounts[j] > 0; j++)
                {
                    for (int k = 1; k <= counts[i]; k++)
                    {
                        int totallength = j + k;
                        temp[totallength] += lengthcounts[j] * fac[totallength] / (fac[k] * fac[j]);
                    }
                }
                for (int j = 0; j <= n; j++)
                {
                    lengthcounts[j] += temp[j];
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += lengthcounts[i];
        }
        return ans;
    }
};

/*
This code solves the Letter Tile Possibilities problem using combinatorics:
1. First calculates factorial values up to n for later use
2. Counts frequency of each letter in input string
3. Uses dynamic programming approach where:
   - lengthcounts[i] stores number of possible sequences of length i
   - For each letter that exists in input:
     * Calculates new possibilities by adding 1 to k occurrences of current letter
     * Uses combination formula with factorials for calculation
4. Finally sums up all possibilities of lengths 1 to n
The solution handles repeated letters correctly by using combinatorial mathematics
*/