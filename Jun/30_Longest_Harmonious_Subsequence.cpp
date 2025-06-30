// 594. Longest Harmonious Subsequence

// We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

// Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

 

// Example 1:

// Input: nums = [1,3,2,2,5,2,3,7]

// Output: 5

// Explanation:

// The longest harmonious subsequence is [3,2,2,2,3].

// Example 2:

// Input: nums = [1,2,3,4]

// Output: 2

// Explanation:

// The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

// Example 3:

// Input: nums = [1,1,1,1]

// Output: 0

// Explanation:

// No harmonic subsequence exists.

 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -109 <= nums[i] <= 109

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int j = 0, maxLength = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] - nums[j] > 1)
            {
                ++j;
            }
            if (nums[i] - nums[j] == 1)
            {
                maxLength = max(maxLength, i - j + 1);
            }
        }
        return maxLength;
    }
};

/*
This solution finds the longest harmonious subsequence in the array using a two-pointer approach:
1. First sorts the array to have elements in ascending order
2. Uses two pointers i and j to maintain a window
3. For each element at i, moves j forward while difference between nums[i] and nums[j] > 1
4. When difference is exactly 1, updates maxLength with current window size (i-j+1)
5. Returns the maximum length found

Time Complexity: O(nlogn) due to sorting
Space Complexity: O(1) as only constant extra space is used
*/