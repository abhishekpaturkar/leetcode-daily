// 790. Domino and Tromino Tiling

// You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


// Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

// In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

// Example 1:


// Input: n = 3
// Output: 5
// Explanation: The five different ways are show above.
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 1000

const int MOD = 1e9 + 7;
class Solution
{
public:
    int numTilings(int n)
    {
        if (n == 0 || n == 1 || n == 2)
            return n;
        vector<long long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = (2 * dp[i - 1] % MOD + dp[i - 3] % MOD) % MOD;
        }
        return dp[n];
    }
};

/*
This code solves the problem of counting the number of ways to tile a 2 x n board using domino and tromino tiles.

The solution uses dynamic programming with a recurrence relation:
dp[i] = 2 * dp[i-1] + dp[i-3]

Base cases:
- dp[0] = 1 (empty board)
- dp[1] = 1 (single column)
- dp[2] = 2 (two columns)

For each position i >= 3, we:
1. Multiply previous state by 2 (2 * dp[i-1])
2. Add the state from 3 positions back (dp[i-3])
3. Take modulo to handle large numbers

Time Complexity: O(n) - single pass through array
Space Complexity: O(n) - dp array to store states
*/