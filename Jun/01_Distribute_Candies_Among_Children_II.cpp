// 2929. Distribute Candies Among Children II

// You are given two positive integers n and limit.

// Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.

 

// Example 1:

// Input: n = 5, limit = 2
// Output: 3
// Explanation: There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).
// Example 2:

// Input: n = 3, limit = 3
// Output: 10
// Explanation: There are 10 ways to distribute 3 candies such that no child gets more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).
 

// Constraints:

// 1 <= n <= 106
// 1 <= limit <= 106


class Solution
{
public:
    long long distributeCandies(int n, int limit)
    {
        vector<vector<long long>> dp(2, vector<long long>(n + 1));
        dp[0][0] = 1;
        for (int j = 1; j <= n; j++)
        {
            dp[0][j] = dp[0][j - 1] + (j <= limit);
        }
        dp[1][0] = 1;
        for (int j = 1; j <= n; j++)
        {
            dp[1][j] += dp[1][j - 1] + (dp[1 - 1][j] - (j - limit - 1 >= 0 ? dp[1 - 1][j - limit - 1] : 0));
        }
        return dp[1][n] - (n - limit - 1 >= 0 ? dp[1][n - limit - 1] : 0);
    }
};

/*
This code solves the problem of distributing n candies among 3 children with a limit on candies per child using dynamic programming:

1. Uses a 2D DP array where dp[i][j] represents ways to distribute j candies among i+1 children
2. First row (dp[0]) calculates ways for first child
3. Second row (dp[1]) builds on first row for two children
4. Final result subtracts invalid distributions for three children

Time Complexity: O(n) where n is the number of candies
Space Complexity: O(n) for the 2D DP array
*/