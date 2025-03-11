// 1358. Number of Substrings Containing All Three Characters

// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".
// Example 3:

// Input: s = "abc"
// Output: 1

// Constraints:

// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters.

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int count = 0;
        int left = 0;
        unordered_map<char, int> char_count = {{'a', 0}, {'b', 0}, {'c', 0}};

        for (int right = 0; right < s.length(); right++)
        {
            char_count[s[right]]++;

            while (char_count['a'] > 0 && char_count['b'] > 0 && char_count['c'] > 0)
            {
                count += s.length() - right;
                char_count[s[left]]--;
                left++;
            }
        }

        return count;
    }
};

/*
This code finds the number of substrings containing all three characters 'a', 'b', and 'c' using a sliding window approach:
1. It maintains a window with left and right pointers and a hash map to count characters
2. The right pointer expands the window and adds characters to the count
3. When all three characters are found (count > 0 for each), it:
   - Adds the number of possible substrings (s.length - right) since all substrings starting at left and ending at or after right are valid
   - Shrinks the window from left side until one character is missing
4. The process continues until the right pointer reaches the end
5. Finally returns the total count of valid substrings
*/