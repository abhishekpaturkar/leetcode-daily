// 3208. Alternating Groups II

// There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

// colors[i] == 0 means that tile i is red.
// colors[i] == 1 means that tile i is blue.
// An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

// Return the number of alternating groups.

// Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

// Example 1:

// Input: colors = [0,1,0,1,0], k = 3

// Output: 3

// Explanation:

// Alternating groups

// Example 2:

// Input: colors = [0,1,0,0,1,0,1], k = 6

// Output: 2

// Explanation:

// Alternating groups:

// Example 3:

// Input: colors = [1,1,0,1], k = 4

// Output: 0

// Explanation:

// Constraints:

// 3 <= colors.length <= 105
// 0 <= colors[i] <= 1
// 3 <= k <= colors.length

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int maxLen = 1, ans = 0, n = colors.size();
        for (int i = 1; i <= n + k - 2; i++)
        {
            if (colors[i % n] != colors[(i - 1 + n) % n])
            {
                maxLen++;
            }
            else
            {
                maxLen = 1;
            }
            if (maxLen >= k)
                ans++;
        }
        return ans;
    }
};

/*
This code finds the number of alternating groups in a circular array of colors. Here's how it works:

1. Takes a vector of colors (0s and 1s) and group size k as input
2. Uses maxLen to track current length of alternating sequence
3. Iterates through array considering circular nature using modulo (%)
4. For each position, compares current color with previous color:
   - If different: increases maxLen
   - If same: resets maxLen to 1
5. Whenever maxLen reaches or exceeds k, increments answer counter
6. Returns total count of valid alternating groups

The loop runs n+k-2 times to handle circular wrapping and ensure all possible groups are checked.
*/