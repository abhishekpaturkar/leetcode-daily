// 1432. Max Difference You Can Get From Changing an Integer

// You are given an integer num. You will apply the following steps to num two separate times:

// Pick a digit x (0 <= x <= 9).
// Pick another digit y (0 <= y <= 9). Note y can be equal to x.
// Replace all the occurrences of x in the decimal representation of num by y.
// Let a and b be the two results from applying the operation to num independently.

// Return the max difference between a and b.

// Note that neither a nor b may have any leading zeros, and must not be 0.

 

// Example 1:

// Input: num = 555
// Output: 888
// Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
// The second time pick x = 5 and y = 1 and store the new integer in b.
// We have now a = 999 and b = 111 and max difference = 888
// Example 2:

// Input: num = 9
// Output: 8
// Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
// The second time pick x = 9 and y = 1 and store the new integer in b.
// We have now a = 9 and b = 1 and max difference = 8
 

// Constraints:

// 1 <= num <= 108

class Solution
{
public:
    int n;

    vector<int> toDigit(int num)
    {
        vector<int> ans(n);
        for (int x = num, i = n - 1; x > 0; x /= 10, i--)
        {
            ans[i] = x % 10;
            //        cout<<int(ans[i])<<",";
        }
        return ans;
    }

    int maxDiff(int num)
    {
        n = 1 + log10(num);
        vector<int> digit = toDigit(num);

        // Make max
        int a = -1;
        for (int i = 0; i < n && a == -1; i++)
        {
            if (digit[i] != 9)
                a = digit[i];
        }

        int x = 0;
        for (int i = 0; i < n; i++)
        {
            if (digit[i] == a)
                x = 10 * x + 9;
            else
                x = 10 * x + digit[i];
        }

        // Make min
        int b = -1, y = 0;
        if (digit[0] != 1)
        {
            b = digit[0];
            for (int i = 0; i < n; i++)
            {
                if (digit[i] == b)
                    y = 10 * y + 1;
                else
                    y = 10 * y + digit[i];
            }
        }
        else
        {
            for (int i = 1; i < n && b == -1; i++)
            {
                if (digit[i] != 0 && digit[i] != 1)
                {
                    b = digit[i];
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (i == 0)
                    y = 10 * y + digit[i]; // preserve the leading 1
                else if (digit[i] == b)
                    y = 10 * y + 0;
                else
                    y = 10 * y + digit[i];
            }
        }

        return x - y;
    }
};

/*
Code Explanation:
This solution finds the maximum difference possible by changing digits in a number according to given rules.

1. toDigit function:
   - Converts number into array of digits
   - Each digit stored in separate index

2. maxDiff function:
   - First calculates number of digits using log10
   - Converts number to digit array
   - Creates maximum number (x):
     * Finds first non-9 digit
     * Replaces all occurrences with 9
   - Creates minimum number (y):
     * If first digit isn't 1:
       - Replaces all occurrences with 1
     * If first digit is 1:
       - Finds first digit that's not 0 or 1
       - Replaces all occurrences with 0
   - Returns difference between max and min

Time Complexity: O(log n) where n is input number
Space Complexity: O(log n) for storing digits array

*/