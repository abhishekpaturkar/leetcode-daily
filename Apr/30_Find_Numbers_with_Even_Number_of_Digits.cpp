// 1295. Find Numbers with Even Number of Digits

// Given an array nums of integers, return how many of them contain an even number of digits.

 

// Example 1:

// Input: nums = [12,345,2,6,7896]
// Output: 2
// Explanation: 
// 12 contains 2 digits (even number of digits). 
// 345 contains 3 digits (odd number of digits). 
// 2 contains 1 digit (odd number of digits). 
// 6 contains 1 digit (odd number of digits). 
// 7896 contains 4 digits (even number of digits). 
// Therefore only 12 and 7896 contain an even number of digits.
// Example 2:

// Input: nums = [555,901,482,1771]
// Output: 1 
// Explanation: 
// Only 1771 contains an even number of digits.
 

// Constraints:

// 1 <= nums.length <= 500
// 1 <= nums[i] <= 105

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (int i : nums)
        {
            int digits = log10(i) + 1;
            if (digits % 2 == 0)
                ++count;
        }
        return count;
    }
};

/*
Time Complexity: O(n) where n is the length of input array nums
Space Complexity: O(1) as we only use constant extra space

The code counts numbers with even number of digits in the given array:
1. We iterate through each number in the input array
2. For each number, we calculate its number of digits using log10(i) + 1
   - log10(i) gives us (number of digits - 1), so we add 1 to get actual digit count
3. If the number of digits is even (divisible by 2), we increment our counter
4. Finally return the total count of numbers with even digits
*/