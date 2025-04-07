// 368. Largest Divisible Subset
// Solved
// Medium
// Topics
// Companies
// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.
// Example 2:

// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 2 * 109
// All the integers in nums are unique.

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
            return {};

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);    // dp[i]: length of largest subset ending at nums[i]
        vector<int> prev(n, -1); // prev[i]: index of previous element in the subset
        int maxIdx = 0;          // index of last element of the largest subset

        // Build dp and prev arrays
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIdx])
            {
                maxIdx = i;
            }
        }

        // Reconstruct the subset
        vector<int> result;
        while (maxIdx >= 0)
        {
            result.push_back(nums[maxIdx]);
            maxIdx = prev[maxIdx];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

/*
This code finds the largest divisible subset in a given array of integers. A divisible subset is one where for any two numbers in the subset, the larger number is divisible by the smaller number.

Algorithm steps:
1. Sort the array in ascending order
2. Use dynamic programming to build the largest subset:
   - dp[i] stores the length of largest subset ending at nums[i]
   - prev[i] stores the previous index in the subset
3. For each number, check divisibility with previous numbers
4. Track the maximum subset length and its ending index
5. Reconstruct the subset using the prev array
6. Reverse the result to get correct order

Time Complexity: O(n^2) where n is the size of input array
Space Complexity: O(n) for dp and prev arrays
*/