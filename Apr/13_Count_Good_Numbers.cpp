// 1922. Count Good Numbers

// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 

// Example 1:

// Input: n = 1
// Output: 5
// Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
// Example 2:

// Input: n = 4
// Output: 400
// Example 3:

// Input: n = 50
// Output: 564908303
 

// Constraints:

// 1 <= n <= 1015

class Solution
{
public:
    long long helper(long long base, long long expo, long long mod)
    {
        long long ans = 1;
        while (expo > 0)
        {
            if (expo % 2 == 0)
            {
                base = (base * base) % mod;
                expo = expo / 2;
            }
            else
            {
                ans = (ans * base) % mod;
                expo -= 1;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n)
    {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        long long mod = 1e9 + 7;
        return (int)((helper(5, even, mod) * helper(4, odd, mod)) % mod);
    }
};

/*
Code Explanation:
This solution counts good numbers where even indices must have even digits (0,2,4,6,8) and odd indices must have prime digits (2,3,5,7).

The helper function implements fast power (binary exponentiation) to calculate (base^expo) % mod efficiently:
- It uses the property that a^n = (a^(n/2))^2 if n is even
- And a^n = a * a^(n-1) if n is odd
- Modulo is applied at each step to prevent overflow

The countGoodNumbers function:
- For even positions (0-based index), we have 5 choices (0,2,4,6,8)
- For odd positions, we have 4 choices (2,3,5,7)
- For length n, we need:
  * (n+1)/2 even positions (including 0th position)
  * n/2 odd positions
- Final result = (5^even_count * 4^odd_count) % mod

Time Complexity: O(log n) - Due to binary exponentiation
Space Complexity: O(1) - Only uses constant extra space
*/