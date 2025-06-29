// 1498. Number of Subsequences That Satisfy the Given Sum Condition

// You are given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [3,5,6,7], target = 9
// Output: 4
// Explanation: There are 4 subsequences that satisfy the condition.
// [3] -> Min value + max value <= target (3 + 3 <= 9)
// [3,5] -> (3 + 5 <= 9)
// [3,5,6] -> (3 + 6 <= 9)
// [3,6] -> (3 + 6 <= 9)
// Example 2:

// Input: nums = [3,3,6,8], target = 10
// Output: 6
// Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
// [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
// Example 3:

// Input: nums = [2,3,3,4,6,7], target = 12
// Output: 61
// Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
// Number of valid subsequences (63 - 2 = 61).
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106
// 1 <= target <= 106

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int mod = 1e9 + 7, n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i)
        {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int left = 0, right = n - 1, result = 0;

        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                result = (result + power[right - left]) % mod;
                ++left;
            }
            else
            {
                --right;
            }
        }
        return result;
    }
};

/*
Code Explanation:
This solution finds the number of subsequences where the sum of min and max elements is <= target.

1. First sorts the array to ensure min element is on left and max on right
2. Precomputes powers of 2 modulo 1e9+7 to handle large numbers
3. Uses two pointer approach:
   - Left pointer for minimum element
   - Right pointer for maximum element
4. For each valid pair (nums[left] + nums[right] <= target):
   - Adds 2^(right-left) subsequences to result
   - This works because elements between left and right can either be included or not
5. If sum > target, decrements right to try smaller max element
6. Returns final count modulo 1e9+7

Time Complexity: O(nlogn) due to sorting
Space Complexity: O(n) for power array
*/