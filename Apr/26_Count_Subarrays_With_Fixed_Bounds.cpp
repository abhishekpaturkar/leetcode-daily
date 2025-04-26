// 2444. Count Subarrays With Fixed Bounds

// You are given an integer array nums and two integers minK and maxK.

// A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

// The minimum value in the subarray is equal to minK.
// The maximum value in the subarray is equal to maxK.
// Return the number of fixed-bound subarrays.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
// Output: 2
// Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
// Example 2:

// Input: nums = [1,1,1,1], minK = 1, maxK = 1
// Output: 10
// Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
 

// Constraints:

// 2 <= nums.length <= 105
// 1 <= nums[i], minK, maxK <= 106

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int pMin = -1, pMax = -1, bad = -1;
        long long ans = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == minK)
                pMin = i;
            if (nums[i] == maxK)
                pMax = i;
            if (nums[i] < minK || nums[i] > maxK)
                bad = i;
            if (pMin != -1 && pMax != -1)
            {
                ans += max(0, min(pMin, pMax) - bad);
            }
        }
        return ans;
    }
};

/*
This solution uses a sliding window approach to count subarrays with fixed bounds.
- pMin tracks the last position where we found minK
- pMax tracks the last position where we found maxK
- bad tracks the last position where we found a number outside [minK, maxK]
- For each position, we update these trackers and if we have both minK and maxK,
  we add the count of valid subarrays ending at current position
- The formula min(pMin,pMax) - bad gives us the count of valid starting points
  for subarrays ending at current position

Time Complexity: O(n) where n is length of nums array
Space Complexity: O(1) as we only use constant extra space
*/