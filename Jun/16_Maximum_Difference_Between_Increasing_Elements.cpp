// 2016. Maximum Difference Between Increasing Elements

// Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

// Return the maximum difference. If no such i and j exists, return -1.

 

// Example 1:

// Input: nums = [7,1,5,4]
// Output: 4
// Explanation:
// The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
// Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.
// Example 2:

// Input: nums = [9,4,3,2]
// Output: -1
// Explanation:
// There is no i and j such that i < j and nums[i] < nums[j].
// Example 3:

// Input: nums = [1,5,2,10]
// Output: 9
// Explanation:
// The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.
 

// Constraints:

// n == nums.length
// 2 <= n <= 1000
// 1 <= nums[i] <= 109

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int maxD = -1, xMinL = 1e9, xMaxR = -1;
        for (int l = 0, r = n - 1; l < r; l++)
        {
            xMinL = min(nums[l], xMinL);
            while (l < r && nums[l + 1] > nums[l])
            {
                l++;
                maxD = max(maxD, nums[l] - xMinL);
            }
            xMaxR = max(nums[r], xMaxR);
            while (l < r && nums[r - 1] < nums[r])
            {
                r--;
                maxD = max(maxD, nums[r] - xMaxR);
            }
            maxD = max(maxD, xMaxR - xMinL);
        }
        return maxD == 0 ? -1 : maxD;
    }
};

/*
This solution finds the maximum difference between two elements in an array where the larger element appears after the smaller element.

The algorithm uses two pointers (l and r) starting from the left and right ends of the array:
- xMinL keeps track of the minimum element seen from the left
- xMaxR keeps track of the maximum element seen from the right
- For each position, it:
  1. Updates minimum from left
  2. Moves right while increasing sequence found, updating maxD
  3. Updates maximum from right
  4. Moves left while decreasing sequence found, updating maxD
  5. Updates maxD with difference between overall min and max

If no valid difference is found (maxD = 0), returns -1

Time Complexity: O(n) where n is array length
Space Complexity: O(1) as only constant extra space is used
*/