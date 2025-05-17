// 75. Sort Colors

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zero = 0;
        int two = nums.size() - 1;
        int ones = 0;

        while (ones <= two)
        {
            if (nums[ones] == 0)
            {
                swap(nums[zero], nums[ones]);
                zero++;
                ones++;
            }
            else if (nums[ones] == 2)
            {
                swap(nums[ones], nums[two]);
                two--;
            }
            else
            {
                ones++;
            }
        }
    }
};

/*
This solution uses the Dutch National Flag algorithm to sort colors in-place.
We use three pointers:
- 'zero' points to the rightmost boundary of 0s
- 'two' points to the leftmost boundary of 2s
- 'ones' is used to traverse the array

The algorithm works by:
1. If we find 0, swap it with element at 'zero' pointer and increment both 'zero' and 'ones'
2. If we find 2, swap it with element at 'two' pointer and decrement 'two'
3. If we find 1, just increment 'ones'

Time Complexity: O(n) where n is the length of array
Space Complexity: O(1) as we are sorting in-place
*/