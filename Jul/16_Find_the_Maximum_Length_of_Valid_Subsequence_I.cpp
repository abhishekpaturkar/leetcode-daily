// 3201. Find the Maximum Length of Valid Subsequence I

// You are given an integer array nums.
// A subsequence sub of nums with length x is called valid if it satisfies:

// (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
// Return the length of the longest valid subsequence of nums.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: nums = [1,2,3,4]

// Output: 4

// Explanation:

// The longest valid subsequence is [1, 2, 3, 4].

// Example 2:

// Input: nums = [1,2,1,1,2,1,2]

// Output: 6

// Explanation:

// The longest valid subsequence is [1, 2, 1, 2, 1, 2].

// Example 3:

// Input: nums = [1,3]

// Output: 2

// Explanation:

// The longest valid subsequence is [1, 3].

 

// Constraints:

// 2 <= nums.length <= 2 * 105
// 1 <= nums[i] <= 107

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int count_even = 0, count_odd = 0;
        for (int num : nums)
        {
            if (num % 2 == 0)
                count_even++;
            else
                count_odd++;
        }

        int even_dp = 0, odd_dp = 0;
        for (int num : nums)
        {
            if (num % 2 == 0)
                even_dp = max(even_dp, odd_dp + 1);
            else
                odd_dp = max(odd_dp, even_dp + 1);
        }

        return max({count_even, count_odd, even_dp, odd_dp});
    }
};

/*
Code Explanation:
This solution finds the maximum length of a valid subsequence where adjacent elements sum to either all even or all odd numbers.

The algorithm works in two parts:
1. First loop counts total even and odd numbers in the array
2. Second loop uses dynamic programming to find longest alternating even-odd subsequence:
   - even_dp tracks max subsequence ending with even number
   - odd_dp tracks max subsequence ending with odd number
   
Finally returns maximum of:
- Total even numbers (count_even)
- Total odd numbers (count_odd) 
- Longest even-ending subsequence (even_dp)
- Longest odd-ending subsequence (odd_dp)

Time Complexity: O(n) where n is length of input array
Space Complexity: O(1) as we only use constant extra space
*/