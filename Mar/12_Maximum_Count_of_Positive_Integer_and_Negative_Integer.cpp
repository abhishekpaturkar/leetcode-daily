// 2529. Maximum Count of Positive Integer and Negative Integer

// Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

// In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
// Note that 0 is neither positive nor negative.

// Example 1:

// Input: nums = [-2,-1,-1,1,2,3]
// Output: 3
// Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.
// Example 2:

// Input: nums = [-3,-2,-1,0,0,1,2]
// Output: 3
// Explanation: There are 2 positive integers and 3 negative integers. The maximum count among them is 3.
// Example 3:

// Input: nums = [5,20,66,1314]
// Output: 4
// Explanation: There are 4 positive integers and 0 negative integers. The maximum count among them is 4.

// Constraints:

// 1 <= nums.length <= 2000
// -2000 <= nums[i] <= 2000
// nums is sorted in a non-decreasing order.

// Follow up: Can you solve the problem in O(log(n)) time complexity?

class Solution
{
public:
    int binarySearch(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }

    int maximumCount(vector<int> &nums)
    {
        int neg = binarySearch(nums, 0);
        int pos = nums.size() - binarySearch(nums, 1);
        return max(neg, pos);
    }
};

/*
This code implements a solution to find the maximum count between positive and negative integers in a sorted array.
The binarySearch method uses binary search to find the leftmost position of a target value in the array.
For negative numbers, it finds the position of 0 (neg variable), giving us the count of negative numbers.
For positive numbers, it finds the position of 1 and subtracts it from array size (pos variable) to get count of positive numbers.
Finally, it returns the maximum of these two counts.
Time complexity is O(log n) due to binary search.
*/