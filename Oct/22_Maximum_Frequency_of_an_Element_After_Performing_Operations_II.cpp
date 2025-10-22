// 3347. Maximum Frequency of an Element After Performing Operations II

// You are given an integer array nums and two integers k and numOperations.

// You must perform an operation numOperations times on nums, where in each operation you:

// Select an index i that was not selected in any previous operations.
// Add an integer in the range [-k, k] to nums[i].
// Return the maximum possible frequency of any element in nums after performing the operations.

 

// Example 1:

// Input: nums = [1,4,5], k = 1, numOperations = 2

// Output: 2

// Explanation:

// We can achieve a maximum frequency of two by:

// Adding 0 to nums[1], after which nums becomes [1, 4, 5].
// Adding -1 to nums[2], after which nums becomes [1, 4, 4].
// Example 2:

// Input: nums = [5,11,20,20], k = 5, numOperations = 1

// Output: 2

// Explanation:

// We can achieve a maximum frequency of two by:

// Adding 0 to nums[1].
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 0 <= k <= 109
// 0 <= numOperations <= nums.length

class Solution
{
public:
    static int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        const int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0, cnt = 0;
        int l = 0, r = 0;
        // Consider nums[i]
        for (int i = 0; i < n; i++)
        {
            const int x = nums[i], L = max(1, x - k), R = min(nums.back(), x + k);

            // count freq
            int f = 1;
            int j = i + 1;
            for (; j < n && nums[j] == x; j++)
                f++;
            i = j - 1; // nums[j]!=x

            // move l
            while (l < n && nums[l] < L)
                l++;

            // move r
            r = (r > i) ? r : i; // start r from last position
            while (r + 1 < n && nums[r + 1] <= R)
                r++;

            cnt = r - l + 1;
            ans = max(ans, f + min(cnt - f, numOperations));
        }

        // consider the subintervals with overlapping
        for (l = 0, r = 0; r < n; r++)
        {
            int x = nums[r], L = max(1, x - 2 * k);
            while (l < r && nums[l] < L)
                l++;
            ans = max(ans, min(r - l + 1, numOperations));
        }
        return ans;
    }
};