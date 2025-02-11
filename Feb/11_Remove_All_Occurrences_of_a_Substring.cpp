// 1910. Remove All Occurrences of a Substring

// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".
// Example 2:

// Input: s = "axxxxyyyyb", part = "xy"
// Output: "ab"
// Explanation: The following operations are done:
// - s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
// - s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
// - s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
// - s = "axyb", remove "xy" starting at index 1 so s = "ab".
// Now s has no occurrences of "xy".
 

// Constraints:

// 1 <= s.length <= 1000
// 1 <= part.length <= 1000
// s​​​​​​ and part consists of lowercase English letters.

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string resultStack;
        int targetLength = part.size();
        char targetEndChar = part.back();

        for (char currentChar : s)
        {
            resultStack.push_back(currentChar);

            if (currentChar == targetEndChar && resultStack.size() >= targetLength)
            {
                if (resultStack.substr(resultStack.size() - targetLength) == part)
                {
                    resultStack.erase(resultStack.size() - targetLength);
                }
            }
        }
        return resultStack;
    }
};

/*
This code removes all occurrences of a substring 'part' from string 's'. Here's how it works:

1. It uses a string 'resultStack' to build the result character by character
2. Stores the length of target substring and its last character for optimization
3. For each character in input string:
   - Adds it to resultStack
   - If current character matches last char of target and resultStack is long enough:
     - Checks if last few characters match the target substring
     - If match found, removes that substring from resultStack
4. Finally returns the processed string with all occurrences removed

The approach is efficient as it processes string left to right and removes matches immediately
*/