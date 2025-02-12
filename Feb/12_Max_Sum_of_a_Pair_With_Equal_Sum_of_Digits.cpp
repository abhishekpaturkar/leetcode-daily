// 2342. Max Sum of a Pair With Equal Sum of Digits

// You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

// Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

 

// Example 1:

// Input: nums = [18,43,36,13,7]
// Output: 54
// Explanation: The pairs (i, j) that satisfy the conditions are:
// - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
// - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
// So the maximum sum that we can obtain is 54.
// Example 2:

// Input: nums = [10,12,19,14]
// Output: -1
// Explanation: There are no two numbers that satisfy the conditions, so we return -1.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109

class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        int max[82] = {0};
        int ans = -1;
        for (int x : nums)
        {
            int sum = 0, temp = x;
            while (temp != 0)
            {
                sum += temp % 10;
                temp /= 10;
            }
            if (max[sum] != 0)
                ans = std::max(ans, x + max[sum]);
            max[sum] = std::max(max[sum], x);
        }
        return ans;
    }
};

/*
This code finds the maximum sum of two numbers in an array that have the same sum of digits.
It uses an array 'max' to store the maximum number encountered so far for each possible digit sum (0-81).
For each number x in nums:
1. Calculate sum of its digits using modulo and division
2. If we've seen a number with same digit sum before (max[sum] != 0), update answer if current sum is larger
3. Update max[sum] with larger of current number and previous maximum for this digit sum
Returns -1 if no valid pair exists
Time complexity: O(n * logm) where n is array length and m is maximum number in array
Space complexity: O(1) as max array size is fixed at 82
*/