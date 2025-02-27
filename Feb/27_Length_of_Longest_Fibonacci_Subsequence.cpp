// 873. Length of Longest Fibonacci Subsequence

// A sequence x1, x2, ..., xn is Fibonacci-like if:

// n >= 3
// xi + xi+1 == xi+2 for all i + 2 <= n
// Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

// A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].


// Example 1:

// Input: arr = [1,2,3,4,5,6,7,8]
// Output: 5
// Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
// Example 2:

// Input: arr = [1,3,7,11,12,14,18]
// Output: 3
// Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].
 

// Constraints:

// 3 <= arr.length <= 1000
// 1 <= arr[i] < arr[i + 1] <= 109

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxLen = 0;

        for (int curr = 2; curr < n; curr++)
        {
            int start = 0, end = curr - 1;
            while (start < end)
            {
                int pairSum = arr[start] + arr[end];
                if (pairSum > arr[curr])
                {
                    end--;
                }
                else if (pairSum < arr[curr])
                {
                    start++;
                }
                else
                {
                    dp[end][curr] = dp[start][end] + 1;
                    maxLen = max(dp[end][curr], maxLen);
                    end--;
                    start++;
                }
            }
        }
        return maxLen == 0 ? 0 : maxLen + 2;
    }
};

/*
This code finds the length of the longest Fibonacci-like subsequence in a sorted array. Here's how it works:

1. Uses a 2D DP array where dp[i][j] represents the length of Fibonacci subsequence ending at indices i,j
2. For each position 'curr', tries to find two previous numbers that sum up to arr[curr]
3. Uses two pointers 'start' and 'end' to find pairs that sum to arr[curr]
4. When a valid pair is found (pairSum == arr[curr]):
   - Updates dp[end][curr] by adding 1 to the length of previous Fibonacci subsequence
   - Updates maxLen to track the longest subsequence found
5. Returns maxLen + 2 (adding 2 for the first two numbers) if a sequence exists, 0 otherwise

Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/