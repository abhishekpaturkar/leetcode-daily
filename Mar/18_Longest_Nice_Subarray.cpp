// 2401. Longest Nice Subarray

// You are given an array nums consisting of positive integers.

// We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

// Return the length of the longest nice subarray.

// A subarray is a contiguous part of an array.

// Note that subarrays of length 1 are always considered nice.

// Example 1:

// Input: nums = [1,3,8,48,10]
// Output: 3
// Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
// - 3 AND 8 = 0.
// - 3 AND 48 = 0.
// - 8 AND 48 = 0.
// It can be proven that no longer nice subarray can be obtained, so we return 3.
// Example 2:

// Input: nums = [3,1,5,11,13]
// Output: 1
// Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int n = nums.size(), left = 0, right = 1, maxi = 1, mask = nums[0];

        while (right < n)
        {
            while ((mask & nums[right]) != 0)
                mask ^= nums[left++];
            mask |= nums[right];
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};

/*
This code finds the longest nice subarray in the given array nums where bitwise AND of any two elements in the subarray is 0.

Algorithm:
1. Uses sliding window approach with two pointers - left and right
2. Maintains a mask to track the bits set in current window
3. For each new element (right pointer):
   - If it has common bits with mask (AND != 0), remove elements from left until no common bits
   - Add new element to mask using OR
   - Update maximum length found so far
4. Returns the maximum length found

Time Complexity: O(n) where n is length of nums
- While loop runs n times
- Inner while loop total operations across all iterations is O(n)

Space Complexity: O(1)
- Uses only constant extra space for variables
*/