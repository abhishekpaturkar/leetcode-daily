// 1695. Maximum Erasure Value

// You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

// Return the maximum score you can get by erasing exactly one subarray.

// An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

 

// Example 1:

// Input: nums = [4,2,4,5,6]
// Output: 17
// Explanation: The optimal subarray here is [2,4,5,6].
// Example 2:

// Input: nums = [5,2,1,2,5,2,1,2,5]
// Output: 8
// Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> seen;
        int left = 0;
        int currentSum = 0;
        int maxSum = 0;

        for (int right = 0; right < n; ++right)
        {
            while (seen.find(nums[right]) != seen.end())
            {
                currentSum -= nums[left];
                seen.erase(nums[left]);
                ++left;
            }
            currentSum += nums[right];
            seen.insert(nums[right]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

/*
This solution uses the sliding window technique with a hash set to find the maximum sum of a subarray with unique elements:

1. We maintain a sliding window with 'left' and 'right' pointers
2. For each element at 'right', we check if it's already in our set
3. If it is, we remove elements from the left until we no longer have duplicates
4. We keep track of the current sum and update the maximum sum found so far
5. The process continues until we've processed all elements

Time Complexity: O(n) where n is the length of the input array
Space Complexity: O(k) where k is the number of unique elements in the array
*/