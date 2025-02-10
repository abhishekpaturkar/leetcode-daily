// 3174. Clear Digits
// Solved
// Easy
// Topics
// Companies
// Hint
// You are given a string s.

// Your task is to remove all digits by doing this operation repeatedly:

// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.

 
// Example 1:

// Input: s = "abc"

// Output: "abc"

// Explanation:

// There is no digit in the string.

// Example 2:

// Input: s = "cb34"

// Output: ""

// Explanation:

// First, we apply the operation on s[2], and s becomes "c4".

// Then we apply the operation on s[1], and s becomes "".

 

// Constraints:

// 1 <= s.length <= 100
// s consists only of lowercase English letters and digits.
// The input is generated such that it is possible to delete all digits.

class Solution
{
public:
    string clearDigits(string s)
    {
        string stack;
        for (char c : s)
        {
            if (isdigit(c))
            {
                if (!stack.empty())
                    stack.pop_back();
            }
            else
            {
                stack.push_back(c);
            }
        }
        return stack;
    }
};

/*
This code implements a solution to remove digits and their closest non-digit characters from a string:
1. It uses a string 'stack' to build the result
2. For each character in input string:
   - If it's a digit, remove last character from stack (if stack not empty)
   - If it's not a digit, add it to stack
3. The stack string contains final result after removing all digits and their adjacent characters
4. Time complexity is O(n) where n is string length
5. Space complexity is O(n) for storing result string
*/