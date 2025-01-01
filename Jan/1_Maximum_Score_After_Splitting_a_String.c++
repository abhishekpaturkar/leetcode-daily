/*
1422. Maximum Score After Splitting a String
Easy

Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

Example 1:
Input: s = "011101"
Output: 5
Explanation:
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5
left = "01" and right = "1101", score = 1 + 3 = 4
left = "011" and right = "101", score = 1 + 2 = 3
left = "0111" and right = "01", score = 1 + 1 = 2
left = "01110" and right = "1", score = 2 + 1 = 3

Example 2:
Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5

Example 3:
Input: s = "1111"
Output: 3

Constraints:
- 2 <= s.length <= 500
- The string s consists of characters '0' and '1' only.
*/

class Solution
{
public:
    int maxScore(string s)
    {
        int one = 0;
        int zero = 0;

        int score = INT_MIN;

        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == '1')
            {
                one++;
            }
            else
            {
                zero++;
            }

            score = max(score, zero - one);
        }

        if (s[s.length() - 1] == '1')
        {
            one++;
        }

        return score + one;
    }
};

/*
This code finds the maximum score after splitting a string into two non-empty substrings:

1. Variables:
   - one: counts number of 1's in left substring
   - zero: counts number of 0's in left substring
   - score: tracks maximum difference between zeros and ones

2. Algorithm:
   - Iterate through string except last character
   - Count 1's and 0's in left part
   - Keep track of max difference (zero - one)
   - Add final 1 if present in last position
   - Return score + total ones

3. Logic:
   - (zero - one) represents: zeros in left - ones in left
   - Adding total ones at end gives: zeros in left + ones in right
   - This equals the required score formula

Time Complexity: O(n)
Space Complexity: O(1)
*/