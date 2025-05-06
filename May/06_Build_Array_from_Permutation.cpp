// 1920. Build Array from Permutation

// Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

// A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

 

// Example 1:

// Input: nums = [0,2,1,5,3,4]
// Output: [0,1,2,4,5,3]
// Explanation: The array ans is built as follows: 
// ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
//     = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
//     = [0,1,2,4,5,3]
// Example 2:

// Input: nums = [5,0,1,2,3,4]
// Output: [4,5,0,1,2,3]
// Explanation: The array ans is built as follows:
// ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
//     = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
//     = [4,5,0,1,2,3]
 

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] < nums.length
// The elements in nums are distinct.
 

// Follow-up: Can you solve it without using an extra space (i.e., O(1) memory)?

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            nums[i] += (1024 * (nums[nums[i]] % 1024));

        for (int i = 0; i < nums.size(); i++)
            nums[i] /= 1024;

        return nums;
    }
};

/*
This solution modifies the array in-place without using extra space. Here's how it works:

1. In first loop, for each index i:
   - Original value is stored in nums[i] % 1024
   - New value is stored in nums[nums[i]] % 1024
   - Multiply new value by 1024 and add to original value
   This way both values are stored in same element

2. In second loop:
   - Divide each element by 1024 to get final value
   - This removes original value and keeps only new value

Time Complexity: O(n) where n is length of array
Space Complexity: O(1) as we modify array in-place
*/