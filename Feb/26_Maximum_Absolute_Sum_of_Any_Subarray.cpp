// 1749. Maximum Absolute Sum of Any Subarray

// You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

// Return the maximum absolute sum of any (possibly empty) subarray of nums.

// Note that abs(x) is defined as follows:

// If x is a negative integer, then abs(x) = -x.
// If x is a non-negative integer, then abs(x) = x.
 

// Example 1:

// Input: nums = [1,-3,2,3,-4]
// Output: 5
// Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
// Example 2:

// Input: nums = [2,-5,1,-4,3,-2]
// Output: 8
// Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int sum = 0, minSum = 0, maxSum = 0;
        for (int num : nums)
        {
            sum += num;
            if (sum > maxSum)
                maxSum = sum;
            if (sum < minSum)
                minSum = sum;
        }
        return abs(maxSum - minSum);
    }
};

/*
This solution finds the maximum absolute sum of any subarray using Kadane's algorithm variant:
1. It maintains a running sum (sum) and tracks both maximum (maxSum) and minimum (minSum) sums encountered
2. For each number in array, it adds to running sum and updates maxSum/minSum if needed
3. The maximum absolute sum possible will be the absolute difference between maxSum and minSum
4. This works because the maximum absolute sum will either be:
   - The maximum positive sum (maxSum)
   - The absolute value of the minimum negative sum (-minSum)
   - The absolute difference between a peak and valley (maxSum - minSum)
Time complexity: O(n) where n is length of input array
Space complexity: O(1) as we only use constant extra space
*/