// 2460. Apply Operations to an Array

// You are given a 0-indexed array nums of size n consisting of non-negative integers.

// You need to apply n - 1 operations to this array where, in the ith operation (0-indexed), you will apply the following on the ith element of nums:

// If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.
// After performing all the operations, shift all the 0's to the end of the array.

// For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end, is [1,2,1,0,0,0].
// Return the resulting array.

// Note that the operations are applied sequentially, not all at once.

// Example 1:

// Input: nums = [1,2,2,1,1,0]
// Output: [1,4,2,0,0,0]
// Explanation: We do the following operations:
// - i = 0: nums[0] and nums[1] are not equal, so we skip this operation.
// - i = 1: nums[1] and nums[2] are equal, we multiply nums[1] by 2 and change nums[2] to 0. The array becomes [1,4,0,1,1,0].
// - i = 2: nums[2] and nums[3] are not equal, so we skip this operation.
// - i = 3: nums[3] and nums[4] are equal, we multiply nums[3] by 2 and change nums[4] to 0. The array becomes [1,4,0,2,0,0].
// - i = 4: nums[4] and nums[5] are equal, we multiply nums[4] by 2 and change nums[5] to 0. The array becomes [1,4,0,2,0,0].
// After that, we shift the 0's to the end, which gives the array [1,4,2,0,0,0].
// Example 2:

// Input: nums = [0,1]
// Output: [1,0]
// Explanation: No operation can be applied, we just shift the 0 to the end.

// Constraints:

// 2 <= nums.length <= 2000
// 0 <= nums[i] <= 1000

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
        }
        while (j < nums.size())
        {
            nums[j++] = 0;
        }

        return nums;
    }
};

/*
This code implements a solution to apply operations on an array and move zeros to the end. Here's how it works:

1. First loop: Iterates through the array and checks adjacent elements
   - If two adjacent elements are equal, multiply the first by 2 and set second to 0
   - This implements the operation described in the problem

2. Second part: Uses two-pointer technique to move non-zero elements to front
   - j keeps track of where to place next non-zero element
   - i scans through array finding non-zero elements
   - When found, moves them to position j

3. Final while loop: Fills remaining positions with zeros
   - After moving all non-zero elements to front
   - Fills rest of array with zeros from position j to end

Time Complexity: O(n) where n is array length
Space Complexity: O(1) as it modifies array in-place
*/