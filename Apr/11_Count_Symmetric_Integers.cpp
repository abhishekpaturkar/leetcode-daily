// 2843. Count Symmetric Integers

// You are given two positive integers low and high.

// An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.

// Return the number of symmetric integers in the range [low, high].

 

// Example 1:

// Input: low = 1, high = 100
// Output: 9
// Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
// Example 2:

// Input: low = 1200, high = 1230
// Output: 4
// Explanation: There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.
 

// Constraints:

// 1 <= low <= high <= 10

class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int count = 0;
        for (int num = low; num <= high; num++)
        {
            if (isSymmetric(num))
            {
                count++;
            }
        }
        return count;
    }

private:
    bool isSymmetric(int num)
    {
        string s = to_string(num);
        int length = s.length();

        // Numbers with odd digits can't be symmetric
        if (length % 2 != 0)
        {
            return false;
        }

        int half = length / 2;
        int firstHalfSum = 0;
        int secondHalfSum = 0;

        // Calculate sum of first half digits
        for (int i = 0; i < half; i++)
        {
            firstHalfSum += s[i] - '0';
        }

        // Calculate sum of second half digits
        for (int i = half; i < length; i++)
        {
            secondHalfSum += s[i] - '0';
        }

        return firstHalfSum == secondHalfSum;
    }
};

/*
Time Complexity: O(N * D), where N is the range (high - low) and D is the average number of digits in the numbers
Space Complexity: O(D), where D is the number of digits in the largest number (for string conversion)

The code solves the problem of counting symmetric integers in a given range [low, high]. A symmetric integer is one where 
the sum of its first half digits equals the sum of its second half digits, and it must have an even number of digits.

The solution:
1. Iterates through each number in the range
2. For each number, converts it to string to easily access digits
3. Checks if the number has even digits (odd digit numbers can't be symmetric)
4. Splits the number into two halves and calculates sum of digits for each half
5. Compares the sums to determine if the number is symmetric
6. Keeps count of all symmetric numbers found
*/