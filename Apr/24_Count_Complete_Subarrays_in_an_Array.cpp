// 2799. Count Complete Subarrays in an Array

// You are given an array nums consisting of positive integers.

// We call a subarray of an array complete if the following condition is satisfied:

// The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
// Return the number of complete subarrays.

// A subarray is a contiguous non-empty part of an array.

 

// Example 1:

// Input: nums = [1,3,1,2,2]
// Output: 4
// Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
// Example 2:

// Input: nums = [5,5,5,5]
// Output: 10
// Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 2000

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        unordered_set<int> s;
        for (auto &x : nums)
            s.insert(x);
        int n = s.size();
        int ans = 0;
        unordered_map<int, int> m;
        int i = 0, j = 0;
        while (j < nums.size())
        {
            m[nums[j]]++;
            while (m.size() == n)
            {
                ans += nums.size() - j;
                m[nums[i]]--;
                if (m[nums[i]] == 0)
                    m.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};

/*
Code Explanation:
This solution uses the sliding window technique to count complete subarrays. Here's how it works:

1. First, we use an unordered_set 's' to find the total number of distinct elements in the array.
2. Variable 'n' stores this count of distinct elements.
3. We use a sliding window with two pointers 'i' and 'j'.
4. unordered_map 'm' keeps track of frequency of elements in current window.
5. For each window:
   - Add elements from right (j)
   - When window has same distinct elements as full array:
     * Add count of all possible subarrays ending at j
     * Shrink window from left (i) until condition breaks
6. Return final count of complete subarrays

Time Complexity: O(N), where N is the length of input array
Space Complexity: O(K), where K is the number of distinct elements in array
*/