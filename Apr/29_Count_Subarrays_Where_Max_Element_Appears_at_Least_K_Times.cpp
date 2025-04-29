// 2962. Count Subarrays Where Max Element Appears at Least K Times

// You are given an integer array nums and a positive integer k.

// Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

// A subarray is a contiguous sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,3,2,3,3], k = 2
// Output: 6
// Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
// Example 2:

// Input: nums = [1,4,2,1], k = 3
// Output: 0
// Explanation: No subarray contains the element 4 at least 3 times.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106
// 1 <= k <= 105

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k, int left = 0)
    {
        long maxi = *max_element(nums.begin(), nums.end()), maxiOccurence = 0, res = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == maxi)
            {
                ++maxiOccurence;
            }
            while (maxiOccurence >= k)
            {
                if (nums[left] == maxi)
                {
                    --maxiOccurence;
                }
                left++;
            }
            res += left;
        }
        return res;
    }

};

/*
This code finds the count of subarrays where the maximum element appears at least k times.

Algorithm:
1. Find the maximum element in the array using max_element
2. Use sliding window technique with two pointers - left and right
3. For each right pointer:
   - If current element is maximum, increment its count
   - While count of maximum element >= k:
     * If left pointer element is maximum, decrement its count
     * Increment left pointer
   - Add left pointer value to result
4. Return final result

Time Complexity: O(n) where n is length of array
Space Complexity: O(1) as we only use constant extra space
*/