// 3423. Maximum Difference Between Adjacent Elements in a Circular Array

// Given a circular array nums, find the maximum absolute difference between adjacent elements.

// Note: In a circular array, the first and last elements are adjacent.

 

// Example 1:

// Input: nums = [1,2,4]

// Output: 3

// Explanation:

// Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.

// Example 2:

// Input: nums = [-5,-10,-5]

// Output: 5

// Explanation:

// The adjacent elements nums[0] and nums[1] have the maximum absolute difference of |-5 - (-10)| = 5.

 

// Constraints:

// 2 <= nums.length <= 100
// -100 <= nums[i] <= 100

class Solution
{
public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        int maxi = 0;
        for (int i = 0; i < nums.size() - 1; i++)
            maxi = max(maxi, abs(nums[i + 1] - nums[i]));
        maxi = max(maxi, abs(nums[nums.size() - 1] - nums[0]));
        return maxi;
    }
};

/*
This code finds the maximum absolute difference between adjacent elements in a circular array:
1. Initialize maxi to store maximum difference
2. First loop checks differences between consecutive elements
3. Last line checks difference between first and last element (circular property)
4. Returns the maximum difference found

Time Complexity: O(n) where n is array length
Space Complexity: O(1) as only constant extra space is used
*/