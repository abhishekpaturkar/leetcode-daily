// 3356. Zero Array Transformation II

// You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

// Each queries[i] represents the following action on nums:

// Decrement the value at each index in the range [li, ri] in nums by at most vali.
// The amount by which each value is decremented can be chosen independently for each index.
// A Zero Array is an array with all its elements equal to 0.

// Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

// Example 1:

// Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]

// Output: 2

// Explanation:

// For i = 0 (l = 0, r = 2, val = 1):
// Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
// The array will become [1, 0, 1].
// For i = 1 (l = 0, r = 2, val = 1):
// Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
// The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum value of k is 2.
// Example 2:

// Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]

// Output: -1

// Explanation:

// For i = 0 (l = 1, r = 3, val = 2):
// Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
// The array will become [4, 1, 0, 0].
// For i = 1 (l = 0, r = 2, val = 1):
// Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
// The array will become [3, 0, 0, 0], which is not a Zero Array.

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 5 * 105
// 1 <= queries.length <= 105
// queries[i].length == 3
// 0 <= li <= ri < nums.length
// 1 <= vali <= 5

class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        auto canMakeZeroArray = [&](int k)
        {
            vector<int> diff(n + 1, 0);
            for (int i = 0; i < k; i++)
            {
                int left = queries[i][0], right = queries[i][1], val = queries[i][2];
                diff[left] += val;
                diff[right + 1] -= val;
            }
            int currVal = 0;
            for (int i = 0; i < n; i++)
            {
                currVal += diff[i];
                if (currVal < nums[i])
                    return false;
            }
            return true;
        };
        if (all_of(nums.begin(), nums.end(), [](int x)
                   { return x == 0; }))
            return 0;
        int left = 1, right = queries.size();
        if (!canMakeZeroArray(right))
            return -1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (canMakeZeroArray(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

/*
This code implements a solution to find the minimum number of queries needed to transform an array into a Zero Array.

Algorithm:
1. The code uses binary search to find the minimum number of queries (k) needed.
2. For each potential k, it uses a difference array technique to simulate the effect of the first k queries.
3. The canMakeZeroArray lambda function checks if it's possible to make the array zero using k queries.
4. The difference array helps efficiently track cumulative changes in ranges.
5. Binary search narrows down the minimum k required.

Time Complexity: O(n * log q) where:
- n is the length of nums array
- q is the number of queries
- For each binary search step, we scan the array once

Space Complexity: O(n)
- Uses a difference array of size n+1
*/