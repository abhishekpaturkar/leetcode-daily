// 1800. Maximum Ascending Subarray Sum
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

// A subarray is defined as a contiguous sequence of numbers in an array.

// A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.

// Example 1:

// Input: nums = [10,20,30,5,10,50]
// Output: 65
// Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
// Example 2:

// Input: nums = [10,20,30,40,50]
// Output: 150
// Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
// Example 3:

// Input: nums = [12,17,15,13,10,11,12]
// Output: 33
// Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int curr = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            curr = nums[i] > nums[i - 1] ? curr + nums[i] : nums[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};

/*
This code finds the maximum sum of an ascending subarray in a given vector of integers.
Here's how it works:
1. Initialize curr and ans with first element of array
2. Iterate through array starting from second element
3. For each element:
   - If current number is greater than previous (ascending), add it to curr sum
   - If not ascending, reset curr sum to current number
4. Keep track of maximum sum seen so far in ans
5. Return the maximum sum found
The solution uses O(n) time complexity and O(1) space complexity.
*/