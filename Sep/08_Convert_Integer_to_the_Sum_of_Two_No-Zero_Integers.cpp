// 1317. Convert Integer to the Sum of Two No-Zero Integers

// No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

// Given an integer n, return a list of two integers [a, b] where:

// a and b are No-Zero integers.
// a + b = n
// The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

 

// Example 1:

// Input: n = 2
// Output: [1,1]
// Explanation: Let a = 1 and b = 1.
// Both a and b are no-zero integers, and a + b = 2 = n.
// Example 2:

// Input: n = 11
// Output: [2,9]
// Explanation: Let a = 2 and b = 9.
// Both a and b are no-zero integers, and a + b = 11 = n.
// Note that there are other valid answers as [8, 3] that can be accepted.
 

// Constraints:

// 2 <= n <= 104

class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        int a = 0, b = 0, tens = 1;
        for (; n > 0; n /= 10, tens *= 10)
        {
            int d = n % 10;
            if (d == 0)
            {
                // borrow from next higher digit: 5+5
                a += 5 * tens;
                b += 5 * tens;
                n -= 10; // subtract from the next digit
            }
            else if (d == 1 && n >= 10)
            {
                a += 6 * tens;
                b += 5 * tens;
                n -= 10; // borrow
            }
            else
            {
                // normal split
                a += (d - d / 2) * tens;
                b += (d / 2) * tens;
            }
        }
        return {a, b};
    }
};
