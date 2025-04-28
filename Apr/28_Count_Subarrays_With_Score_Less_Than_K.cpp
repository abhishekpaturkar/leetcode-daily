// 2302. Count Subarrays With Score Less Than K

// The score of an array is defined as the product of its sum and its length.

// For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
// Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

// A subarray is a contiguous sequence of elements within an array.

 

// Example 1:

// Input: nums = [2,1,4,3,5], k = 10
// Output: 6
// Explanation:
// The 6 subarrays having scores less than 10 are:
// - [2] with score 2 * 1 = 2.
// - [1] with score 1 * 1 = 1.
// - [4] with score 4 * 1 = 4.
// - [3] with score 3 * 1 = 3. 
// - [5] with score 5 * 1 = 5.
// - [2,1] with score (2 + 1) * 2 = 6.
// Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, while we need scores strictly less than 10.
// Example 2:

// Input: nums = [1,1,1], k = 5
// Output: 5
// Explanation:
// Every subarray except [1,1,1] has a score less than 5.
// [1,1,1] has a score (1 + 1 + 1) * 3 = 9, which is greater than 5.
// Thus, there are 5 subarrays having scores less than 5.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
// 1 <= k <= 1015

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int start = 0;
        long long sum = 0;
        long long count = 0;

        // Iterate through the array using the 'end' pointer
        for (int end = 0; end < nums.size(); end++)
        {
            sum += nums[end];

            // Shrink the window if the score exceeds or equals 'k'
            while (sum * (end - start + 1) >= k)
            {
                sum -= nums[start];
                start++;
            }

            // Add the number of valid subarrays ending at 'end'
            count += (end - start + 1);
        }

        return count;
    }
};

/*
This solution uses the sliding window technique to find subarrays with score less than k.
- We maintain a window with two pointers: 'start' and 'end'
- For each position of 'end', we add nums[end] to our running sum
- We shrink the window from the start while the score (sum * length) >= k
- The number of valid subarrays ending at current 'end' is (end - start + 1)
- We keep adding these counts to get total number of valid subarrays

Time Complexity: O(n) where n is length of nums array
- Each element is added and removed at most once
Space Complexity: O(1) as we only use a constant amount of extra space
*/