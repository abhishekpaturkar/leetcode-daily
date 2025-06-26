// 2311. Longest Binary Subsequence Less Than or Equal to K

// You are given a binary string s and a positive integer k.

// Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.

// Note:

// The subsequence can contain leading zeroes.
// The empty string is considered to be equal to 0.
// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
 

// Example 1:

// Input: s = "1001010", k = 5
// Output: 5
// Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
// Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
// The length of this subsequence is 5, so 5 is returned.
// Example 2:

// Input: s = "00101001", k = 1
// Output: 6
// Explanation: "000001" is the longest subsequence of s that makes up a binary number less than or equal to 1, as this number is equal to 1 in decimal.
// The length of this subsequence is 6, so 6 is returned.
 

// Constraints:

// 1 <= s.length <= 1000
// s[i] is either '0' or '1'.
// 1 <= k <= 109

class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        int n = s.size();
        int zeros = 0, ones = 0;
        long long value = 0, pow = 1;

        for (char c : s)
        {
            if (c == '0')
                zeros++;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                if (value + pow > k)
                {
                    continue; // Skip this '1' as it would exceed k
                }
                value += pow;
                ones++;
            }
            pow <<= 1;
            if (pow > k)
                break; // Further bits would exceed k
        }

        return zeros + ones;
    }
};

/*
Code Explanation:
This solution finds the longest binary subsequence less than or equal to k using a greedy approach:
1. First counts all zeros in the string as they don't affect the value
2. Then processes ones from right to left (least significant to most significant)
3. For each '1', checks if including it keeps the value <= k
4. Uses pow to track the position value (1, 2, 4, 8, etc.)
5. Returns total count of usable zeros and ones

Time Complexity: O(n) where n is the length of string
Space Complexity: O(1) as we only use a constant amount of extra space
*/