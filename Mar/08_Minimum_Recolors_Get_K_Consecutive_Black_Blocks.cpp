// 2379. Minimum Recolors to Get K Consecutive Black Blocks

// You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

// You are also given an integer k, which is the desired number of consecutive black blocks.

// In one operation, you can recolor a white block such that it becomes a black block.

// Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

// Example 1:

// Input: blocks = "WBBWWBBWBW", k = 7
// Output: 3
// Explanation:
// One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
// so that blocks = "BBBBBBBWBW".
// It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
// Therefore, we return 3.
// Example 2:

// Input: blocks = "WBWBBBW", k = 2
// Output: 0
// Explanation:
// No changes need to be made, since 2 consecutive black blocks already exist.
// Therefore, we return 0.

// Constraints:

// n == blocks.length
// 1 <= n <= 100
// blocks[i] is either 'W' or 'B'.
// 1 <= k <= n

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int black_count = 0, ans = INT_MAX;

        for (int i = 0; i < blocks.size(); i++)
        {
            if (i - k >= 0 && blocks[i - k] == 'B')
                black_count--;
            if (blocks[i] == 'B')
                black_count++;
            ans = min(ans, k - black_count);
        }

        return ans;
    }
};

/*
This code solves the problem of finding minimum recolors needed to get k consecutive black blocks:
1. Uses sliding window approach with size k
2. black_count keeps track of number of black blocks in current window
3. For each position i:
   - If window moves past a black block (i-k), decrease black_count
   - If current position has black block, increase black_count
   - Calculate minimum operations needed (k - black_count) for current window
4. Returns minimum operations found across all windows
*/