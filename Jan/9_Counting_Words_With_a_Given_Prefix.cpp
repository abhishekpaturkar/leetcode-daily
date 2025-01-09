// 2185. Counting Words With a Given Prefix

// You are given an array of strings words and a string pref.

// Return the number of strings in words that contain pref as a prefix.

// A prefix of a string s is any leading contiguous substring of s.

// Example 1:

// Input: words = ["pay","attention","practice","attend"], pref = "at"
// Output: 2
// Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
// Example 2:

// Input: words = ["leetcode","win","loops","success"], pref = "code"
// Output: 0
// Explanation: There are no strings that contain "code" as a prefix.

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length, pref.length <= 100
// words[i] and pref consist of lowercase English letters.

class Solution
{
public:
    bool find(string s, string pref)
    {
        for (int i = 0; i < pref.length(); i++)
        {
            if (s[i] != pref[i])
            {
                return false;
            }
        }
        return true;
    }

    int prefixCount(vector<string> &words, string pref)
    {
        int ans = 0;

        for (auto &w : words)
        {
            if (find(w, pref))
                ans++;
        }

        return ans;
    }
};

/*
This code solves the problem of counting words with a given prefix. Here's how it works:

1. The find() function:
   - Takes two strings as input: the word to check (s) and the prefix to find (pref)
   - Compares each character of the word with the prefix
   - Returns false if any character doesn't match
   - Returns true if all characters in prefix match with the word's beginning

2. The prefixCount() function:
   - Takes a vector of strings (words) and a prefix string (pref)
   - Initializes a counter variable 'ans'
   - Iterates through each word in the vector
   - Uses find() function to check if the word contains the prefix
   - Increments counter if prefix is found
   - Returns the final count

The solution has a time complexity of O(N * M) where N is the number of words and M is the length of the prefix.
*/