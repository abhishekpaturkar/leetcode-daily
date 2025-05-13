// 3335. Total Characters in String After Transformations I

// You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

// If the character is 'z', replace it with the string "ab".
// Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
// Return the length of the resulting string after exactly t transformations.

// Since the answer may be very large, return it modulo 109 + 7.

 
// Example 1:

// Input: s = "abcyy", t = 2

// Output: 7

// Explanation:

// First Transformation (t = 1):
// 'a' becomes 'b'
// 'b' becomes 'c'
// 'c' becomes 'd'
// 'y' becomes 'z'
// 'y' becomes 'z'
// String after the first transformation: "bcdzz"
// Second Transformation (t = 2):
// 'b' becomes 'c'
// 'c' becomes 'd'
// 'd' becomes 'e'
// 'z' becomes "ab"
// 'z' becomes "ab"
// String after the second transformation: "cdeabab"
// Final Length of the string: The string is "cdeabab", which has 7 characters.
// Example 2:

// Input: s = "azbk", t = 1

// Output: 5

// Explanation:

// First Transformation (t = 1):
// 'a' becomes 'b'
// 'z' becomes "ab"
// 'b' becomes 'c'
// 'k' becomes 'l'
// String after the first transformation: "babcl"
// Final Length of the string: The string is "babcl", which has 5 characters.
 

// Constraints:

// 1 <= s.length <= 105
// s consists only of lowercase English letters.
// 1 <= t <= 105

class Solution
{
public:
    const int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t)
    {
        vector<int> dp(t + 26);
        for (int i = 0; i < 26; i++)
            dp[i] = 1;
        for (int i = 26; i < t + 26; i++)
            dp[i] = (dp[i - 26] + dp[i - 25]) % mod;
        int ans = 0;
        for (char ch : s)
            ans = (ans + dp[ch - 'a' + t]) % mod;
        return ans;
    }
};

/*
This code calculates the length of a string after performing 't' transformations on each character.

The solution uses dynamic programming:
1. Creates a DP array of size t+26 to store lengths after each transformation
2. Initializes first 26 positions with 1 (base case for each letter)
3. For each position after 26, calculates sum of previous two transformations
4. Finally iterates through input string, adding lengths for each character after 't' transformations

For 'z', it becomes "ab" (2 characters), while other letters become next letter (1 character).
This pattern continues for each transformation.

Time Complexity: O(t + n) where t is transformations and n is string length
Space Complexity: O(t) for the DP array
*/