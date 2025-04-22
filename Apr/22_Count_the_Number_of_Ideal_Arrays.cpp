// 2338. Count the Number of Ideal Arrays

// You are given two integers n and maxValue, which are used to describe an ideal array.

// A 0-indexed integer array arr of length n is considered ideal if the following conditions hold:

// Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
// Every arr[i] is divisible by arr[i - 1], for 0 < i < n.
// Return the number of distinct ideal arrays of length n. Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: n = 2, maxValue = 5
// Output: 10
// Explanation: The following are the possible ideal arrays:
// - Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
// - Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
// - Arrays starting with the value 3 (1 array): [3,3]
// - Arrays starting with the value 4 (1 array): [4,4]
// - Arrays starting with the value 5 (1 array): [5,5]
// There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
// Example 2:

// Input: n = 5, maxValue = 3
// Output: 11
// Explanation: The following are the possible ideal arrays:
// - Arrays starting with the value 1 (9 arrays): 
//    - With no other distinct values (1 array): [1,1,1,1,1] 
//    - With 2nd distinct value 2 (4 arrays): [1,1,1,1,2], [1,1,1,2,2], [1,1,2,2,2], [1,2,2,2,2]
//    - With 2nd distinct value 3 (4 arrays): [1,1,1,1,3], [1,1,1,3,3], [1,1,3,3,3], [1,3,3,3,3]
// - Arrays starting with the value 2 (1 array): [2,2,2,2,2]
// - Arrays starting with the value 3 (1 array): [3,3,3,3,3]
// There are a total of 9 + 1 + 1 = 11 distinct ideal arrays.
 

// Constraints:

// 2 <= n <= 104
// 1 <= maxValue <= 104

class Solution
{
public:
    long long dp[15][10001], pr[15][10001], tot[15], mod = 1e9 + 7, mx, n;
    void get(int la, int cn)
    {
        tot[cn]++;
        for (int p = 2 * la; p <= mx; p += la)
            get(p, cn + 1);
    }
    int idealArrays(int nn, int mmx)
    {
        n = nn;
        mx = mmx;
        for (int i = 1; i <= 10000; i++)
            dp[1][i] = 1, pr[1][i] = i;

        for (int i = 2; i < 15; i++)
        {
            for (int j = i; j <= 10000; j++)
            {
                dp[i][j] = pr[i - 1][j - 1];
                pr[i][j] = dp[i][j] + pr[i][j - 1];
                dp[i][j] %= mod, pr[i][j] %= mod;
            }
        }
        long long ans = mx, x;
        for (int i = 1; i <= mx; i++)
            get(i, 1);

        for (int i = 2; i < 15; i++)
        {
            x = tot[i] * dp[i][n];
            x %= mod;
            ans += x;
            ans %= mod;
        }
        return ans;
    }
};

/*
Code Explanation:
This solution uses dynamic programming and combinatorics to count the number of ideal arrays.

1. The code uses a recursive function 'get' to count the number of possible values at each position
   that satisfy the divisibility condition.

2. The dp array stores combinations where:
   - dp[i][j] represents ways to choose i numbers from j positions
   - pr[i][j] stores prefix sums of dp values

3. Main steps:
   - Initialize base cases for dp[1][i]
   - Build dp table using combinations
   - Use recursive get() to find valid number sequences
   - Calculate final answer using combinations and valid sequences

Time Complexity: O(maxValue * log(maxValue) + n * maxValue)
Space Complexity: O(n * maxValue)

The solution handles large numbers using modulo arithmetic (10^9 + 7).
*/