// 2014. Longest Subsequence Repeated k Times

// You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.

// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

// A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.

// For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
// Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.

 

// Example 1:

// example 1
// Input: s = "letsleetcode", k = 2
// Output: "let"
// Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
// "let" is the lexicographically largest one.
// Example 2:

// Input: s = "bb", k = 2
// Output: "b"
// Explanation: The longest subsequence repeated 2 times is "b".
// Example 3:

// Input: s = "ab", k = 2
// Output: ""
// Explanation: There is no subsequence repeated 2 times. Empty string is returned.
 

// Constraints:

// n == s.length
// 2 <= n, k <= 2000
// 2 <= n < k * 8
// s consists of lowercase English letters.

class Solution
{
public:
    string longestSubsequenceRepeatedK(string s, int k)
    {
        string result = "";
        queue<string> q;
        q.push("");
        while (!q.empty())
        {
            string curr = q.front();
            q.pop();
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                string next = curr + ch;
                if (isK(next, s, k))
                {
                    result = next;
                    q.push(next);
                }
            }
        }
        return result;
    }

    bool isK(string sub, string t, int k)
    {
        int count = 0, i = 0;
        for (char ch : t)
        {
            if (ch == sub[i])
            {
                if (++i == sub.size())
                {
                    i = 0;
                    if (++count == k)
                        return true;
                }
            }
        }
        return false;
    }
};

/*
Code Explanation:
This solution uses a BFS (Breadth-First Search) approach to find the longest subsequence that repeats k times in string s.

1. The main function longestSubsequenceRepeatedK:
   - Uses a queue to generate all possible subsequences starting from empty string
   - For each subsequence, tries to append each lowercase letter (a-z)
   - If new subsequence appears k times, updates result and adds to queue
   - Returns the lexicographically largest subsequence that appears k times

2. The helper function isK:
   - Checks if a subsequence appears k times in the main string
   - Uses two pointers technique to match characters
   - Counts complete matches until reaching k repetitions

Time Complexity: 
- O(26^L * N) where L is the length of the longest valid subsequence and N is the length of string s
- For each subsequence, we try 26 characters and check if it appears k times in string s

Space Complexity: 
- O(26^L) for storing subsequences in the queue
- Where L is the length of the longest valid subsequence
*/