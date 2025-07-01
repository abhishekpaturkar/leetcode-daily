// 3330. Find the Original Typed String I

// Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

// Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.

// You are given a string word, which represents the final output displayed on Alice's screen.

// Return the total number of possible original strings that Alice might have intended to type.

 

// Example 1:

// Input: word = "abbcccc"

// Output: 5

// Explanation:

// The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".

// Example 2:

// Input: word = "abcd"

// Output: 1

// Explanation:

// The only possible string is "abcd".

// Example 3:

// Input: word = "aaaa"

// Output: 4

 

// Constraints:

// 1 <= word.length <= 100
// word consists only of lowercase English letters.

class Solution
{
public:
    int possibleStringCount(string word)
    {
        int n = word.length();
        int count = n;
        for (int i = 1; i < n; i++)
        {
            if (word[i] != word[i - 1])
            {
                count--;
            }
        }
        return count;
    }

};

/*
This code finds the number of possible original strings that could have been typed by Alice.
It works by:
1. Starting with count equal to string length
2. Decreasing count whenever adjacent characters are different
3. Final count represents possible original strings

Time Complexity: O(n) where n is length of input string
Space Complexity: O(1) as only constant extra space is used
*/