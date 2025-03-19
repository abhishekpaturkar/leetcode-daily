// 3191. Minimum Operations to Make Binary Array Elements Equal to One I
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a binary array nums.

// You can do the following operation on the array any number of times (possibly zero):

// Choose any 3 consecutive elements from the array and flip all of them.
// Flipping an element means changing its value from 0 to 1, and from 1 to 0.

// Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.

// Example 1:

// Input: nums = [0,1,1,1,0,0]

// Output: 3

// Explanation:
// We can do the following operations:

// Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
// Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
// Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].
// Example 2:

// Input: nums = [0,1,1,1]

// Output: -1

// Explanation:
// It is impossible to make all elements equal to 1.

// Constraints:

// 3 <= nums.length <= 105
// 0 <= nums[i] <= 1

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] == 0)
            {
                cnt++;
                nums[i + 1] ^= 1 ^ 0;
                nums[i + 2] ^= 1 ^ 0;
            }
        }
        return nums[n - 1] && nums[n - 2] ? cnt : -1;
    }
};

/*
Code Explanation:
This solution solves the problem by using a greedy approach. It iterates through the array from left to right and whenever it encounters a 0, it flips the next three elements (including the current one) using XOR operations. The algorithm:

1. Keeps track of number of operations (cnt) and array size (n)
2. Iterates through array up to n-2 (since we need 3 consecutive elements)
3. When a 0 is found:
   - Increments operation count
   - Flips next two elements using XOR with 1
4. Finally checks if last two elements are 1
   - If yes, returns operation count
   - If no, returns -1 (impossible to make all 1s)

Time Complexity: O(n) where n is the length of input array
Space Complexity: O(1) as we only use constant extra space
*/