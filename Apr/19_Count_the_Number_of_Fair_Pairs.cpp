// 2563. Count the Number of Fair Pairs

// Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

// A pair (i, j) is fair if:

// 0 <= i < j < n, and
// lower <= nums[i] + nums[j] <= upper
 

// Example 1:

// Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
// Output: 6
// Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
// Example 2:

// Input: nums = [1,7,9,2,5], lower = 11, upper = 11
// Output: 1
// Explanation: There is a single fair pair: (2,3).
 

// Constraints:

// 1 <= nums.length <= 105
// nums.length == n
// -109 <= nums[i] <= 109
// -109 <= lower <= upper <= 109

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        for (int l = 0; l < n; l++)
        {
            int x = nums[l], lo = lower - x, hi = upper - x;
            auto i = lower_bound(nums.begin() + l + 1, nums.end(), lo);
            auto j = upper_bound(nums.begin() + l + 1, nums.end(), hi);
            cnt += j - i;
        }
        return cnt;
    }
};

/*
This solution finds fair pairs in a sorted array where the sum of two elements falls within a given range [lower, upper].

Algorithm:
1. Sort the array first to enable binary search
2. For each element x, find elements y where lower <= x + y <= upper
3. Use binary search (lower_bound and upper_bound) to find the range of valid y values
4. Count pairs by taking difference of iterators
5. Accumulate all valid pairs

Time Complexity: O(nlogn) - sorting + O(nlogn) for binary search in loop = O(nlogn)
Space Complexity: O(1) - only using constant extra space
*/