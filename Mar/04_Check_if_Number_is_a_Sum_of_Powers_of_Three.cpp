// 1780. Check if Number is a Sum of Powers of Three
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

// An integer y is a power of three if there exists an integer x such that y == 3x.

// Example 1:

// Input: n = 12
// Output: true
// Explanation: 12 = 31 + 32
// Example 2:

// Input: n = 91
// Output: true
// Explanation: 91 = 30 + 32 + 34
// Example 3:

// Input: n = 21
// Output: false

// Constraints:

// 1 <= n <= 107

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        while (n > 0)
        {
            if (n % 3 == 2)
            {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};


/*
This solution works by checking if a number can be represented as sum of powers of three.
The key insight is that when we convert a number to base-3 (ternary), each digit can only be 0 or 1
(not 2) for it to be a valid sum of distinct powers of three.

For example:
- If we get remainder 2 when dividing by 3, it means we need to use that power of 3 twice, which is not allowed
- We keep dividing by 3 and checking remainders until n becomes 0
- If we never encounter remainder 2, it means the number can be represented as sum of distinct powers of 3

Time Complexity: O(log n) - we divide n by 3 in each iteration
Space Complexity: O(1) - we only use constant extra space
*/

