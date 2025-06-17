// 3405. Count the Number of Arrays with K Matching Adjacent Elements

// You are given three integers n, m, k. A good array arr of size n is defined as follows:

// Each element in arr is in the inclusive range [1, m].
// Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
// Return the number of good arrays that can be formed.

// Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: n = 3, m = 2, k = 1

// Output: 4

// Explanation:

// There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2, 2, 1].
// Hence, the answer is 4.
// Example 2:

// Input: n = 4, m = 2, k = 2

// Output: 6

// Explanation:

// The good arrays are [1, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 2], [2, 1, 1, 1], [2, 2, 1, 1] and [2, 2, 2, 1].
// Hence, the answer is 6.
// Example 3:

// Input: n = 5, m = 2, k = 0

// Output: 2

// Explanation:

// The good arrays are [1, 2, 1, 2, 1] and [2, 1, 2, 1, 2]. Hence, the answer is 2.
 

// Constraints:

// 1 <= n <= 105
// 1 <= m <= 105
// 0 <= k <= n - 1

const int MOD = 1e9 + 7;

class Solution
{
public:
    long long modInverse(long long a, long long mod)
    {
        long long res = 1;
        long long power = mod - 2;

        while (power)
        {
            if (power & 1)
                res = res * a % mod;
            a = a * a % mod;
            power >>= 1;
        }

        return res;
    }

    int nCr(int n, int r)
    {
        if (r > n)
            return 0;
        if (r == 0 || r == n)
            return 1;

        long long res = 1;

        for (int i = 1; i <= r; i++)
        {
            res = res * (n - r + i) % MOD;
            res = res * modInverse(i, MOD) % MOD;
        }

        return (int)res;
    }

    long long bin_expo(long long a, long long b)
    {
        long long result = 1;
        while (b)
        {
            if (b & 1)
                result = (result * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }

    int countGoodArrays(int n, int m, int k)
    {
        // bin_expo = binary exponentiation = power a^b
        int formula = (m * 1ll * bin_expo(m - 1, n - (k + 1))) % MOD;

        int updated_formula = (formula * 1ll * nCr(n - 1, k)) % MOD;

        return updated_formula;
    }
};

/*
Code Explanation:
This solution counts the number of arrays with k matching adjacent elements using combinatorics.

1. modInverse(): Calculates modular multiplicative inverse using Fermat's little theorem
2. nCr(): Computes combination (n choose r) using modular arithmetic
3. bin_expo(): Implements binary exponentiation for efficient power calculation
4. countGoodArrays(): Main function that:
   - Uses formula: m * (m-1)^(n-k-1) * C(n-1,k)
   - m: possible values for each position
   - (m-1)^(n-k-1): non-matching positions
   - C(n-1,k): ways to choose k matching positions

Time Complexity: 
- modInverse(): O(log MOD)
- nCr(): O(r)
- bin_expo(): O(log b)
- Overall: O(k + log(n))

Space Complexity: O(1) - uses only constant extra space
*/