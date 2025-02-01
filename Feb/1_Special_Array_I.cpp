// 3151. Special Array I
// Solved
// Easy
// Topics
// Companies
// Hint
// An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

// You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

// Example 1:

// Input: nums = [1]

// Output: true

// Explanation:

// There is only one element. So the answer is true.

// Example 2:

// Input: nums = [2,1,4]

// Output: true

// Explanation:

// There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.

// Example 3:

// Input: nums = [4,3,1,6]

// Output: false

// Explanation:

// nums[1] and nums[2] are both odd. So the answer is false.

 

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100

class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] % 2 == nums[i + 1] % 2)
            {
                return false;
            }
        }
        return true;
    }
};

/*
This code checks if an array is "special" based on the parity of adjacent elements:
1. Takes a vector of integers as input
2. Iterates through the array up to second-to-last element
3. For each pair of adjacent elements, checks if they have the same parity using modulo 2
4. Returns false if any adjacent elements have same parity
5. Returns true if all adjacent elements have different parity
*/