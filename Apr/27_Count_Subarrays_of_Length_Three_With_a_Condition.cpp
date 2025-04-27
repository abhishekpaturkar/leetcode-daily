// 3392. Count Subarrays of Length Three With a Condition

// Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.

// Example 1:

// Input: nums = [1,2,1,4,1]

// Output: 1

// Explanation:

// Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.

// Example 2:

// Input: nums = [1,1,1]

// Output: 0

// Explanation:

// [1,1,1] is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.

 

// Constraints:

// 3 <= nums.length <= 100
// -100 <= nums[i] <= 100

class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i + 2 < nums.size(); i++)
            if (2 * (nums[i] + nums[i + 2]) == nums[i + 1])
                count++;
        return count;
    }
};

/*
This code counts the number of subarrays of length 3 where sum of first and third elements equals half of middle element.
It uses a single loop to iterate through array, checking each possible subarray of length 3.
For each position i, it checks if nums[i] + nums[i+2] = nums[i+1]/2
If condition is met, increment counter.

Time Complexity: O(n) where n is length of input array
Space Complexity: O(1) as only using constant extra space
*/