// 1408. String Matching in an Array

// Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

// A substring is a contiguous sequence of characters within a string

 

// Example 1:

// Input: words = ["mass","as","hero","superhero"]
// Output: ["as","hero"]
// Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
// ["hero","as"] is also a valid answer.
// Example 2:

// Input: words = ["leetcode","et","code"]
// Output: ["et","code"]
// Explanation: "et", "code" are substring of "leetcode".
// Example 3:

// Input: words = ["blue","green","bu"]
// Output: []
// Explanation: No string of words is substring of another string.
 

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 30
// words[i] contains only lowercase English letters.
// All the strings of words are unique

class Solution
{
public:
    vector<int> computeLPS(const string &pat)
    {
        int n = pat.length();
        vector<int> lps(n, 0);
        int len = 0;

        for (int i = 1; i < n; ++i)
        {
            while (len > 0 && pat[i] != pat[len])
            {
                len = lps[len - 1];
            }
            if (pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
            }
        }
        return lps;
    }

    bool isPatternInText(const string &txt, const string &pat)
    {
        if (pat.empty())
            return true;
        if (txt.length() < pat.length())
            return false;

        vector<int> lps = computeLPS(pat);
        int i = 0;
        int j = 0;

        while (i < txt.length())
        {
            if (txt[i] == pat[j])
            {
                i++;
                j++;
                if (j == pat.length())
                {
                    return true;
                }
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return false;
    }

    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> res;
        sort(words.begin(), words.end(), [](const string &a, const string &b) -> bool
             { return a.length() < b.length(); });

        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                if (isPatternInText(words[j], words[i]))
                {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
}; 
/*
This code implements a solution to find all strings in an array that are substrings of other strings in the array. It uses the KMP (Knuth-Morris-Pratt) algorithm for efficient string matching.

The solution consists of three main functions:
1. computeLPS: Computes the Longest Proper Prefix which is also a Suffix array for KMP algorithm
2. isPatternInText: Implements KMP algorithm to check if a pattern exists in a text string
3. stringMatching: Main function that sorts words by length and checks each word against longer words

The algorithm first sorts the words by length to optimize the search process, then uses KMP pattern matching to find substrings. When a match is found, the substring is added to the result vector.
*/
