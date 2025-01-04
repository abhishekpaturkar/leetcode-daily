// 1930. Unique Length-3 Palindromic Subsequences

// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".

// Example 1:

// Input: s = "aabca"
// Output: 3
// Explanation: The 3 palindromic subsequences of length 3 are:
// - "aba" (subsequence of "aabca")
// - "aaa" (subsequence of "aabca")
// - "aca" (subsequence of "aabca")
// Example 2:

// Input: s = "adc"
// Output: 0
// Explanation: There are no palindromic subsequences of length 3 in "adc".
// Example 3:

// Input: s = "bbcbaba"
// Output: 4
// Explanation: The 4 palindromic subsequences of length 3 are:
// - "bbb" (subsequence of "bbcbaba")
// - "bcb" (subsequence of "bbcbaba")
// - "bab" (subsequence of "bbcbaba")
// - "aba" (subsequence of "bbcbaba")

// Constraints:

// 3 <= s.length <= 105
// s consists of only lowercase English letters.

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        unordered_set<char> letters;
        for (char c : s)
        {
            letters.insert(c);
        }

        int ans = 0;
        for (char letter : letters)
        {
            int i = -1;
            int j = 0;

            for (int k = 0; k < s.size(); k++)
            {
                if (s[k] == letter)
                {
                    if (i == -1)
                    {
                        i = k;
                    }

                    j = k;
                }
            }

            unordered_set<char> between;
            for (int k = i + 1; k < j; k++)
            {
                between.insert(s[k]);
            }

            ans += between.size();
        }

        return ans;
    }
};

/*
Approach:
1. Create a set 'letters' to store unique characters from string s
2. For each unique letter in letters:
   - Find first (i) and last (j) occurrence of that letter in string s
   - Create a set 'between' to store unique characters between i and j
   - Add all characters between i and j to 'between' set
   - Add size of 'between' set to answer (represents number of unique palindromes possible with current letter)
3. Return final answer

Time Complexity: O(n * k) where n is length of string and k is number of unique characters
Space Complexity: O(k) where k is number of unique characters
*/