// 2429. Minimize XOR

// Given two positive integers num1 and num2, find the positive integer x such that:

// x has the same number of set bits as num2, and
// The value x XOR num1 is minimal.
// Note that XOR is the bitwise XOR operation.

// Return the integer x. The test cases are generated such that x is uniquely determined.

// The number of set bits of an integer is the number of 1's in its binary representation.

 

// Example 1:

// Input: num1 = 3, num2 = 5
// Output: 3
// Explanation:
// The binary representations of num1 and num2 are 0011 and 0101, respectively.
// The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
// Example 2:

// Input: num1 = 1, num2 = 12
// Output: 3
// Explanation:
// The binary representations of num1 and num2 are 0001 and 1100, respectively.
// The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
 

// Constraints:

// 1 <= num1, num2 <= 109


class Solution
{
public:
    int countSetBits(int num)
    {
        int count = 0;
        while (num)
        {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    int addSetBits(int num, int bitsToAdd)
    {
        int bitPos = 0;
        while (bitsToAdd > 0)
        {
            while ((num >> bitPos) & 1)
                ++bitPos;
            num |= (1 << bitPos);
            --bitsToAdd;
        }
        return num;
    }

    int removeSetBits(int num, int bitsToRemove)
    {
        while (bitsToRemove > 0)
        {
            num &= (num - 1);
            --bitsToRemove;
        }
        return num;
    }

    int minimizeXor(int num1, int num2)
    {
        int setBitsNum1 = countSetBits(num1);
        int setBitsNum2 = countSetBits(num2);

        if (setBitsNum1 == setBitsNum2)
            return num1;
        if (setBitsNum1 < setBitsNum2)
            return addSetBits(num1, setBitsNum2 - setBitsNum1);
        return removeSetBits(num1, setBitsNum1 - setBitsNum2);
    }
};

// CountSetBits: Counts the number of set bits in a number.
// AddSetBits: Adds the required set bits by setting the least significant unset bits.
// RemoveSetBits: Removes extra set bits by unsetting the least significant set bits.
// It adjusts num1 based on whether it has fewer or more set bits compared to num2.

// Complexity
// Time complexity: O(32) (constant time for 32-bit integers).
// Space complexity: O(1).
