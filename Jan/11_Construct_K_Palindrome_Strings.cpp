// 1400. Construct K Palindrome Strings

// Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

 

// Example 1:

// Input: s = "annabelle", k = 2
// Output: true
// Explanation: You can construct two palindromes using all characters in s.
// Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
// Example 2:

// Input: s = "leetcode", k = 3
// Output: false
// Explanation: It is impossible to construct 3 palindromes using all the characters of s.
// Example 3:

// Input: s = "true", k = 4
// Output: true
// Explanation: The only possible solution is to put each character in a separate string.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.
// 1 <= k <= 105

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        int odd = 0;
        int n = s.length();

        vector<int> freq(26, 0);

        for (char c : s)
        {
            freq[c - 'a']++;
        }

        for (int i : freq)
        {
            if (i % 2 == 1)
            {
                odd++;
            }
        }

        return odd <= k && k <= n;
    }
};

// Approach:
// 1. Key Conditions:
//    a) Number of characters with odd frequency must be <= k
//    b) k must be <= length of string

// 2. Why these conditions?
//    - Each odd frequency character needs its own palindrome or must be in middle
//    - Can't make more palindromes than characters available

// 3. Examples showing it works:
//    Case 1: String with no odd frequency chars (e.g. "aabb")
//    - Can form 1 to n palindromes: "abba", "aa+bb", "a+a+bb", "a+a+b+b"
    
//    Case 2: String with odd frequency chars (e.g. "aabbc")
//    - Need at least as many palindromes as odd chars
//    - Can split: "aacbb", "aca+bb", "a+a+bcb", "a+a+c+bb"

// 4. Algorithm steps:
//    a) Count frequency of each character
//    b) Count how many characters have odd frequency
//    c) Check if odd_count <= k <= string_length

// Time Complexity: O(N) - single pass through string
// Space Complexity: O(1) - fixed size array for char counts