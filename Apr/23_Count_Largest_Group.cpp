// 1399. Count Largest Group

// You are given an integer n.

// Each number from 1 to n is grouped according to the sum of its digits.

// Return the number of groups that have the largest size.

 

// Example 1:

// Input: n = 13
// Output: 4
// Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
// [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
// There are 4 groups with largest size.
// Example 2:

// Input: n = 2
// Output: 2
// Explanation: There are 2 groups [1], [2] of size 1.
 

// Constraints:

// 1 <= n <= 104

class Solution
{
public:
    int countLargestGroup(int n)
    {
        int res = 0, max_size = 0;
        unordered_map<int, int> m;
        for (int i = 1; i <= n; ++i)
        {
            int sum = 0, num = i;
            while (num)
            {
                sum += num % 10;
                num /= 10;
            }
            ++m[sum];
            if (m[sum] > max_size)
            {
                max_size = m[sum];
                res = 1;
            }
            else if (m[sum] == max_size)
                ++res;
        }
        return res;
    }
};

/*
This code counts the number of groups with the largest size when numbers from 1 to n are grouped by their digit sums.

Algorithm:
1. Initialize result and max_size variables to track count and size of largest groups
2. Use unordered_map to store digit sums as keys and their frequencies as values
3. For each number from 1 to n:
   - Calculate sum of its digits using modulo and division
   - Increment frequency of that digit sum in map
   - Update max_size and result counter when new largest group is found
4. Return final count of largest groups

Time Complexity: O(n * logn) - For each number we calculate digit sum
Space Complexity: O(k) where k is number of unique digit sums possible
*/