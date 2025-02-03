// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
// Solved
// Easy
// Topics
// Companies
// You are given an array of integers nums. Return the length of the longest 
// subarray
//  of nums which is either 
// strictly increasing
//  or 
// strictly decreasing
// .

 
// Example 1:

// Input: nums = [1,4,3,3,2]

// Output: 2

// Explanation:

// The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].

// The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].

// Hence, we return 2.

// Example 2:

// Input: nums = [3,3,3,3]

// Output: 1

// Explanation:

// The strictly increasing subarrays of nums are [3], [3], [3], and [3].

// The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

// Hence, we return 1.

// Example 3:

// Input: nums = [3,2,1]

// Output: 3

// Explanation:

// The strictly increasing subarrays of nums are [3], [2], and [1].

// The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].

// Hence, we return 3.

 

// Constraints:

// 1 <= nums.length <= 50
// 1 <= nums[i] <= 50

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int maxLength = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            int len = 1;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j - 1] < nums[j])
                {
                    len++;
                    maxLength = max(maxLength, len);
                }
                else
                {
                    len = 0;
                }
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int len = 1;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j - 1] > nums[j])
                {
                    len++;
                    maxLength = max(maxLength, len);
                }
                else
                {
                    len = 0;
                }
            }
        }
        return maxLength;
    }
};

/*
This code finds the length of the longest strictly increasing or strictly decreasing subarray in a given array nums.
It uses two nested loops - first to find increasing subarrays and second to find decreasing subarrays.
For increasing subarrays, it checks if current element is greater than previous element.
For decreasing subarrays, it checks if current element is less than previous element.
It maintains a len variable to track current subarray length and maxLength to store the maximum length found so far.
When the condition breaks (not increasing/decreasing), len is reset to 0.
Finally returns the maximum length found between both increasing and decreasing subarrays.
*/