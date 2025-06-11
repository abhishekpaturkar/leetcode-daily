// 3445. Maximum Difference Between Even and Odd Frequency II

// You are given a string s and an integer k. Your task is to find the maximum difference between the frequency of two characters, freq[a] - freq[b], in a substring subs of s, such that:

// subs has a size of at least k.
// Character a has an odd frequency in subs.
// Character b has an even frequency in subs.
// Return the maximum difference.

// Note that subs can contain more than 2 distinct characters.
 

// Example 1:

// Input: s = "12233", k = 4

// Output: -1

// Explanation:

// For the substring "12233", the frequency of '1' is 1 and the frequency of '3' is 2. The difference is 1 - 2 = -1.

// Example 2:

// Input: s = "1122211", k = 3

// Output: 1

// Explanation:

// For the substring "11222", the frequency of '2' is 3 and the frequency of '1' is 2. The difference is 3 - 2 = 1.

// Example 3:

// Input: s = "110", k = 3

// Output: -1

 

// Constraints:

// 3 <= s.length <= 3 * 104
// s consists only of digits '0' to '4'.
// The input is generated that at least one substring has a character with an even frequency and a character with an odd frequency.
// 1 <= k <= s.length

class Solution
{
public:
    int maxDifference(string s, int k)
    {
        int n = s.size();
        int ans = INT_MIN;

        // Step 1: Try all (a, b) pairs
        for (int a = 0; a <= 4; ++a)
        {
            for (int b = 0; b <= 4; ++b)
            {
                if (a == b)
                {
                    continue;
                }

                vector<int> s1(n + 1);
                vector<int> s2(n + 1);

                // Step 2: Prefix counts
                for (int i = 1; i <= n; ++i)
                {
                    s1[i] = s1[i - 1] + (s[i - 1] - '0' == a);
                    s2[i] = s2[i - 1] + (s[i - 1] - '0' == b);
                }

                // Step 3: Matrix for best difference at each parity
                int g[2][2] = {{INT_MIN, INT_MIN}, {INT_MIN, INT_MIN}};
                int j = 0;

                // Step 4: Sliding window
                for (int i = k; i <= n; ++i)
                {
                    while (i - j >= k && s1[i] > s1[j] && s2[i] > s2[j])
                    {
                        int pa = s1[j] % 2;
                        int pb = s2[j] % 2;
                        g[pa][pb] = max(g[pa][pb], s2[j] - s1[j]);
                        ++j;
                    }

                    // Step 5: Check if valid
                    int pa = s1[i] % 2;
                    int pb = s2[i] % 2;
                    int need = g[1 - pa][pb];

                    if (need != INT_MIN)
                    {
                        ans = max(ans, (s1[i] - s2[i]) + need);
                    }
                }
            }
        }

        return ans == INT_MIN ? -1 : ans;
    }
};

/*
Code Explanation:
This solution finds the maximum difference between odd and even frequency characters in substrings of length >= k.

1. The outer loops iterate through all possible pairs of digits (0-4).
2. For each pair (a,b), we maintain prefix sum arrays s1 and s2 to count occurrences.
3. A 2x2 matrix g stores the best differences found so far for each parity combination.
4. Using sliding window technique, we process all possible substrings of length >= k.
5. For each window, we update the best differences and check if we can find a valid answer.
6. Finally, return the maximum difference found or -1 if no valid solution exists.

Time Complexity: O(n * 25), where n is string length
- Outer loops: O(5 * 5) = O(25)
- For each pair: O(n) operations
Total: O(25 * n) = O(n)

Space Complexity: O(n)
- Two prefix arrays of size n+1
- Constant extra space for matrix g
*/